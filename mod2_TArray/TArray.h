#pragma once
#include <string>
#include <array>

template<class T,size_t N> struct TArray {
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;
	
	value_type * Ptr;

	TArray() = default;

	~TArray() = default;

	TArray(std::initializer_list<T> init) : TArray(){
		size_type i = 0;
		for (auto & j : init) {
			Ptr[i] = j;
			++i;
		}
	}

	iterator begin() {
		return Ptr;
	}

	const iterator begin() {
		return Ptr;
	}

	const iterator cbegin() {
		return begin();
	}

	iterator end() {
		return Ptr + N;
	}

	const iterator end() {
		return Ptr + N;
	}

	const iterator cend() {
		return end();
	}

	iterator rbegin() {
		return end();
	}

	const iterator rbegin() {
		return end();
	}

	const iterator crbegin() {
		return rbegin();
	}

	iterator rend() {
		return begin();
	}

	const iterator rend() {
		return begin();
	}

	const iterator crend() {
		return rend();
	}

	constexpr size_type size() {	
		return N;
	}

	constexpr size_type max_size() {	
		return N;
	}

	constexpr bool empty() {	
		return N==0;
	}

	reference at(size_type pos) {
		if (N <= pos) {
			throw std::out_of_range();
		}
		return Ptr[N];
	}

	const_reference at(size_type pos) const {
		if (N <= pos) {
			throw std::out_of_range();
		}
		return Ptr[N];
	}

	reference operator[](size_t pos) {
		return Ptr[N];
	}

	const_reference operator[](size_t pos) const{
		return Ptr[N];
	}

	reference front() {
		return Ptr[0];
	}

	const_reference front(size_t pos) const{
		return Ptr[0];
	}

	reference back() {
		return Ptr[N-1];
	}

	const_reference back(size_t pos) const {
		return Ptr[N - 1];
	}

	iterator data() {
		return Ptr;
	}

	const iterator data() const {
		return Ptr;
	}

	void fill(const value_type& val) {
		for (size_t i = 0; i < N; i++) {
			Ptr[i] = val;
		}
	}

	void swap(TArray<T,N> & rhs) {
		std::swap(Ptr,rhs.Ptr)
	}
};
