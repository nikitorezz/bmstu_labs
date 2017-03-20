#ifndef __TBINARY_TREE_INCLUDED__
#define __TBINARY_TREE_INCLUDED__

#include <exception>
#include <iostream>

struct TExistElementException
	: public std::exception
{
	TExistElementException(char const* const message) throw()
		: std::exception(message)
	{
	}
};


struct TNotFoundException
	: public std::exception
{
	TNotFoundException(char const* const message) throw()
		: std::exception(message)
	{ }
};

class TBinaryTree
{
public:
	using value_type = int;

	struct TNode
	{
		value_type Data;
		TNode * Right;
		TNode * Left;

	private:
		TNode(const value_type& data, TNode * next = nullptr, TNode * prev = nullptr)
			: Data(data)
			, Right(next)
			, Left(prev)
		{ }
		TNode()
			: Data(value_type())
			, Right(nullptr)
			, Left(nullptr)
		{ }

		~TNode()
		{
			delete Left;
			delete Right;
		}

		friend class TBinaryTree;
	};

private:
	TNode * Root = nullptr;

	TNode * Cur_Search = nullptr;

	TNode * Cur_Parent = nullptr;

	static void Print(std::ostream & out, TBinaryTree::TNode * node)
	{
		if (node)
		{
			Print(out, node->Left);
			out << std::endl << node->Data;
			Print(out, node->Right);
		}
	}

public:
	TBinaryTree()
	{ }

	~TBinaryTree()
	{
		delete Cur_Parent;
		delete Cur_Search;
		delete Root;
	}

	int Insert(const value_type& data)
	{
		int res = TryInsert(data);
		if (!res) {
			throw TExistElementException("element already exist");
		}
		return res;
	}

	int TryInsert(const value_type& data)
	{
		int res;
		if (Root == nullptr)
		{
			Root = new TNode(data);
			return -10;
		}

		TNode * curNode = Root;
		TNode * prevNode = curNode;
		do
		{
			prevNode = curNode;
			if (curNode->Data == data) {
				Cur_Search = curNode;
				return 0;
			}
			if (curNode->Data < data)
				curNode = curNode->Right;
			else
				curNode = curNode->Left;
		} while (curNode);

		TNode * newNode = new TNode(data);
		Cur_Search = newNode;
		(prevNode->Data < data) ? res =  -1 : res = -2;
		(prevNode->Data < data) ? prevNode->Right = newNode : prevNode->Left = newNode;
		Cur_Parent = prevNode;
		return res;
	}

	// Требуется реализовать функцию поиска элемента
	// Если узел содержит искомый элемент, то функция возвращает указатель на этот узел
	// Если элемента в дереве не найдено, то функция генерирует исключение TNotFoundException
	TNode * Find(const value_type & value)
	{
		try {
			int res = Insert(value);
			if (res && res > -5) {
				res == -1 ? Cur_Parent->Right = nullptr : Cur_Parent->Left = nullptr;
			}
			delete Cur_Search;
		}
		catch (TExistElementException) {
			return Cur_Search;
		}

		throw TNotFoundException("not found \n");
		return nullptr;
	}

	friend std::ostream& operator << (std::ostream & out, const TBinaryTree& tree);
};

std::ostream& operator << (std::ostream & out, const TBinaryTree& tree)
{
	TBinaryTree::Print(out, tree.Root);
	return out;
}

#endif // __TBINARY_TREE_INCLUDED__
