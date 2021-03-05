#ifndef map_hpp
#define map_hpp

#include <iostream>
#include <iterator>
#include <memory>

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > class map {
public:
	typedef struct	s_node
	{
		struct s_node*					_head;
		struct s_node*					_right;
		struct s_node*					_left;
		std::pair<const Key, T>*		_data;
		int								_l;
		int								_r;
	}				t_node;
	
	typedef typename Alloc::template rebind<t_node>::other Alloc_rebind;
	Alloc			_dataAlloc;
	Alloc_rebind	_nodeAlloc;
	Compare			_comp;

	t_node*			_left;
	t_node*			_right;
	t_node*			_root;
	size_t			_size;

public:
	//MARK: - Member types
	typedef Key key_type;
	typedef T mapped_type;
	typedef std::pair<const key_type,mapped_type> value_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	class value_compare : public std::binary_function<value_type,value_type,bool>
	{
	public:
	  Compare comp;
	  value_compare (Compare c) : comp(c) {}
	public:
	  bool operator() (const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
	};
	
	//MARK: - Constructors
	explicit map (const key_compare& comp = key_compare(),
				  const allocator_type& alloc = allocator_type()) : _dataAlloc(alloc), _comp(comp) {
		_root = 0;
		_left = endNodeCreator();
		_right = endNodeCreator();
		_size = 0;
	};
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		 const allocator_type& alloc = allocator_type(), typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _dataAlloc(alloc), _comp(comp) {
		_root = 0;
		_left = endNodeCreator();
		_right = endNodeCreator();
		_size = 0;
		insert(first, last);
	};
	map (const map& x) {
		*this = x;
	};
	
	//MARK: - Destructor
	~map() {
		clear();
		deleteOne(_left);
		deleteOne(_right);
	};
	
	//MARK: - Assign
	map& operator=(const map& x) {
		if (this == &x)
			return *this;
		clear();
		insert(x.cbegin(), x.cend());
		return *this;
	};
	
	//MARK: - Iterators
	class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		t_node* point;
		const key_type* first;
		T* second;
		iterator() {};
		iterator(t_node* src) : point(src), first(&src->_data->first), second(&src->_data->second) {}
		iterator(const iterator& src) {
			*this = src;
		}
		iterator& operator=(const iterator& src) {
			if (*this == src)
				return (*this);
			this->point = src.point;
			first = &point->_data->first;
			second = &point->_data->second;
			return (*this);
		}
		virtual ~iterator() {};
		virtual iterator& operator++() {
			if (point->_right != 0) {
				point = point->_right;
				while (point->_left != 0)
					point = point->_left;
			}
			else {
				if (point->_l == -1)
					point = point->_head;
				else {
					key_type tmp = (point->_data)->first;
					while (tmp >= (point->_data)->first && point->_head)
						point = point->_head;
				}
			}
			first = &point->_data->first;
			second = &point->_data->second;
			return *this;
		}
		virtual iterator operator++(int){
			iterator tmp(*this);
			operator++();
			return tmp;
		}
		virtual iterator& operator--() {
			if (point->_left != 0) {
				point = point->_left;
				while (point->_right != 0)
					point = point->_right;
			}
			else {
				if (point->_r == -1)
					point = point->_head;
				else {
					key_type tmp = (point->_data)->first;
					while (tmp <= (point->_data)->first && point->_head)
						point = point->_head;
				}
			}
			first = &point->_data->first;
			second = &point->_data->second;
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
	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		t_node* point;
		const key_type* first;
		const T* second;
		const_iterator() {};
		const_iterator(t_node* src) : point(src), first(&src->_data->first), second(&src->_data->second) {}
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
			if (point->_right != 0) {
				point = point->_right;
				while (point->_left != 0)
					point = point->_left;
			}
			else {
				if (point->_l == -1)
					point = point->_head;
				else {
					key_type tmp = (point->_data)->first;
					while (tmp >= (point->_data)->first)
						point = point->_head;
				}
			}
			first = &point->_data->first;
			second = &point->_data->second;
			return *this;
		}
		virtual const_iterator operator++(int){
			const_iterator tmp(*this);
			operator++();
			return tmp;
		}
		virtual const_iterator& operator--() {
			if (point->_left != 0) {
				point = point->_left;
				while (point->_right != 0)
					point = point->_right;
			}
			else {
				if (point->_r == -1)
					point = point->_head;
				else {
					key_type tmp = (point->_data)->first;
					while (tmp <= (point->_data)->first)
						point = point->_head;
				}
			}
			first = &point->_data->first;
			second = &point->_data->second;
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
		const value_type* operator->() {
			return point->_data;
		}
	};
	class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		t_node* point;
		const key_type* first;
		T* second;
		reverse_iterator() {};
		reverse_iterator(t_node* src) : point(src), first(&src->_data->first), second(&src->_data->second) {}
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
		virtual reverse_iterator& operator--() {
			if (point->_right != 0) {
				point = point->_right;
				while (point->_left != 0)
					point = point->_left;
			}
			else {
				if (point->_l == -1)
					point = point->_head;
				else {
					key_type tmp = (point->_data)->first;
					while (tmp >= (point->_data)->first)
						point = point->_head;
				}
			}
			first = &point->_data->first;
			second = &point->_data->second;
			return *this;
		}
		virtual reverse_iterator operator--(int){
			reverse_iterator tmp(*this);
			operator--();
			return tmp;
		}
		virtual reverse_iterator& operator++() {
			if (point->_left != 0) {
				point = point->_left;
				while (point->_right != 0)
					point = point->_right;
			}
			else {
				if (point->_r == -1)
					point = point->_head;
				else {
					key_type tmp = (point->_data)->first;
					while (tmp <= (point->_data)->first)
						point = point->_head;
				}
			}
			first = &point->_data->first;
			second = &point->_data->second;
			return *this;
		}
		virtual reverse_iterator operator++(int) {
			reverse_iterator tmp(*this);
			operator++();
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
	class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		t_node* point;
		const key_type* first;
		const T* second;
		const_reverse_iterator() {};
		const_reverse_iterator(t_node* src) : point(src), first(&src->_data->first), second(&src->_data->second) {}
		const_reverse_iterator(const const_reverse_iterator& src) {
			*this = src;
		}
		const_reverse_iterator& operator=(const reverse_iterator& src) {
			if (*this == src)
				return (*this);
			this->point = src.point;
			return (*this);
		}
		virtual ~const_reverse_iterator() {};
		virtual const_reverse_iterator& operator--() {
			if (point->_right != 0) {
				point = point->_right;
				while (point->_left != 0)
					point = point->_left;
			}
			else {
				if (point->_l == -1)
					point = point->_head;
				else {
					key_type tmp = (point->_data)->first;
					while (tmp >= (point->_data)->first)
						point = point->_head;
				}
			}
			first = &point->_data->first;
			second = &point->_data->second;
			return *this;
		}
		virtual const_reverse_iterator operator--(int){
			const_reverse_iterator tmp(*this);
			operator--();
			return tmp;
		}
		virtual const_reverse_iterator& operator++() {
			if (point->_left != 0) {
				point = point->_left;
				while (point->_right != 0)
					point = point->_right;
			}
			else {
				if (point->_r == -1)
					point = point->_head;
				else {
					key_type tmp = (point->_data)->first;
					while (tmp <= (point->_data)->first)
						point = point->_head;
				}
			}
			first = &point->_data->first;
			second = &point->_data->second;
			return *this;
		}
		virtual const_reverse_iterator operator++(int) {
			const_reverse_iterator tmp(*this);
			operator++();
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
		const value_type* operator->() {
			return point->_data;
		}
	};
	iterator begin() {
		if (_size == 0)
			return end();
		return iterator(_left->_head);
	}
	iterator end() {
		return iterator(_right);
	}
	const_iterator cbegin() const {
		if (_size == 0)
			return cend();
		return const_iterator(_left->_head);
	}
	const_iterator cend() const {
		return const_iterator(_right);
	}
	reverse_iterator rbegin() {
		if (_size == 0)
			return rend();
		return reverse_iterator(_right->_head);
	}
	reverse_iterator rend() {
		return reverse_iterator(_left);
	}
	const_reverse_iterator crbegin() const {
		if (_size == 0)
			return crend();
		return const_reverse_iterator(_right->_head);
	}
	const_reverse_iterator crend() const {
		return const_reverse_iterator(_left);
	}
	
	//MARK: - Capacity
	bool empty() const {
		return (_size == 0);
	};
	size_type size() const {
		return _size;
	};
	size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof(t_node);
	};
	
	//MARK: - Element access
	mapped_type& operator[] (const key_type& k) {
		return insert(std::pair<key_type, mapped_type>(k, mapped_type())).first.point->_data->second;
	};
	
	//MARK: - Modifiers
	std::pair<iterator,bool> insert (const value_type& val) {
		t_node* res = serchPlace(val.first, _root);
		if (res == 0 || res->_data->first != val.first)
			return std::pair<iterator, bool>(iterator(insertNode(res, nodeCreator(val))), true);
		return std::pair<iterator, bool>(iterator(res), false);
	};
	iterator insert (iterator position, const value_type& val) {
		(void)position;
		t_node* res = serchPlace(val.first, _root);
		if (res == 0 || res->_data->first != val.first)
			return iterator(insertNode(res, nodeCreator(val)));
		return iterator(res);
	};
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		while (first != last) {
			insert(*first);
			first++;
		}
	};
	void erase (iterator position) {
		t_node* tmp = (position.point)->_head;
		cutEnds();
		if (position.point->_left == 0 && position.point->_right == 0) {
			makeHeadLink(position.point, 0);
			if (position.point == _root)
				return deleteLast(position.point);
			deleteOne(position.point);
			while (tmp) {
				changeIndex(tmp);
				balanceBranch(tmp);
				tmp = tmp->_head;
			}
		}
		else if (position.point->_left == 0 && position.point->_right != 0) {
			makeHeadLink(position.point, position.point->_right);
			(position.point->_right)->_head = tmp;
			if (position.point == _root)
				_root = (position.point)->_right;
			deleteOne(position.point);
			while (tmp) {
				changeIndex(tmp);
				balanceBranch(tmp);
				tmp = tmp->_head;
			}
		}
		else if (position.point->_left != 0 && position.point->_right == 0) {
			makeHeadLink(position.point, position.point->_left);
			(position.point->_left)->_head = tmp;
			if (position.point == _root)
				_root = (position.point)->_left;
			deleteOne(position.point);
			while (tmp) {
				changeIndex(tmp);
				balanceBranch(tmp);
				tmp = tmp->_head;
			}
		}
		else {
			t_node* tmp2 = poolMin((position.point)->_right);
			t_node* tmp3 = tmp2->_head;
			while (tmp3 != tmp) {
				changeIndex(tmp3);
				balanceBranch(tmp3);
				tmp3 = tmp3->_head;
			}
			if (position.point == _root)
				_root = tmp2;
			deleteOne(replaceOne(position.point, tmp2));
			while (tmp2) {
				changeIndex(tmp2);
				balanceBranch(tmp2);
				tmp2 = tmp2->_head;
			}
		}
		glueEnds();
	};
	size_type erase (const key_type& k) {
		t_node* goal = serchPlace(k, _root);
		if (goal->_data->first != k)
			return 0;
		erase(iterator(goal));
		return 1;
	};
	void erase (iterator first, iterator last) {
		while (first != last) {
			iterator tmp = first;
			first++;
			erase(tmp);
		}
	};
	void swap (map& x) {
		t_node* tmpLeft = _left;
		t_node* tmpRight = _right;
		t_node* tmpRoot = _root;
		size_type tmpSize = _size;
		_left = x._left;
		_right = x._right;
		_root = x._root;
		_size = x._size;
		x._left = tmpLeft;
		x._right = tmpRight;
		x._root = tmpRoot;
		x._size = tmpSize;
	};
	void clear() {
		erase(begin(), end());
	};
	
	//MARK: - Observers
	key_compare key_comp() const {return _comp;};
	value_compare value_comp() const {return value_compare(_comp);};
	
	//MARK: - Operations
	iterator find (const key_type& k) {
		t_node* tmp = serchPlace(k, _root);
		key_compare cmp = key_comp();
		if (!cmp(k, tmp->_data->first) && !cmp(tmp->_data->first, k))
			return iterator(tmp);
		return end();
	};
	const_iterator find (const key_type& k) const {
		t_node* tmp = serchPlace(k, _root);
		key_compare cmp = key_comp();
		if (!cmp(k, tmp->_data->first) && !cmp(tmp->_data->first, k))
			return const_iterator(tmp);
		return cend();
	};
	size_type count (const key_type& k) const {
		t_node* tmp = serchPlace(k, _root);
		key_compare cmp = key_comp();
		return (!cmp(k, tmp->_data->first) && !cmp(tmp->_data->first, k));
	};
	iterator lower_bound (const key_type& k) {
		key_compare cmp = key_comp();
		for (iterator it = begin(); it != end(); ++it)
			if (!cmp(it->first, k))
				return it;
		return end();
	};
	const_iterator lower_bound (const key_type& k) const {
		key_compare cmp = key_comp();
		for (const_iterator it = cbegin(); it != cend(); ++it)
			if (!cmp(it->first, k))
				return it;
		return cend();
	};
	iterator upper_bound (const key_type& k) {
		key_compare cmp = key_comp();
		for (iterator it = begin(); it != end(); ++it)
			if (!cmp(it->first, k)) {
				if (it->first == k)
					return ++it;
				else
					return it;
			}
		return end();
	};
	const_iterator upper_bound (const key_type& k) const {
		key_compare cmp = key_comp();
		for (const_iterator it = cbegin(); it != cend(); ++it)
			if (!cmp(it->first, k)) {
				if (it->first == k)
					return ++it;
				else
					return it;
			}
		return cend();
	};
	std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		return std::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
	};
	std::pair<iterator,iterator> equal_range (const key_type& k) {
		return std::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
	};
	
	//MARK: - Utilitys
private:
	void deleteLast(t_node* last) {
		_root = 0;
		_left->_head = 0;
		_left->_right = 0;
		_left->_left = 0;
		_right->_head = 0;
		_right->_right = 0;
		_right->_left = 0;
		_right->_r = 0;
		_right->_l = 0;
		_left->_r = 0;
		_left->_l = 0;
		deleteOne(last);
	}
	t_node* serchPlace(Key n, t_node* head) const {
		if (head == 0)
			return _root;
		if (n < head->_data->first && head->_left != 0)
			return serchPlace(n, head->_left);
		else if (n < head->_data->first && head->_left == 0)
			return head;
		else if (n > head->_data->first && head->_right != 0)
			return serchPlace(n, head->_right);
		else if (n > head->_data->first && head->_right == 0)
			return head;
		return head;
	}
	void glueEnds() {
		t_node* tmp = _root;
		if (_left->_head == 0 || ((_left->_head)->_left != 0 && (_left->_head)->_left != _left)) {
			while (tmp->_left && tmp->_left->_l != -1)
				tmp = tmp->_left;
			tmp->_left = _left;
			_left->_head = tmp;
		}
		else
			(_left->_head)->_left = _left;
		tmp = _root;
		if (_right->_head == 0 || ((_right->_head)->_right != 0 && (_right->_head)->_right != _right)) {
			while (tmp->_right && tmp->_right->_r != -1)
				tmp = tmp->_right;
			tmp->_right = _right;
			_right->_head = tmp;
		}
		else
			(_right->_head)->_right = _right;
	}
	void cutEnds() {
		if (_right->_head && (_right->_head)->_right == _right)
			(_right->_head)->_right = 0;
		if (_left->_head && (_left->_head)->_left == _left)
			(_left->_head)->_left = 0;
	}
	void balanceBranch(t_node* root) {
		if (root->_l - root->_r < -1 && (root->_right)->_l <= (root->_right)->_r)
			leftTwist(root);
		else if (root->_l - root->_r > 1 && (root->_left)->_r <= (root->_left)->_l)
			rightTwist(root);
		else if (root->_l - root->_r < -1 && (root->_right)->_l > (root->_right)->_r)
			bigLeftTwist(root);
		else if (root->_l - root->_r > 1 && (root->_left)->_r > (root->_left)->_l)
			bigRightTwist(root);
	}
	t_node* incBranch(t_node* newone) {
		t_node* tmp = newone;
		while (tmp != _root) {
			if (tmp == (tmp->_head)->_left && ((tmp->_head)->_l < tmp->_l + 1 || (tmp->_head)->_l < tmp->_r + 1))
				tmp->_head->_l++;
			else if (tmp == (tmp->_head)->_right && ((tmp->_head)->_r < tmp->_l + 1 || (tmp->_head)->_r < tmp->_r + 1))
				tmp->_head->_r++;
			tmp = tmp->_head;
			balanceBranch(tmp);
		}
		return newone;
	}
	void insertBetween(t_node* side, t_node* newone) {
		newone->_head = side->_head;
		side->_head = newone;
		if (side == _right) {
			(newone->_head)->_right = newone;
			newone->_right = side;
		}
		else {
			(newone->_head)->_left = newone;
			newone->_left = side;
		}
	}
	t_node* insertNode(t_node* placeHold, t_node* newone) {
		if (placeHold == 0) {
			_root = newone;
			newone->_left = _left;
			_left->_head = newone;
			newone->_right = _right;
			_right->_head = newone;
		}
		else if (placeHold == _left)
			insertBetween(_left, newone);
		else if (placeHold == _right)
			insertBetween(_right, newone);
		else if (placeHold->_data->first < newone->_data->first)
			placeHold->_right = newone;
		else
			placeHold->_left = newone;
		if (placeHold != 0 && placeHold != _left && placeHold != _right)
			newone->_head = placeHold;
		_size++;
		return incBranch(newone);
	}
	t_node* endNodeCreator() {
		t_node* end =_nodeAlloc.allocate(1);
		_nodeAlloc.construct(end);
		end->_data = _dataAlloc.allocate(1);
		_dataAlloc.construct(end->_data);
		end->_head = 0;
		end->_left = 0;
		end->_right = 0;
		end->_l = -1;
		end->_r = -1;
		return (end);
	}
	t_node* nodeCreator(const value_type& pair) {
		t_node* newone = _nodeAlloc.allocate(1);
		_nodeAlloc.construct(newone);
		newone->_data = _dataAlloc.allocate(1);
		_dataAlloc.construct(newone->_data, pair);
		newone->_head = 0;
		newone->_left = 0;
		newone->_right = 0;
		return (newone);
	}
	void leftTwist(t_node* root) {
		cutEnds();
		t_node* newRoot = root->_right;
		makeHeadLink(root, newRoot);
		newRoot->_head = root->_head;
		root->_right = newRoot->_left;
		root->_r = newRoot->_l;
		if (root->_right)
			(root->_right)->_head = root;
		newRoot->_left = root;
		root->_head = newRoot;
		changeIndex(newRoot);
		if (root == _root)
			_root = newRoot;
		glueEnds();
	}
	void rightTwist(t_node* root) {
		cutEnds();
		t_node* newRoot = root->_left;
		makeHeadLink(root, newRoot);
		newRoot->_head = root->_head;
		root->_left = newRoot->_right;
		root->_l = newRoot->_r;
		if (root->_left)
			(root->_left)->_head = root;
		newRoot->_right = root;
		root->_head = newRoot;
		changeIndex(newRoot);
		if (root == _root)
			_root = newRoot;
		glueEnds();
	}
	void bigLeftTwist(t_node* root) {
		cutEnds();
		t_node* newRoot = (root->_right)->_left;
		t_node* tmp = root->_right;
		newRoot->_head = root->_head;
		makeHeadLink(root, newRoot);
		root->_right = newRoot->_left;
		root->_r = newRoot->_l;
		if (root->_right)
			(root->_right)->_head = root;
		tmp->_left = newRoot->_right;
		tmp->_l = newRoot->_r;
		if (tmp->_left)
			(tmp->_left)->_head = tmp;
		newRoot->_left = root;
		root->_head = newRoot;
		newRoot->_right = tmp;
		tmp->_head = newRoot;
		changeIndex(root);
		changeIndex(tmp);
		changeIndex(newRoot);
		if (root == _root)
			_root = newRoot;
		glueEnds();
	}
	void bigRightTwist(t_node* root) {
		cutEnds();
		t_node* newRoot = (root->_left)->_right;
		t_node* tmp = root->_left;
		newRoot->_head = root->_head;
		makeHeadLink(root, newRoot);
		root->_left = newRoot->_right;
		root->_l = newRoot->_r;
		if (root->_left)
			(root->_left)->_head = root;
		tmp->_right = newRoot->_left;
		tmp->_r = newRoot->_l;
		if (tmp->_right)
			(tmp->_right)->_head = tmp;
		newRoot->_right = root;
		tmp->_head = newRoot;
		newRoot->_left = tmp;
		root->_head = newRoot;
		changeIndex(root);
		changeIndex(tmp);
		changeIndex(newRoot);
		if (root == _root)
			_root = newRoot;
		glueEnds();
	}
	void changeIndex(t_node* goal) {
		if (goal->_right) {
			if (goal->_right->_l > goal->_right->_r)
				goal->_r = goal->_right->_l + 1;
			else
				goal->_r = goal->_right->_r + 1;
		}
		else
			goal->_r = 0;
		if (goal->_left) {
			if (goal->_left->_l > goal->_left->_r)
				goal->_l = goal->_left->_l + 1;
			else
				goal->_l = goal->_left->_r + 1;
		}
		else
			goal->_l = 0;
	}
	void makeHeadLink(t_node* goal, t_node* newone) {
		if (goal->_head) {
			if (goal == (goal->_head)->_right)
				(goal->_head)->_right = newone;
			else
				(goal->_head)->_left = newone;
		}
	}
	void deleteOne(t_node* toDelete) {
		if (toDelete == _right->_head && toDelete->_head)
			_right->_head = (toDelete->_head)->_head;
		else
			_right->_head = 0;
		if (toDelete == _left->_head && toDelete->_head)
			_left->_head = (toDelete->_head)->_head;
		else
			_left->_head = 0;
		_dataAlloc.destroy(toDelete->_data);
		_dataAlloc.deallocate(toDelete->_data, 1);
		_nodeAlloc.destroy(toDelete);
		_nodeAlloc.deallocate(toDelete, 1);
		_size--;
	}
	t_node* replaceOne(t_node* oldone, t_node* newone) {
		newone->_head = oldone->_head;
		makeHeadLink(oldone, newone);
		newone->_left = oldone->_left;
		if (newone->_left)
			(newone->_left)->_head = newone;
		newone->_right = oldone->_right;
		if (newone->_right)
			(newone->_right)->_head = newone;
		newone->_l = oldone->_l;
		newone->_r = oldone->_r;
		return oldone;
	}
	t_node* poolMin(t_node* goal) {
		if (goal->_left == 0 && goal->_right == 0)
			(goal->_head)->_right = 0;
		else if (goal->_left == 0) {
			(goal->_head)->_right = goal->_right;
			(goal->_right)->_head = goal->_head;
		}
		else {
			while (goal->_left)
				goal = goal->_left;
			if (goal->_right != 0) {
				(goal->_head)->_left = goal->_right;
				(goal->_right)->_head = goal->_head;
			}
			else
				(goal->_head)->_left = 0;
		}
		return goal;
	}
	
};
}

#endif
