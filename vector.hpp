#ifndef vector_hpp
#define vector_hpp

#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>

namespace ft {
template < class T, class Alloc = std::allocator<T> >
class vector {
private:
	T*				_data;
	size_t			_capacity;
	size_t			_size;
	Alloc			_dataAlloc;
public:
	//MARK: - Member types
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	
	//MARK: - Constructors
	explicit vector (const allocator_type& alloc = allocator_type()) : _data(0), _capacity(0), _size(0), _dataAlloc(alloc) {};
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _dataAlloc(alloc) {
		_data = createArr(n);
		_size = n;
		_capacity = n;
		fillArr(val, 0, n, _data);
	};
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _data(0), _capacity(0), _size(0), _dataAlloc(alloc) {
		_data = createArr(last - first);
		_size = last - first;
		_capacity = last - first;
		copyArr(first, last, _data);
	};
	vector (const vector& x) {
		_capacity = x._size;
		_size = x._size;
		_data = createArr(_capacity);
		const_iterator it = x.cbegin();
		const_iterator ite = x.cend();
		constCopyArr(it, ite, _data);
	};
	
	//MARK: - Destructor
	~vector() {
		clear();
		_dataAlloc.deallocate(_data, _capacity);
		_capacity = 0;
	};
	
	//MARK: - Assign
	vector& operator=(const vector& x) {
		if (this == &x)
			return (*this);
		const_iterator it = x.cbegin();
		const_iterator ite = x.cend();
		T* tmp = createArr(x._capacity);
		constCopyArr(it, ite, tmp);
		clear();
		_dataAlloc.deallocate(_data, _capacity);
		_capacity = x._size;
		_size = x._size;
		_data = tmp;
		return (*this);
	};
	
	//MARK: - Iterators
	class iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
	public:
		T*		data;
		iterator() : data(0) {};
		iterator(T* src) : data(src) {}
		iterator(const iterator& src) {
			data = src.data;
		}
		iterator& operator=(const iterator& src) {
			if (*this == src)
				return (*this);
			this->data = src.data;
			return (*this);
		}
		virtual ~iterator() {};
		virtual iterator& operator++() {
			data++;
			return *this;
		}
		virtual iterator operator++(int){
			iterator tmp = *this;
			operator++();
			return tmp;
		}
		virtual iterator& operator--() {
			data--;
			return *this;
		}
		virtual iterator operator--(int) {
			iterator tmp = *this;
			operator--();
			return tmp;
		}
		virtual bool operator==(const iterator& rhs) const {
			return data == rhs.data;
		}
		virtual bool operator!=(const iterator& rhs) const {
			return data != rhs.data;
		}
		virtual value_type& operator*() {
			return *data;
		}
		virtual value_type operator->() {
			return *data;
		}
		virtual iterator operator+(int num) {
			data += num;
			return *this;
		}
		virtual iterator operator-(int num) {
			data -= num;
			return *this;
		}
		virtual value_type& operator[](const size_t num) {
			return (*(data + num));
		}
		virtual bool operator<(const iterator x) {
			return (data < x.data);
		}
		virtual bool operator>(const iterator x) {
			return (data > x.data);
		}
		virtual bool operator<=(const iterator x) {
			return (data <= x.data);
		}
		virtual bool operator>=(const iterator x) {
			return (data >= x.data);
		}
		virtual iterator& operator+=(const size_t num) {
			data += num;
			return *this;
		}
		virtual iterator& operator-=(const size_t num) {
			data -= num;
			return *this;
		}
	};
	class const_iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
	public:
		T*		data;
		const_iterator() : data(0){};
		const_iterator(T* src) : data(src) {}
		const_iterator(const const_iterator& src) {
			*this = src;
		}
		const_iterator& operator=(const const_iterator& src) {
			if (*this == src)
				return (*this);
			this->data = src.data;
			return (*this);
		}
		virtual ~const_iterator() {};
		virtual const_iterator& operator++() {
			data++;
			return *this;
		}
		virtual const_iterator operator++(int){
			const_iterator tmp = *this;
			operator++();
			return tmp;
		}
		virtual const_iterator& operator--() {
			data--;
			return *this;
		}
		virtual const_iterator operator--(int) {
			const_iterator tmp = *this;
			operator--();
			return tmp;
		}
		virtual bool operator==(const const_iterator& rhs) const {
			return data == rhs.data;
		}
		virtual bool operator!=(const const_iterator& rhs) const {
			return data != rhs.data;
		}
		virtual const value_type& operator*() {
			return *data;
		}
		virtual const value_type operator->() {
			return *data;
		}
		virtual const_iterator operator+(int num) {
			data += num;
			return *this;
		}
		virtual const_iterator operator-(int num) {
			data -= num;
			return *this;
		}
		virtual value_type& operator[](const size_t num) {
			return (*(data + num));
		}
		virtual bool operator<(const const_iterator x) {
			return (data < x.data);
		}
		virtual bool operator>(const const_iterator x) {
			return (data > x.data);
		}
		virtual bool operator<=(const const_iterator x) {
			return (data <= x.data);
		}
		virtual bool operator>=(const const_iterator x) {
			return (data >= x.data);
		}
		virtual const_iterator& operator+=(const size_t num) {
			data += num;
			return *this;
		}
		virtual const_iterator& operator-=(const size_t num) {
			data -= num;
			return *this;
		}
	};
	class reverse_iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
		public:
		T*		data;
		reverse_iterator() : data(0) {};
		reverse_iterator(T* src) : data(src) {}
		reverse_iterator(const reverse_iterator& src) {
			data = src.data;
		}
		reverse_iterator& operator=(const reverse_iterator& src) {
			if (*this == src)
				return (*this);
			this->data = src.data;
			return (*this);
		}
		virtual ~reverse_iterator() {};
		virtual reverse_iterator& operator++() {
			data--;
			return *this;
		}
		virtual reverse_iterator operator++(int){
			reverse_iterator tmp = *this;
			operator++();
			return tmp;
		}
		virtual reverse_iterator& operator--() {
			data++;
			return *this;
		}
		virtual reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			operator--();
			return tmp;
		}
		virtual bool operator==(const reverse_iterator& rhs) const {
			return data == rhs.data;
		}
		virtual bool operator!=(const reverse_iterator& rhs) const {
			return data != rhs.data;
		}
		virtual value_type& operator*() {
			return *data;
		}
		virtual value_type operator->() {
			return *data;
		}
		virtual reverse_iterator operator+(int num) {
			data -= num;
			return *this;
		}
		virtual reverse_iterator operator-(int num) {
			data += num;
			return *this;
		}
		virtual value_type& operator[](const size_t num) {
			return (*(data + num));
		}
		virtual bool operator<(const reverse_iterator x) {
			return (data < x.data);
		}
		virtual bool operator>(const reverse_iterator x) {
			return (data > x.data);
		}
		virtual bool operator<=(const reverse_iterator x) {
			return (data <= x.data);
		}
		virtual bool operator>=(const reverse_iterator x) {
			return (data >= x.data);
		}
		virtual reverse_iterator& operator+=(const size_t num) {
			data -= num;
			return *this;
		}
		virtual reverse_iterator& operator-=(const size_t num) {
			data += num;
			return *this;
		}
	};
	class const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
		public:
		T*		data;
		const_reverse_iterator() : data(0) {};
		const_reverse_iterator(T* src) : data(src) {}
		const_reverse_iterator(const const_reverse_iterator& src) {
			*this = src;
		}
		const_reverse_iterator& operator=(const const_reverse_iterator& src) {
			if (*this == src)
				return (*this);
			this->data = src.data;
			return (*this);
		}
		virtual ~const_reverse_iterator() {};
		virtual const_reverse_iterator& operator++() {
			data--;
			return *this;
		}
		virtual const_reverse_iterator operator++(int){
			const_reverse_iterator tmp = *this;
			operator++();
			return tmp;
		}
		virtual const_reverse_iterator& operator--() {
			data++;
			return *this;
		}
		virtual const_reverse_iterator operator--(int) {
			const_reverse_iterator tmp = *this;
			operator--();
			return tmp;
		}
		virtual bool operator==(const const_reverse_iterator& rhs) const {
			return data == rhs.data;
		}
		virtual bool operator!=(const const_reverse_iterator& rhs) const {
			return data != rhs.data;
		}
		virtual value_type& operator*() {
			return *data;
		}
		virtual value_type operator->() {
			return *data;
		}
		virtual const_reverse_iterator operator+(int num) {
			data -= num;
			return *this;
		}
		virtual const_reverse_iterator operator-(int num) {
			data += num;
			return *this;
		}
		virtual value_type& operator[](const size_t num) {
			return (*(data + num));
		}
		virtual bool operator<(const const_reverse_iterator x) {
			return (data < x.data);
		}
		virtual bool operator>(const const_reverse_iterator x) {
			return (data > x.data);
		}
		virtual bool operator<=(const const_reverse_iterator x) {
			return (data <= x.data);
		}
		virtual bool operator>=(const const_reverse_iterator x) {
			return (data >= x.data);
		}
		virtual const_reverse_iterator& operator+=(const size_t num) {
			data -= num;
			return *this;
		}
		virtual const_reverse_iterator& operator-=(const size_t num) {
			data += num;
			return *this;
		}
	};
	iterator begin() {
		return iterator(_data);
	};
	iterator end() {
		iterator res = iterator(_data) + static_cast<int>(_size);
		return res;
	};
	reverse_iterator rbegin() {
		reverse_iterator res = reverse_iterator(_data + _size - 1);
		return res;
	};
	reverse_iterator rend() {
		reverse_iterator res = reverse_iterator(_data - 1);
		return res;
	};
	const_iterator cbegin() const {
		return const_iterator(_data);
	};
	const_iterator cend() const {
		const_iterator res = const_iterator(_data + _size);
		return res;
	};
	const_reverse_iterator crbegin() const {
		const_reverse_iterator res = const_reverse_iterator(_data + _size - 1);
		return res;
	};
	const_reverse_iterator crend() const {
		const_reverse_iterator res = const_reverse_iterator(_data - 1);
		return res;
	};
	
	//MARK: - Capacity
	size_type size() const {
		return _size;
	};
	size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof(value_type);
	};
	void resize (size_type n, value_type val = value_type()) {
		size_type temp = _capacity;
		if (n > _capacity) {
			if (_capacity == 0)
				_capacity = 1;
			while (_capacity < n)
				_capacity = _capacity * 2;
		}
		T* tmp = createArr(_capacity);
		iterator it = begin();
		iterator ite = end();
		if (n > _size) {
			copyArr(it, ite, tmp);
			fillArr(val, _size, n, tmp);
		}
		else if (n < _size)
			copyArr(it, ite, tmp);
		clear();
		_dataAlloc.deallocate(_data, temp);
		_data = tmp;
		_size = n;
	};
	size_type capacity() const {
		return _capacity;
	};
	bool empty() const {
		return (_size == 0);
	};
	void reserve (size_type n) {
		if (n > _capacity) {
			size_type temp = _size;
			T* tmp = createArr(n);
			iterator it = begin();
			iterator ite = end();
			copyArr(it, ite, tmp);
			clear();
			_dataAlloc.deallocate(_data, _capacity);
			_data = tmp;
			_capacity = n;
			_size = temp;
		}
	};
	
	//MARK: - Element access
	reference operator[] (size_type n) {
		return reference(_data[n]);
	};
	const_reference operator[] (size_type n) const {
		return const_reference(_data[n]);
	};
	reference at (size_type n) {
		if (n >= _size)
			throw std::out_of_range("index out of range");
		return reference(_data[n]);
	};
	const_reference at (size_type n) const {
		if (n >= _size)
			throw std::out_of_range("index out of range");
		return const_reference(_data[n]);
	};
	reference front() {
		return reference(_data[0]);
	};
	const_reference front() const {
		return const_reference(_data[0]);
	};
	reference back() {
		return reference(_data[_size - 1]);
	};
	const_reference back() const {
		return const_reference(_data[_size - 1]);
	};
	
	//MARK: - Modifiers
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		clear();
		iterator ite = end();
		long i = 0;
		for (InputIterator tmp = first; tmp != last; tmp++)
			i++;
		_data = realloc(&_capacity, _size + i);
		move(begin(), end(), i);
		for (int i = 0; first != last; i++) {
			_data[i] = *first;
			_size++;
			first++;
		}
	};
	void assign (size_type n, const value_type& val) {
		clear();
		_data = createArr(n);
		_size = n;
		_capacity = n;
		fillArr(val, 0, n, _data);
	};
	void push_back (const value_type& val) {
		_data = realloc(&_capacity, _size + 1);
		_data[_size] = val;
		_size++;
	};
	void pop_back() {
		_size--;
		_dataAlloc.destroy(&_data[_size]);
	};
	iterator insert (iterator position, const value_type& val) {
		iterator ite = end();
		long tmp = position.data - _data;
		_data = realloc(&_capacity, _size + 1);
		move(position, end(), 1);
		_data[tmp] = val;
		_size++;
		iterator res(_data + tmp);
		return res;
	};
	void insert (iterator position, size_type n, const value_type& val) {
		iterator ite = end();
		long tmp = position.data - _data;
		_data = realloc(&_capacity, _size + n);
		move(position, end(), static_cast<int>(n));
		for (size_t i = 0; i < n; i++) {
			_data[tmp] = val;
			_size++;
			tmp++;
		}
	};
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		long i = 0;
		for (InputIterator tmp = first; tmp != last; tmp++)
			i++;
		_data = realloc(&_capacity, _size + i);
		iterator ite = end();
		iterator res(_data + (position.data - _data));
		move(position, end(), i);
		for (; first != last; first++) {
			*res = *first;
			res++;
			_size++;
		}
	};
	iterator erase (iterator position) {
		moveBack(position, end(), 1);
		_size--;
		return position;
	};
	iterator erase (iterator first, iterator last) {
		moveBack(first, end(), static_cast<int>(last.data - first.data));
		_size -= last.data - first.data;
		return first;
	};
	void swap (vector& x) {
		value_type* tmpData = _data;
		size_type tmpSize = _size;
		size_type tmpCapacity = _capacity;
		_data = x._data;
		_size = x._size;
		_capacity = x._capacity;
		x._data = tmpData;
		x._size = tmpSize;
		x._capacity = tmpCapacity;
	};
	void clear() {
		while (_size != 0)
			pop_back();
	};
	
	//MARK: - Utility
private:
	T* createArr(size_type n) {
		T* cont = _dataAlloc.allocate(n);
		T* tmp = cont;
		for (size_t i = 0; i < n; i++)
			_dataAlloc.construct(tmp++, T());
		return cont;
	}
	void fillArr(const value_type& val, size_type start, size_type finish, T* data) {
		for (; start < finish; start++) {
			data[start] = val;
		}
	}
	template <class InputIterator>
	size_t copyArr(InputIterator first, InputIterator last, T* data, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		size_t arrSize = 0;
		for (; first != last; first++) {
			data[arrSize] = *first;
			arrSize++;
		}
		return arrSize;
	}
	void constCopyArr(const_iterator first, const_iterator last, T* data) {
		for (size_t i = 0; first != last; first++) {
			data[i] = *first;
			i++;
		}
	}
	T* realloc(size_type *capacity, size_type n) {
		size_type temp = _capacity;
		if (n > *capacity) {
			if (*capacity == 0)
				*capacity = 1;
			while (*capacity < n)
				*capacity = *capacity * 2;
			T* tmp = createArr(*capacity);
			size_type elems = copyArr(begin(), end(), tmp);
			clear();
			_dataAlloc.deallocate(_data, temp);
			_data = tmp;
			_size = elems;
		}
		return _data;
	}
	void move(iterator pos, iterator end, long n) {
		iterator cur = end;
		cur += static_cast<int>(n);
		while (end != pos) {
			*cur = *end;
			end--;
			cur--;
		}
		*cur = *end;
	}
	void moveBack(iterator pos, iterator end, long n) {
		iterator cur = pos;
		cur += static_cast<int>(n);
		while (cur != end) {
			*pos = *cur;
			pos++;
			cur++;
		}
		*pos = *cur;
	}
};

//MARK: - Non-member function overloads
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T>::const_iterator lit = lhs.cbegin();
	typename ft::vector<T>::const_iterator lite = lhs.cend();
	typename ft::vector<T>::const_iterator rit = rhs.cbegin();
	typename ft::vector<T>::const_iterator rite = rhs.cend();
	while (lit != lite) {
		if (*lit != *rit)
			return false ;
		lit++;
		rit++;
	}
	if (lhs.size() == rhs.size())
		return true ;
	return false;
};
template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs == rhs);
};
template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	size_t size;
	if (lhs.size() < rhs.size())
		size = lhs.size();
	else
		size = rhs.size();
	typename ft::vector<T>::const_iterator lit = lhs.cbegin();
	typename ft::vector<T>::const_iterator lite = lhs.cend();
	typename ft::vector<T>::const_iterator rit = rhs.cbegin();
	typename ft::vector<T>::const_iterator rite = rhs.cend();
	for (size_t i = 0; i < size; i++) {
		if (*rit < *lit)
			return false;
		else if (*lit < *rit)
			return true;
		lit++;
		rit++;
	}
	return false;
};
template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (lhs < rhs || lhs == rhs);
};
template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs <= rhs);
};
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (!(lhs < rhs) || lhs == rhs);
};
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
	x.swap(y);
};
};

#endif
