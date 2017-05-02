#pragma once
#include <iostream>
#include <vector>

template<
	class Key,
	class T,
	class Hash = std::hash<Key>,
	class KeyEqual = std::equal_to<Key>
> class u_map {

	using key_type = Key;
	using mapped_type = T;
	using value_type = std::pair<Key, T>;
	using size_type = size_t;
	//using difference_type = std::ptrdiff_t;
	using hasher = Hash;
	using key_equal = KeyEqual;
	//using allocator_type = Allocator;
	using refference = value_type&;
	using const_reference = const value_type&;
	//using pointer = std::allocator_traits<Allocator>::pointer;
	//using const_pointer = std::allocator_traits<Allocator>::const_pointer;
	using bucket_arr = std::vector<value_type>;
	using map_arr = std::vector<bucket_arr>;


	class TIterator : public std::iterator<std::forward_iterator_tag, value_type> {

		value_type * Ptr = nullptr;
		size_type Index;
		size_type inner_Index;
		map_arr Array;

		TIterator(value_type* ptr, size_type& ind, size_type& inner, map_arr& arr = nullptr)
			: Ptr(ptr)
			, Index(ind)
			, inner_Index(inner)
			, Array(arr) {
		}

		friend class u_map;

	public:

		TIterator() = default;

		TIterator& operator=(const TIterator&) = default;

		value_type& operator*() const {
			return *Ptr;
		}

		value_type* operator->() const {
			return Ptr;
		}

		bool operator == (const TIterator& rhs) {
			return (Ptr->first == rhs.Ptr->first);
		}

		bool operator != (const TIterator& rhs) {
			return !(*this == rhs);
		}

		TIterator& operator++() {
			if (inner_Index != Array[Index].size() - 1) {
				++Ptr;
				++inner_Index;
				return *this;
			}
			size_type temp = Index + 1;
			while (temp < Array.size() && Array[temp].empty()) {
				++temp;
			}
			if (temp < Array.size()) {
				Index = temp;
				Ptr = &Array[Index][0];
				inner_Index = 0;
			}
			else {
				++Ptr;
				++Index;
				inner_Index = 0;
				return *this;
			}
			return *this;
		}

		TIterator& operator--() {
			if (inner_Index == 0) {
				size_type temp = Index - 1;
				while (temp >= 0 && Array[temp].empty()) {
					--temp;
				}

				Index = temp;
				inner_Index = Array[Index].size() - 1;
				Ptr = &Array[Index].back();
				return *this;
			}
			--Ptr;
			--inner_Index;
			return *this;
		}

		size_type GetIndex() {
			return Index;
		}

		size_type GetInnerIndex() {
			return inner_Index;
		}
	};



	using iterator = TIterator;
	using const_iterator = const TIterator;
	using local_iterator = TIterator;
	using const_local_iterator = const TIterator;

	hasher Hash;
	key_equal Eq;
	size_t Size;
	map_arr m_Arr;

public:

	u_map(size_t size = 16, hasher& hash = hasher(), key_equal& eq = key_equal())
		:Size(size)
		, Eq(eq)
		, Hash(hash) {
		bucket_arr b;
		for (size_t i = 0; i < size; i++) {
			m_Arr.push_back(b);
		}
	}
	u_map(u_map& rhs)
		:Size(rhs.Size)
		, Eq(rhs.Eq)
		, Hash(rhs.Hash)
		, m_Arr(rhs.m_Arr){
	}

	u_map(std::initializer_list<value_type> il, size_t size = 16, hasher& hash = hasher(), key_equal& eq = key_equal()) {
		if (!this->empty()) {
			this->clear;
		}
		for (auto & it : il) {
			this->insert(it);
		}
	}

	iterator begin() {
		size_type tmp = 0;
		while (m_Arr[tmp].empty()) {
			++tmp;
		}
		size_t in = 0;
		iterator res(&m_Arr[tmp][0], tmp, in, m_Arr);
		return res;
	}

	const_iterator begin() const {
		size_type tmp = 0;
		while (m_Arr[tmp].empty()) {
			++tmp;
		}
		size_t in = 0;
		iterator res(&m_Arr[tmp][0], tmp, in, m_Arr);
		return res;
	}

	iterator end() {
		if (m_Arr.empty()) {
			return this->begin();
		}
		for (size_t i = 15; i >= 0; i--) {
			if (!m_Arr[i].empty()) {
				size_t in = m_Arr[i].size() - 1;
				iterator it(&m_Arr[i].back(), i, in, m_Arr);
				++it;
				return it;
			}
		}
	}

	const_iterator end() const {
		if (m_Arr.empty()) {
			return this->begin();
		}
		for (size_t i = 15; i >= 0; i--) {
			if (!m_Arr[i].empty()) {
				size_t in = m_Arr[i].size() - 1;
				iterator it(&m_Arr[i].back(), i, in, m_Arr);
				++it;
				return it;
			}
		}
	}

	bool empty() const {
		for (auto i = m_Arr.begin(); i != m_Arr.end(); ++i) {
			if (!i->empty()) {
				return false;
			}
		}
		return true;
	}

	size_type size() const {
		return Size;
	}
	
	size_type max_size() const {
	return Size;
	}
	//////////////////////////////////////////////// пытался сделать поумнее, не получилось
	size_type GetIndex(const key_type& Key) const {
	return Hash(Key) % 16;
	}
	////////////////////////////////////////
	std::pair<iterator, bool> insert(const value_type& val) {
		size_type index = GetIndex(val.first);
		for (size_t i = 0; i < m_Arr[index].size(); i++) {
			if (Eq(val.first, m_Arr[index][i].first)) {
				return std::pair<iterator, bool>(TIterator(&m_Arr[index][i], index, i, m_Arr), false);
			}
		}
	
		m_Arr[index].push_back(val);
		size_t in = m_Arr[index].size() - 1;
		return std::pair<iterator, bool>(TIterator(&m_Arr[index][m_Arr[index].size() - 1], index, in, m_Arr), true);
	}

	void insert(iterator& first, iterator& last) {
		for (auto i = first; i != last; ++i) {
			this->insert(*i);
		}
	}

	size_type erase(const key_type& key) {
		iterator iter = find(key);
		if (iter.Ptr != end().Ptr) {
			size_t index = iter.GetIndex();
			size_t ind = iter.GetInnerIndex();
			auto pos = m_Arr[index].begin() + ind;
			m_Arr[index].erase(pos);
			return 1;
		}
		return 0;
	}

	iterator erase(iterator& first, iterator& last) {
		for (auto i = first; i != last; ++i) {
			this->erase((*i).first);
		}
		return last;
	}

	void clear() {
		for (size_t i = 0; i < Size; ++i) {
			if (!m_Arr[i].empty()) {
				m_Arr[i].clear;
			}
		}
	}

	void swap(u_map& rhs) {
		std::swap(Hash, rhs.Hasher);
		std::swap(Eq, rhs.Eq);
		std::swap(Size, rhs.Size);
		std::swap(m_Arr, rhs.m_Arr);
	}
	
	mapped_type& at(const key_type& key) {
		if (find(key) == end()) {
			throw std::out_of_range("Wrong index");
		}
		size_type index = GetIndex(key);
		for (size_t i = 0; i < m_Arr[index].size(); i++) {
			if (Eq(key, m_Arr[index][i].first)) {
				return m_Arr[index][i].second;
			}
		}
	}

	const mapped_type& at(const key_type& key) const {
		if (find(key).Ptr == end().Ptr) {
			throw std::out_of_range("Wrong index");
		}
		size_type index = GetIndex(key);
		for (size_t i = 0; i < m_Arr[index].size(); i++) {
			if (Eq(key, m_Arr[index][i].first)) {
				return m_Arr[index][i].second;
			}
		}
	}


	iterator find(const key_type& key) {
		size_type index = GetIndex(key);
		for (size_t i = 0; i < m_Arr[index].size(); i++) {
			if (Eq(key, m_Arr[index][i].first)) {
				return TIterator(&m_Arr[index][i], index, i, m_Arr);
			}
		}
		return end();
	}

	////////////////
	size_type count(const key_type& key) const {
		size_type index = GetIndex(key);
		for (size_type i = 0; i < m_Arr[index].size(); ++i)
			if (Eq(key, m_Arr[index][i].first)) {
				return 1;
			}
		return 0;
	}

	size_type bucket_count() const {
		size_type size = 0;
		for (auto i = m_Arr.begin(); i != m_Arr.end(); ++i) {
			if (!i->empty()) {
				++size;
			}
		}
		return size;
	}
	
	size_type max_bucket_count() const {
		return Size;
	}

	size_type bucket(const key_equal& key) const {
		return GetIndex(key);
	}

	size_type bucket_size(size_type ind) const {
		return m_Arr[ind].size();
	}

	mapped_type& operator[](const key_type& key){
		size_type index = GetIndex(key);
		for (size_type i = 0; i < m_Arr[index].size(); ++i){
			if (Eq(key, m_Arr[index][i].first)) {
				return m_Arr[index][i].second;
			}
		}
		mapped_type val;
		m_Arr[index].push_back({key, val});
		return m_Arr[index][m_Arr[index].size() - 1].second;
	}

	u_map& operator=(const u_map& rhs){
		Hash = rhs.Hash;
		Eq = rhs.Eq;
		m_Arr = rhs.m_Arr;
		Size = rhs.Size;
		return *this;
	}
	
};


template<
	class Key,
	class T,
	class Hash = std::hash<Key>,
	class KeyEqual = std::equal_to<Key>
> bool operator==(u_map<Key, T>& a, u_map<Key, T>& b) {
	if (a.size() != b.size()) {
		return false;
	}

	for (auto i = a.begin(); i != a.end(); ++i) {
		if (a.count(i->first) != b.count(i->first)) {
			return false;
		}
		if (i->second != b.at(i->second)) {
			return false;
		}
	}
	return true;
}

template<
	class Key,
	class T,
	class Hash = std::hash<Key>,
	class KeyEqual = std::equal_to<Key>
> bool operator!=(u_map<Key, T>& a, u_map<Key, T>& b) {
	return !(a == b);
}

