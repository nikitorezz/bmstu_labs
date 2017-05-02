#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__
#include <memory>
#include <stdexcept>

template<typename T>
class TVector
{
public:
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }

	TVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	~TVector()
	{
		delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}

	void reserve(size_type size)
	{
		if (size < InternalCapacity) {
			return;
		}
		value_type * temp = new value_type[size];
		memcpy(temp, Ptr, Count * sizeof(value_type));
		InternalCapacity = size;
		delete[] Ptr;
		Ptr = temp;
	}

	TVector(const TVector& rhs)
	{
		this->reserve(rhs.InternalCapacity);
		memcpy(Ptr, rhs.Ptr, sizeof(value_type));
		Count = rhs.Count;
	}

	TVector& operator=(const TVector& rhs)
	{
		if (this == &rhs) {
			return *this;
		}
		Count = rhs.Count;
		this->reserve(rhs.InternalCapacity);
		memcpy(Ptr, rhs.Ptr, sizeof(value_type));
		return *this;
	}

	void MemAlloc(size_type size) {
		if (InternalCapacity == 0)
			this->reserve(1);
		while (size >= InternalCapacity)
			this->reserve(InternalCapacity * 2);
	}

	void push_back(const value_type& value)
	{
		MemAlloc(1 + Count);
		Ptr[Count] = value;
		Count++;
	}

	reference at(size_type index)
	{
		if (index < 0 || index >= Count) {
			throw std::out_of_range("out_of_range exception");
		}
		return Ptr[index];
	}

	value_type at(size_type index) const
	{
		if (index < 0 || index >= Count) {
			throw std::out_of_range("out_of_range exception");
		}
		return Ptr[index];
	}

	reference operator[](size_type index)
	{
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		return Ptr[index];
	}

	void Check() const {
		if (!Ptr) {
			throw std::out_of_range("nullptr exception");
		}
	}

	reference front()
	{
		Check();
		return Ptr[0];
	}

	const_reference front() const
	{
		Check();
		return Ptr[0];
	}

	reference back()
	{
		Check();
		return Ptr[Count - 1];
	}

	const_reference back() const
	{
		Check();
		return Ptr[Count - 1];
	}

	void clear()
	{
		InternalCapacity = 0;
		Count = 0;
		delete[] Ptr;
	}

	void pop_back()
	{
		Check();
		Count--;
	}

	void swap(TVector& other)
	{
		std::swap(other.Ptr, Ptr);
		std::swap(other.Count, Count);
		std::swap(other.InternalCapacity, InternalCapacity);
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (Count < count) {
			MemAlloc(count);
			for (int i = Count; i < count; i++) {
				Ptr[i] = value;
			}
		}
		Count = count;
	}

	iterator insert(iterator in_pos, const value_type& value)
	{
		size_t pos = in_pos - Ptr;
		if (pos < 0) {
			throw std::out_of_range("bad insert");
		}
		if (pos > Count - 1) {
			push_back(value);
			return in_pos;
		}
		reserve(++Count);
		for (int i = Count - 1 - pos; i >= 0; i--) {
			Ptr[i + pos + 1] = Ptr[i + pos];
		}
		Ptr[pos] = value;
		return in_pos;
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		if (*pos < 0) {
			throw std::out_of_range("bad insert");
		}
		if (*pos > Count - 1) {
			for (int i = 0; i < count; i++) {
				push_back(value);
			}
		}
		Count += count;
		reserve(++Count);

		for (int i = Count - 2 + count - *pos; i >= 0; i--) {
			Ptr[i + *pos + count] = Ptr[i + *pos];
		}
		for (int i = 0; i < count; i++) {
			Ptr[*pos + i] = value;
		}
	}

	iterator erase(iterator in_pos)
	{
		size_t pos = in_pos - Ptr;
		if (pos >= Count) {
			throw std::out_of_range("bad erase");
		}
		if (pos == Count - 1) {
			pop_back();
			return in_pos;
		}
		memcpy(Ptr + pos, Ptr + (pos + 1), (Count - 1 - pos) * sizeof(value_type));
		Count--;
		return in_pos;
	}

	iterator erase(iterator in_first, iterator in_last)
	{
		size_t first = in_first - Ptr;
		size_t last = in_last - Ptr;
		if (first >= Count) {
			throw std::out_of_range("bad erase");
		}
		if (last >= Count) {
			for (int i = 0; i < Count - first; i++) {
				pop_back();
			}
			return in_first;
		}
		memcpy(Ptr + first, Ptr + (last), (Count - last) * sizeof(value_type));
		Count -= (last - first);
		return in_first;
	}
};


#endif // __TVECTOR_INCLUDED__
