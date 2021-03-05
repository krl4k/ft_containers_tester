#ifndef stack_hpp
#define stack_hpp

#include <iostream>
#include <iterator>
#include <memory>
#include "list.hpp"

namespace ft {
template <class T, class Container = list<T> >
class stack {
private:
	list<T> _cont;
public:
	//MARK: - Member types
	typedef T value_type;
	typedef list<T> container_type;
	typedef size_t size_type;
	
	//MARK: - Member functions
	explicit stack (const container_type& ctnr = container_type()) : _cont(ctnr) {};
	bool empty() const {return _cont.empty();};
	size_type size() const {return _cont.size();};
	value_type& top() {return *(--_cont.end());};
	const value_type& top() const {return *(--_cont.cend());};
	void push (const value_type& val) {_cont.push_back(val);};
	void pop() {_cont.pop_back();};
	container_type getCont() const {return _cont;};
};
template <class T, class Container>
bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return lhs.getCont() == rhs.getCont();
};
template <class T, class Container>
bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return lhs.getCont() != rhs.getCont();
};
template <class T, class Container>
bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return lhs.getCont() < rhs.getCont();
};
template <class T, class Container>
bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return lhs.getCont() <= rhs.getCont();
};
template <class T, class Container>
bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return lhs.getCont() > rhs.getCont();
};
template <class T, class Container>
bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return lhs.getCont() >= rhs.getCont();
};
}

#endif
