#ifndef list_hpp
#define list_hpp

#include <iostream>
#include <iterator>
#include <memory>

namespace ft {
template <class T, class Alloc = std::allocator<T> > class list {
private:
	typedef struct		s_list
	{
		struct s_list*	_next;
		struct s_list*	_prev;
		T*				_data;
	}					t_list;
	
	typedef typename Alloc::template rebind<t_list>::other Alloc_rebind;
	Alloc				_dataAlloc;
	Alloc_rebind		_rebindAlloc;
	
	t_list*				_end;
	size_t				_size;
	
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
	explicit list (const allocator_type& alloc = allocator_type()) : _dataAlloc(alloc) {
		_end = endNodeConsructor();
		_size = 0;
	}
	explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _dataAlloc(alloc) {
		_end = endNodeConsructor();
		_size = 0;
		for (size_type i = 0; i < n; i++) {
			push_back(val);
		}
	};
	template <class InputIterator>
	list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _dataAlloc(alloc) {
		_size = 0;
		_end = endNodeConsructor();
		while (first != last) {
			push_back(*first);
			first++;
		}
	};
	list (const list<T>& src) {
		_size = 0;
		_end = endNodeConsructor();
		for (const_iterator it = src.cbegin(); it != src.cend(); it++)
			push_back(*it);
	}
	
	//MARK: -  Destructor
	~list() {
		while (_end->_next != _end) {
			pop_front();
			_size--;
		}
		endNodeDestructor();
	};
	
	//MARK: - Assign
	list& operator=(const list& src) {
		if (this == &src)
			return (*this);
		clear();
		if (_end)
			endNodeDestructor();
		_end = endNodeConsructor();
		const_iterator it = src.cbegin();
		const_iterator ite = src.cend();
		while (it != ite) {
			this->push_back(*it);
			it++;
		}
		return (*this);
	}
	
	//MARK: - Iterators
	class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		t_list* point;
		iterator() {};
		iterator(t_list* src) : point(src) {}
		iterator(const iterator& src) {
			*this = src;
		}
		iterator& operator=(const iterator& src) {
			if (*this == src)
				return (*this);
			this->point = src.point;
			return (*this);
		}
		virtual ~iterator() {};
		virtual iterator& operator++() {
			point = point->_next;
			return *this;
		}
		virtual iterator operator++(int){
			iterator tmp(*this);
			operator++();
			return tmp;
		}
		virtual iterator& operator--() {
			point = point->_prev;
			return *this;
		}
		virtual iterator operator--(int) {
			iterator tmp(*this);
			operator--();
			return tmp;
		}
		bool operator==(const iterator& rhs) const {
			return point==rhs.point;
		}
		bool operator!=(const iterator& rhs) const {
			return point!=rhs.point;
		}
		value_type& operator*() {
			return *point->_data;
		}
		value_type* operator->() {
			return point->_data;
		}
	};
	class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		t_list* point;
		reverse_iterator() {};
		reverse_iterator(t_list* src) : point(src) {}
		reverse_iterator(const reverse_iterator& src) {
			*this = src;
		}
		reverse_iterator& operator=(const reverse_iterator& src) {
			if (*this == src)
				return (*this);
			this->point = src.point;
			return (*this);
		}
		virtual ~reverse_iterator() {};
		virtual reverse_iterator& operator++() {
			point = point->_prev;
			return *this;
		}
		virtual reverse_iterator operator++(int){
			reverse_iterator tmp(*this);
			operator++();
			return tmp;
		}
		virtual reverse_iterator& operator--() {
			point = point->_next;
			return *this;
		}
		virtual reverse_iterator operator--(int) {
			reverse_iterator tmp(*this);
			operator--();
			return tmp;
		}
		bool operator==(const reverse_iterator& rhs) const {
			return point==rhs.point;
		}
		bool operator!=(const reverse_iterator& rhs) const {
			return point!=rhs.point;
		}
		value_type& operator*() {
			return *point->_data;
		}
		value_type* operator->() {
			return point->_data;
		}
	};
	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		t_list* point;
		const_iterator() {};
		const_iterator(t_list* src) : point(src) {}
		const_iterator(const const_iterator& src) {
			*this = src;
		}
		const_iterator& operator=(const const_iterator& src) {
			if (*this == src)
				return (*this);
			this->point = src.point;
			return (*this);
		}
		virtual ~const_iterator() {};
		virtual const_iterator& operator++() {
			point = point->_next;
			return *this;
		}
		virtual const_iterator operator++(int){
			const_iterator tmp(*this);
			operator++();
			return tmp;
		}
		virtual const_iterator& operator--() {
			point = point->_prev;
			return *this;
		}
		virtual const_iterator operator--(int) {
			const_iterator tmp(*this);
			operator--();
			return tmp;
		}
		bool operator==(const const_iterator& rhs) const {
			return point==rhs.point;
		}
		bool operator!=(const const_iterator& rhs) const {
			return point!=rhs.point;
		}
		const value_type& operator*() {
			return *point->_data;
		}
		value_type* operator->() {
			return point->_data;
		}
	};
	class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		t_list* point;
		const_reverse_iterator() {};
		const_reverse_iterator(t_list* src) : point(src) {}
		const_reverse_iterator(const const_reverse_iterator& src) {
			*this = src;
		}
		const_reverse_iterator& operator=(const const_reverse_iterator& src) {
			if (*this == src)
				return (*this);
			this->point = src.point;
			return (*this);
		}
		virtual ~const_reverse_iterator() {};
		virtual const_reverse_iterator& operator++() {
			point = point->_prev;
			return *this;
		}
		virtual const_reverse_iterator operator++(int){
			const_reverse_iterator tmp(*this);
			operator++();
			return tmp;
		}
		virtual const_reverse_iterator& operator--() {
			point = point->_next;
			return *this;
		}
		virtual const_reverse_iterator operator--(int) {
			const_reverse_iterator tmp(*this);
			operator--();
			return tmp;
		}
		bool operator==(const const_reverse_iterator& rhs) const {
			return point==rhs.point;
		}
		bool operator!=(const const_reverse_iterator& rhs) const {
			return point!=rhs.point;
		}
		const value_type& operator*() {
			return *point->_data;
		}
		value_type* operator->() {
			return point->_data;
		}
	};
	iterator begin() {
		return iterator(_end->_next);
	}
	iterator end() {
		return iterator (_end);
	}
	const_iterator cbegin() const {
		return const_iterator (_end->_next);
	}
	const_iterator cend() const {
		return const_iterator (_end);
	}
	reverse_iterator rbegin() {
		return reverse_iterator(_end->_prev);
	}
	reverse_iterator rend() {
		return reverse_iterator(_end);
	}
	const_reverse_iterator crbegin() const {
		return const_reverse_iterator(_end->_prev);
	}
	const_reverse_iterator crend() const {
		return const_reverse_iterator(_end);
	}
	
	//MARK: - Capacity
	bool empty() const {
		return (_size == 0);
	};
	size_type size() const {
		return _size;
	};
	size_type max_size() const{
		return std::numeric_limits<size_type>::max() / sizeof(t_list);
	};
	
	//MARK: - Element access
	reference front() {
		return *(_end->_next)->_data;
	};
	const_reference front() const {
		return *(_end->_next)->_data;
	};
	reference back() {
		return *(_end->_prev)->_data;
	};
	const_reference back() const {
		return *(_end->_prev)->_data;
	};
	
	//MARK: - Modifiers
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		clear();
		while (first != last) {
			push_back(*first);
			first++;
		}
	}
	void assign (size_type n, const value_type& val) {
		clear();
		for (size_type i = 0; i < n; i++) {
			push_back(val);
		}
	};
	void push_back (const value_type& val) {
		insertBetween(_end->_prev, _end, createNode(val));
	};
	void push_front (const value_type& val) {
		insertBetween(_end, _end->_next, createNode(val));
	};
	void pop_front() {
		if (_size > 0)
			deleteOne(_end->_next);
	};
	void pop_back() {
		if (_size > 0)
			deleteOne(_end->_prev);
	};
	iterator insert (iterator position, const value_type& val) {
		insertBetween(position.point->_prev, position.point, createNode(val));
		return position;
	};
	void insert (iterator position, size_type n, const value_type& val) {
		for (size_type i = 0; i < n; i++) {
			insertBetween(position.point->_prev, position.point, createNode(val));
		}
	};
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		while (first != last) {
			insertBetween(position.point->_prev, position.point, createNode(*first));
			first++;
		}
	};
	iterator erase (iterator position) {
		position++;
		deleteOne(position.point->_prev);
		return position;
	};
	iterator erase (iterator first, iterator last) {
		first++;
		last++;
		while(first != last) {
			deleteOne(first.point->_prev);
			first++;
		}
		return first;
	};
	void swap (list& src) {
		size_type tmpSize = _size;
		t_list* tmpEnd = _end;
		_size = src._size;
		_end = src._end;
		src._size = tmpSize;
		src._end = tmpEnd;
	};
	void resize (size_type n, value_type val = value_type()) {
		if (_size > n)
			while (_size != n) {
				pop_back();
			}
		else
			while (_size != n) {
				push_back(val);
			}
	};
	void clear() {
		while (_size != 0) {
			pop_front();
		}
	};
	
	//MARK: - Operations
	void splice (iterator position, list& src) {
		while (src._size != 0) {
			insertBetween(position.point->_prev, position.point, src.pullNode(src._end->_next));
		}
	};
	void splice (iterator position, list& src, iterator i) {
		insertBetween(position.point->_prev, position.point, src.pullNode(i.point));
	};
	void splice (iterator position, list& src, iterator first, iterator last) {
		while (first != last) {
			first++;
			insertBetween(position.point->_prev, position.point, src.pullNode(first.point->_prev));
		}
	};
	void remove (const value_type& val) {
		iterator it = begin();
		iterator ite = end();
		while (it != ite) {
			if (comaprator(val, it) == true)
				deleteOne(it.point);
			it++;
		}
	};
	template <class Predicate>
	void remove_if (Predicate pred){
		iterator it = begin();
		iterator ite = end();
		while (it != ite) {
			if (pred(*it) == true)
				deleteOne(it.point);
			it++;
		}
	};
	void unique() {
		iterator it = begin()++;
		iterator eit = end();
		while (it != eit) {
			if (comaprator(*(it.point->_prev)->_data, it)) {
				it++;
				deleteOne(it.point->_prev);
			}
			else
				it++;
		}
	};
	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred) {
		iterator it = begin()++;
		iterator eit = end();
		while (it != eit) {
			if (binary_pred(*it.point->_data, *(it.point->_prev)->_data)) {
				it++;
				deleteOne(it.point->_prev);
			}
			else
				it++;
		}
	};
	void merge (list& src) {
		iterator it = begin();
		iterator eit = end();
		iterator srci = src.begin();
		while (it != eit && src.size() != 0) {
			if (*it > *srci) {
				srci++;
				insertBetween(it.point->_prev, it.point, src.pullNode((srci.point)->_prev));
			}
			else
				it++;
		}
		if (it == eit)
			splice(eit, src);
	};
	template <class Compare>
	void merge (list& src, Compare comp) {
		iterator it = begin();
		iterator eit = end();
		iterator srci = src.begin();
		while (it != eit && src.size() != 0) {
			if (!comp(*it, *srci)) {
				srci++;
				insertBetween((it.point)->_prev, it.point, src.pullNode((srci.point)->_prev));
			}
			else
				it++;
		}
		if (it == eit)
			splice(eit, src);
	};
	void sort() {
		iterator it = begin();
		it--;
		iterator eit = end();
		eit--;
		while (++it != eit) {
			if (*it.point->_data > *(it.point->_next)->_data) {
				insertBetween(it.point->_prev, it.point, pullNode(it.point->_next));
				it = begin();
				it--;
			}
		}
	};
	template <class Compare>
	void sort (Compare comp) {
		iterator it = begin();
		it--;
		iterator eit = end();
		eit--;
		while (++it != eit) {
			if (!comp(*it.point->_data, *(it.point->_next)->_data) && *it.point->_data!= *(it.point->_next)->_data) {
				insertBetween(it.point->_prev, it.point, pullNode(it.point->_next));
				it = begin();
				it--;
			}
		}
	};
	void reverse() {
		for (iterator it = begin(); it.point->_next != _end;) {
			insertBetween(it.point->_prev, it.point, pullNode(_end->_prev));
		}
	};
	
	//MARK: - Utilitys
private:
	bool comaprator(const value_type& val, iterator elem) {
		if (*elem.point->_data == val)
			return true;
		return false;
	}
	t_list* pullNode(t_list* toPull) {
		_size--;
		(toPull->_next)->_prev = toPull->_prev;
		(toPull->_prev)->_next = toPull->_next;
		toPull->_next = nullptr;
		toPull->_prev = nullptr;
		return toPull;
	}
	void deleteOne(t_list* toDelete) {
		(toDelete->_prev)->_next = toDelete->_next;
		(toDelete->_next)->_prev = toDelete->_prev;
		_dataAlloc.destroy(toDelete->_data);
		_dataAlloc.deallocate(toDelete->_data, 1);
		_rebindAlloc.destroy(toDelete);
		_rebindAlloc.deallocate(toDelete, 1);
		_size--;
	}
	void insertBetween(t_list* left, t_list* right, t_list* newone) {
		left->_next = newone;
		newone->_next = right;
		right->_prev = newone;
		newone->_prev = left;
		_size++;
	};
	t_list* createNode(const value_type& val) {
		t_list *newone = _rebindAlloc.allocate(1);
		_rebindAlloc.construct(newone);
		newone->_data = _dataAlloc.allocate(1);
		_dataAlloc.construct(newone->_data, val);
		newone->_next = _end;
		newone->_prev = _end;
		return (newone);
	};
	t_list* endNodeConsructor() {
		t_list *endNode = _rebindAlloc.allocate(1);
		_rebindAlloc.construct(endNode);
		endNode->_data = _dataAlloc.allocate(1);
		_dataAlloc.construct(endNode->_data);
		endNode->_prev = endNode;
		endNode->_next = endNode;
		return (endNode);
	}
	void endNodeDestructor() {
		_dataAlloc.destroy(_end->_data);
		_dataAlloc.deallocate(_end->_data, 1);
		_rebindAlloc.destroy(_end);
		_rebindAlloc.deallocate(_end, 1);
	}
};

//MARK: - Non-member function overloads
template <class T, class Alloc>
bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	typename ft::list<T>::const_iterator lit = lhs.cbegin();
	typename ft::list<T>::const_iterator lite = lhs.cend();
	typename ft::list<T>::const_iterator rit = rhs.cbegin();
	typename ft::list<T>::const_iterator rite = rhs.cend();
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
bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return !(lhs == rhs);
};
template <class T, class Alloc>
bool operator<  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	size_t size;
	if (lhs.size() < rhs.size())
		size = lhs.size();
	else
		size = rhs.size();
	typename ft::list<T>::const_iterator lit = lhs.cbegin();
	typename ft::list<T>::const_iterator lite = lhs.cend();
	typename ft::list<T>::const_iterator rit = rhs.cbegin();
	typename ft::list<T>::const_iterator rite = rhs.cend();
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
bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return (lhs < rhs || lhs == rhs);
};
template <class T, class Alloc>
bool operator>  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return !(lhs <= rhs);
};
template <class T, class Alloc>
bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return (!(lhs < rhs) || lhs == rhs);
};
template <class T, class Alloc>
void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y) {
	x.swap(y);
};
}

#endif
