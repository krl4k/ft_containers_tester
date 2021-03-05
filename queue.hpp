#ifndef queue_hpp
#define queue_hpp

#include <iostream>
#include <iterator>
#include <memory>
#include "list.hpp"

namespace ft {
template <class T, class Container = list<T> > class queue {
private:
	list<T> _cont;
public:
	//MARK: - Member types
	typedef T value_type;
	typedef list<T> container_type;
	typedef size_t size_type;
	
	//MARK: - Member functions
	explicit queue (const container_type& ctnr = container_type()) : _cont(ctnr) {};
	bool empty() const {return _cont.empty();};
	size_type size() const {return _cont.size();};
	value_type& front() {return *_cont.begin();};
	const value_type& front() const {return *_cont.cbegin();};
	value_type& back() {return *(--_cont.end());};
	const value_type& back() const {return *(--_cont.cend());};
	void push (const value_type& val) {_cont.push_back(val);};
	void pop() {_cont.pop_front();};
	container_type getCont() const {return _cont;};
};
//MARK: - Non-member function overloads
template <class T, class Container>
bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
	return lhs.getCont() == rhs.getCont();
};
template <class T, class Container>
bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
	return lhs.getCont() != rhs.getCont();
};
template <class T, class Container>
bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
	return lhs.getCont() < rhs.getCont();
};
template <class T, class Container>
bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
	return lhs.getCont() <= rhs.getCont();
};
template <class T, class Container>
bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
	return lhs.getCont() > rhs.getCont();
};
template <class T, class Container>
bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
	return lhs.getCont() >= rhs.getCont();
};
}

#endif
