#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include "map.hpp"
#include "list.hpp"
#include "vector.hpp"
#include "queue.hpp"
#include "stack.hpp"

//MARK: - Utils

bool singleDigit(const int& value) {
	return (value < 10);
}
struct isEven {
	bool operator()(const int& value) {
		return (value % 2) == 0;
	}
};
bool sameRemainderOfDivision(int first, int second) {
	if (first % 10 == second % 10)
		return true;
	return false;
}
bool myComparison (int first, int second) {
	return (first > second);
}

//MARK: - Utilst list

template <typename T>
void listPushBackElem(std::list<T> &std, ft::list<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push_back(i);
		ft.push_back(i);
	}
}

template <typename T>
void listPushFrontElem(std::list<T> &std, ft::list<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push_front(i);
		ft.push_front(i);
	}
}

template <typename T>
void listPopFrontElem(std::list<T> &std, ft::list<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.pop_front();
		ft.pop_front();
	}
}

template <typename T>
void listPopBackElem(std::list<T> &std, ft::list<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.pop_back();
		ft.pop_back();
	}
}

//MARK: - Utilst vector

template <typename T>
void VectorPushBackElem(std::vector<T> &std, ft::vector<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push_back(i);
		ft.push_back(i);
	}
}

template <typename T>
void VectorPopBackElem(std::vector<T> &std, ft::vector<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.pop_back();
		ft.pop_back();
	}
}

template <typename T>
void VectorFillStr(std::vector<T> &def, ft::vector<T> &my, std::string &std, std::string &ft) {
	for (typename std::vector<T>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (typename ft::vector<T>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	std += def.capacity();
	ft += my.capacity();
}

//MARK: - Utilst map

template <typename Key, typename T>
void mapInsertElem(std::map<Key,T> &std, ft::map<Key,T> &ft, unsigned long number) {
	Key i;
	T j;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		j = rand();
		std::pair<Key, T> res(i, j);
		std.insert(res);
		ft.insert(res);
	}
}

template <typename Key, typename T>
void mapFillStr(std::map<Key,T> &def, ft::map<Key,T> &my, std::string &std, std::string &ft) {
	for (typename std::map<Key,T>::iterator it = def.begin(); it != def.end(); it++) {
		std += it->first;
		std += it->second;
	}
	for (typename ft::map<Key,T>::iterator it = my.begin(); it != my.end(); it++) {
		ft += it->first;
		ft += it->second;
	}
	std += def.size();
	ft += my.size();
}

//MARK: - Utils stack

template <typename T>
void stackPushElem(std::stack<T> &std, ft::stack<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push(i);
		ft.push(i);
	}
}

template <typename T>
void fillStrStack(std::stack<T> &def, ft::stack<T> &my, std::string &std, std::string &ft) {
	std += def.top();
	ft += my.top();
	std += def.size();
	ft += my.size();
}

//MARK: - Utils queue

template <typename T>
void queuePushElem(std::queue<T> &std, ft::queue<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push(i);
		ft.push(i);
	}
}

template <typename T>
void fillStrQueue(std::queue<T> &def, ft::queue<T> &my, std::string &std, std::string &ft) {
	std += def.back();
	ft += my.back();
	std += def.front();
	ft += my.front();
	std += def.size();
	ft += my.size();
}

//MARK: - Constructors list

void defaultCnstTest(std::string &std, std::string &ft) {
	std::cout << "Default int constructor test" << " ";
	std::list<int> intStd;
	ft::list<int> intFt;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Default std::string constructor test" << " ";
	std::list<std::string> stringStd;
	ft::list<std::string> stringFt;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Default float constructor test" << " ";
	std::list<float> floatStd;
	ft::list<float> floatFt;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillCnstTest(std::string &std, std::string &ft, int number) {
	std::cout << "Fill int constructor test" << " ";
	int i = rand();
	std::list<int> intStd(number, i);
	ft::list<int> intFt(number, i);
	for (std::list<int>::iterator it = intStd.begin(); it != intStd.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = intFt.begin(); it != intFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Fill std::string constructor test" << " ";
	std::string j;
	j += rand();
	std::list<std::string> stringStd(number, j);
	ft::list<std::string> stringFt(number, j);
	for (std::list<std::string>::iterator it = stringStd.begin(); it != stringStd.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = stringFt.begin(); it != stringFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Fill float constructor test" << " ";
	float k = rand();
	std::list<float> floatStd(number, k);
	ft::list<float> floatFt(number, k);
	for (std::list<float>::iterator it = floatStd.begin(); it != floatStd.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = floatFt.begin(); it != floatFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTest(std::string &std, std::string &ft, int number) {
	std::cout << "Range int constructor test" << " ";
	std::list<int> testInt;
	for (int l = 0; l < number; l++) {
		int i = rand();
		testInt.push_back(i);
	}
	std::list<int> intStd(testInt.begin(), testInt.end());
	ft::list<int> intFt(testInt.begin(), testInt.end());
	for (std::list<int>::iterator it = intStd.begin(); it != intStd.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = intFt.begin(); it != intFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Range std::string constructor test" << " ";
	std::list<std::string> testString;
	for (int l = 0; l < number; l++) {
		std::string j;
		j += rand();
		testString.push_back(j);
	}
	std::list<std::string> stringStd(testString.begin(), testString.end());
	ft::list<std::string> stringFt(testString.begin(), testString.end());
	for (std::list<std::string>::iterator it = stringStd.begin(); it != stringStd.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = stringFt.begin(); it != stringFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Range float constructor test" << " ";
	
	std::list<float> testFloat;
	for (int l = 0; l < number; l++) {
		float k = rand();
		testFloat.push_back(k);
	}
	std::list<float> floatStd(testFloat.begin(), testFloat.end());
	ft::list<float> floatFt(testFloat.begin(), testFloat.end());
	for (std::list<float>::iterator it = floatStd.begin(); it != floatStd.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = floatFt.begin(); it != floatFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Assign list

void assignTest(std::string &std, std::string &ft, int i) {
	std::cout << "Assign int test" << " ";
	int j = rand();
	std::list<int> stdFst(i, j);
	ft::list<int> ftFst(i, j);
	std::list<int> stdSec;
	ft::list<int> ftSec;
	stdSec = stdFst;
	ftSec = ftFst;
	for (std::list<int>::iterator it = stdSec.begin(); it != stdSec.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = ftSec.begin(); it != ftSec.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Assign std::string test" << " ";
	std::string m;
	m += rand();
	std::list<std::string> stdFstStr(i, m);
	ft::list<std::string> ftFstStr(i, m);
	std::list<std::string> stdSecStr;
	ft::list<std::string> ftSecStr;
	stdSecStr = stdFstStr;
	ftSecStr = ftFstStr;
	for (std::list<std::string>::iterator it = stdSecStr.begin(); it != stdSecStr.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = ftSecStr.begin(); it != ftSecStr.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Assign float test" << " ";
	float n = rand();
	std::list<float> stdFstFlt(i, n);
	ft::list<float> ftFstFlt(i, n);
	std::list<float> stdSecFlt;
	ft::list<float> ftSecFlt;
	stdSecFlt = stdFstFlt;
	ftSecFlt = ftFstFlt;
	for (std::list<float>::iterator it = stdSecFlt.begin(); it != stdSecFlt.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = ftSecFlt.begin(); it != ftSecFlt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestList(std::string &std, std::string &ft) {
	std::cout << "Range assign int test" << " ";
	std::list<int> test;
	std::list<int> def;
	ft::list<int> my;
	for (int i = 0; i < 100; i++)
		test.push_back(rand());
	def.assign(test.begin(), test.end());
	my.assign(test.begin(), test.end());
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestListFloat(std::string &std, std::string &ft) {
	std::cout << "Range assign float test" << " ";
	std::list<float> test;
	std::list<float> def;
	ft::list<float> my;
	for (int i = 0; i < 100; i++)
		test.push_back(rand());
	def.assign(test.begin(), test.end());
	my.assign(test.begin(), test.end());
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestListStr(std::string &std, std::string &ft) {
	std::cout << "Range assign std::string test" << " ";
	std::list<std::string> test;
	std::list<std::string> def;
	ft::list<std::string> my;
	std::string j;
	for (int i = 0; i < 100; i++) {
		j += rand();
		test.push_back(j);
		j.clear();
	}
	def.assign(test.begin(), test.end());
	my.assign(test.begin(), test.end());
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Iteratot list

void iteratorTest(std::string &std, std::string &ft, int number) {
	std::list<int> testStd;
	ft::list<int> testFt;
	std::cout << "All iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::list<int>::iterator it = testStd.begin();
	std::list<int>::iterator ite = testStd.end();
	ft::list<int>::iterator itm = testFt.begin();
	ft::list<int>::iterator item = testFt.end();
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.begin();
	itm = testFt.begin();
	while (ite != it) {
		ite--;
		std += *ite;
	}
	while (item != itm) {
		item--;
		ft += *item;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const iteratot list

void constIteratorTest(std::string &std, std::string &ft, int number) {
	std::list<int> testStd;
	ft::list<int> testFt;
	std::cout << "All const_iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::list<int>::const_iterator it = testStd.cbegin();
	std::list<int>::const_iterator ite = testStd.cend();
	ft::list<int>::const_iterator itm = testFt.cbegin();
	ft::list<int>::const_iterator item = testFt.cend();
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.cbegin();
	itm = testFt.cbegin();
	while (ite != it) {
		ite--;
		std += *ite;
	}
	while (item != itm) {
		item--;
		ft += *item;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Reverse iteratot list

void reverseIteratorTest(std::string &std, std::string &ft, int number) {
	std::list<int> testStd;
	ft::list<int> testFt;
	std::cout << "All reverse_iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::list<int>::reverse_iterator it = testStd.rbegin();
	std::list<int>::reverse_iterator ite = testStd.rend();
	ft::list<int>::reverse_iterator itm = testFt.rbegin();
	ft::list<int>::reverse_iterator item = testFt.rend();
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.rbegin();
	itm = testFt.rbegin();
	while (ite != it) {
		ite--;
		std += *ite;
	}
	while (item != itm) {
		item--;
		ft += *item;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const reverse iteratot list

void constReverseIteratorTest(std::string &std, std::string &ft, int number) {
	std::list<int> testStd;
	ft::list<int> testFt;
	std::cout << "All const_reverse_iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::list<int>::const_reverse_iterator it = testStd.crbegin();
	std::list<int>::const_reverse_iterator ite = testStd.crend();
	ft::list<int>::const_reverse_iterator itm = testFt.crbegin();
	ft::list<int>::const_reverse_iterator item = testFt.crend();
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.crbegin();
	itm = testFt.crbegin();
	while (ite != it) {
		ite--;
		std += *ite;
	}
	while (item != itm) {
		item--;
		ft += *item;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Capacity list

void capacityTests(std::string &std, std::string &ft) {
	std::cout << "All capacity test" << " ";
	std::list<int> testStd;
	ft::list<int> testFt;
	std += testStd.empty();
	ft += testFt.empty();
	std += testStd.size();
	ft += testFt.size();
	listPushFrontElem(testStd, testFt, 100);
	std += testStd.empty();
	ft += testFt.empty();
	std += testStd.size();
	ft += testFt.size();
	std += testStd.max_size();
	ft += testFt.max_size();
	std::list<float> testStdStr;
	ft::list<float> testFtStr;
	std += testStdStr.max_size();
	ft += testFtStr.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Element access list

void accessTest(std::string &std, std::string &ft) {
	std::cout << "Elemen access test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	int i = 0;
	while (i < 10) {
		listPushFrontElem(def, my, 2);
		std += def.front();
		std += def.back();
		ft += my.front();
		ft += my.back();
		i++;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignModTest(std::string &std, std::string &ft, int number) {
	std::cout << "Assign test" << " ";
	float i = rand();
	std::list<float> fstStd(number, i);
	ft::list<float> fstFt(number, i);
	float j = rand();
	while (j == i)
		j = rand();
	fstStd.assign(number, j);
	fstFt.assign(number, j);
	for (std::list<float>::iterator it = fstStd.begin(); it != fstStd.end(); it++) {
		if (*it != j) {
			std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
			std.clear();
			ft.clear();
			return ;
		}
		std += *it;
	}
	for (ft::list<float>::iterator it = fstFt.begin(); it != fstFt.end(); it++) {
		if (*it != j) {
			std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
			std.clear();
			ft.clear();
			return ;
		}
		ft += *it;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Modifiers list

void pushBackTest(std::string &std, std::string &ft, int number) {
	std::cout << "Push back test" << " ";
	std::list<std::string> stdLst;
	ft::list<std::string> ftLst;
	listPushBackElem(stdLst, ftLst, number);
	for (std::list<std::string>::iterator it = stdLst.begin(); it != stdLst.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = ftLst.begin(); it != ftLst.end(); it++)
		ft += *it;
	std += stdLst.size();
	ft += ftLst.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushFrontTest(std::string &std, std::string &ft, int number) {
	std::cout << "Push front test" << " ";
	std::list<std::string> stdLst;
	ft::list<std::string> ftLst;
	listPushFrontElem(stdLst, ftLst, number);
	for (std::list<std::string>::iterator it = stdLst.begin(); it != stdLst.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = ftLst.begin(); it != ftLst.end(); it++)
		ft += *it;
	std += stdLst.size();
	ft += ftLst.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popBackTest(std::string &std, std::string &ft, int number) {
	std::cout << "Pop back test" << " ";
	std::list<float> stdLst;
	ft::list<float> ftLst;
	listPushBackElem(stdLst, ftLst, number);
	std += stdLst.size();
	ft += ftLst.size();
	listPopBackElem(stdLst, ftLst, number);
	std += stdLst.size();
	ft += ftLst.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popFrontTest(std::string &std, std::string &ft, int number) {
	std::cout << "Pop front test" << " ";
	std::list<float> stdLst;
	ft::list<float> ftLst;
	listPushBackElem(stdLst, ftLst, number);
	std += stdLst.size();
	ft += ftLst.size();
	listPopFrontElem(stdLst, ftLst, number);
	std += stdLst.size();
	ft += ftLst.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void insertSinglPositionTest(std::string &std, std::string  &ft) {
	std::cout << "Insert singl position test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 5);
	def.insert(def.begin()++, 42);
	my.insert(my.begin()++, 42);
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void insertMultyPositionTest(std::string &std, std::string  &ft) {
	std::cout << "Insert multy position test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 5);
	def.insert(++def.begin(), 21, 42);
	my.insert(++my.begin(), 21, 42);
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void insertRangePosotionTest(std::string &std, std::string &ft) {
	std::cout << "Insert range position test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> test;
	for (int l = 0; l < 5; l++)
		test.push_back(l);
	listPushBackElem(def, my, 5);
	def.insert(++def.begin(), ++test.begin(), --(--test.end()));
	my.insert(++my.begin(), ++test.begin(), --(--test.end()));
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseSinglTest(std::string &std, std::string &ft) {
	std::cout << "Erase singl test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	std += *(def.erase(++def.begin()));
	ft += *(my.erase(++my.begin()));
	std += *(def.erase(--(--def.end())));
	ft += *(my.erase(--(--my.end())));
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseMultyTest(std::string &std, std::string &ft) {
	std::cout << "Erase multy test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	std::list<std::string>::iterator it = def.begin();
	std::list<std::string>::iterator ite = def.end();
	ft::list<std::string>::iterator itm = my.begin();
	ft::list<std::string>::iterator item = my.end();
	for (int i = 0; i < 20; i++) {
		it++;
		itm++;
		ite--;
		item--;
	}
	std += *(static_cast<void>(it), ite);
	ft += *(static_cast<void>(itm), item);
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapTest() {
	std::cout << "Swap test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> swapDef;
	ft::list<std::string> swapMy;
	std::list<std::string> checkDef;
	ft::list<std::string> checkMy;
	listPushBackElem(def, my, 5);
	listPushBackElem(swapDef, swapMy, 10);
	checkDef = def;
	checkMy = my;
	def.swap(swapDef);
	my.swap(swapMy);
	if (swapDef != checkDef && swapMy != checkMy) {
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
		return ;
	}
	checkDef = def;
	checkMy = my;
	swapDef.swap(def);
	swapMy.swap(my);
	if (swapDef != checkDef && swapMy != checkMy)
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
}

void resizeTestStr(std::string &std, std::string &ft) {
	std::cout << "Resize std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 10);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(5);
	my.resize(5);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(7, "hello");
	my.resize(7, "hello");
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(10);
	my.resize(10);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void resizeTestInt(std::string &std, std::string &ft) {
	std::cout << "Resize int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(5);
	my.resize(5);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(7, 100);
	my.resize(7, 100);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(10);
	my.resize(10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void resizeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Resize float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	listPushBackElem(def, my, 10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(5);
	my.resize(5);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(7, 100.2);
	my.resize(7, 100.2);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(10);
	my.resize(10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearTest(std::string &std, std::string &ft) {
	std::cout << "Clear test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.clear();
	my.clear();
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	listPushBackElem(def, my, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Operations list

void spliceTestEntireInt(std::string &std, std::string &ft) {
	std::cout << "Splice entire int test" << " ";
	std::list<int> defInt;
	ft::list<int> myInt;
	std::list<int> spliceInt;
	ft::list<int> mySpliceInt;
	listPushBackElem(defInt, myInt, 10);
	listPushBackElem(spliceInt, mySpliceInt, 4);
	std += defInt.size();
	ft += myInt.size();
	for (std::list<int>::iterator it = defInt.begin(); it != defInt.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = myInt.begin(); it != myInt.end(); it++)
		ft += *it;
	std += spliceInt.size();
	ft += mySpliceInt.size();
	for (std::list<int>::iterator it = spliceInt.begin(); it != spliceInt.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySpliceInt.begin(); it != mySpliceInt.end(); it++)
		ft += *it;
	defInt.splice(++defInt.begin(), spliceInt);
	myInt.splice(++myInt.begin(), mySpliceInt);
	std += defInt.size();
	ft += myInt.size();
	for (std::list<int>::iterator it = defInt.begin(); it != defInt.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = myInt.begin(); it != myInt.end(); it++)
		ft += *it;
	std += spliceInt.size();
	ft += mySpliceInt.size();
	for (std::list<int>::iterator it = spliceInt.begin(); it != spliceInt.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySpliceInt.begin(); it != mySpliceInt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestEntireFloat(std::string &std, std::string &ft) {
	std::cout << "Splice entire float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	std::list<float> splice;
	ft::list<float> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 4);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice);
	my.splice(++my.begin(), mySplice);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestEntireStr(std::string &std, std::string &ft) {
	std::cout << "Splice entire std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> splice;
	ft::list<std::string> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 4);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice);
	my.splice(++my.begin(), mySplice);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestSinglInt(std::string &std, std::string &ft) {
	std::cout << "Splice single int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> splice;
	ft::list<int> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<int>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin());
	my.splice(++my.begin(), mySplice, ++mySplice.begin());
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<int>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestSinglFloat(std::string &std, std::string &ft) {
	std::cout << "Splice single float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	std::list<float> splice;
	ft::list<float> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin());
	my.splice(++my.begin(), mySplice, ++mySplice.begin());
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestSinglStr(std::string &std, std::string &ft) {
	std::cout << "Splice single std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> splice;
	ft::list<std::string> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin());
	my.splice(++my.begin(), mySplice, ++mySplice.begin());
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestRangeInt(std::string &std, std::string &ft) {
	std::cout << "Splice range int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> splice;
	ft::list<int> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<int>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin(), --(--splice.end()));
	my.splice(++my.begin(), mySplice, ++mySplice.begin(), --(--mySplice.end()));
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<int>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestRangeFloat(std::string &std, std::string &ft) {
	std::cout << "Splice range float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	std::list<float> splice;
	ft::list<float> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin(), --(--splice.end()));
	my.splice(++my.begin(), mySplice, ++mySplice.begin(), --(--mySplice.end()));
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestRangeStr(std::string &std, std::string &ft) {
	std::cout << "Splice range std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> splice;
	ft::list<std::string> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin(), --(--splice.end()));
	my.splice(++my.begin(), mySplice, ++mySplice.begin(), --(--mySplice.end()));
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void removeTestInt(std::string &std, std::string &ft) {
	std::cout << "Remove int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	def.insert(++(++def.begin()), 42);
	my.insert(++(++my.begin()), 42);
	def.insert(++(++def.begin()), 42);
	my.insert(++(++my.begin()), 42);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove(42);
	my.remove(42);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove(21);
	my.remove(21);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void removeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Remove float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	listPushBackElem(def, my, 100);
	def.insert(++(++def.begin()), 42);
	my.insert(++(++my.begin()), 42);
	def.insert(++(++def.begin()), 42);
	my.insert(++(++my.begin()), 42);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove(42.21);
	my.remove(42.21);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove(21.42);
	my.remove(21.42);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void removeTestStr(std::string &std, std::string &ft) {
	std::cout << "Remove std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	def.insert(++(++def.begin()), "42");
	my.insert(++(++my.begin()), "42");
	def.insert(++(++def.begin()), "42");
	my.insert(++(++my.begin()), "42");
	def.insert(++(++def.begin()), "21");
	my.insert(++(++my.begin()), "21");
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove("42");
	my.remove("42");
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove("21");
	my.remove("21");
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void removeIfTest(std::string &std, std::string &ft) {
	std::cout << "Remove if test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 5);
	def.insert(++def.begin(), 9);
	my.insert(++my.begin(), 9);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove_if(singleDigit);
	my.remove_if(singleDigit);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove_if(isEven());
	my.remove_if(isEven());
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void uniqueTest(std::string &std, std::string &ft) {
	std::cout << "Unique test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.unique();
	my.unique();
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.unique(sameRemainderOfDivision);
	my.unique(sameRemainderOfDivision);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void mergeTestInt(std::string &std, std::string &ft) {
	std::cout << "Merge int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> mergDef;
	ft::list<int> mergMy;
	listPushBackElem(def, my, 10);
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	def.merge(mergDef);
	my.merge(mergMy);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	mergDef.merge(def, myComparison);
	mergMy.merge(my, myComparison);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void mergeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Merge float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	std::list<float> mergDef;
	ft::list<float> mergMy;
	listPushBackElem(def, my, 10);
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	def.merge(mergDef);
	my.merge(mergMy);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	mergDef.merge(def, myComparison);
	mergMy.merge(my, myComparison);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void mergeTestStr(std::string &std, std::string &ft) {
	std::cout << "Merge std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> mergDef;
	ft::list<std::string> mergMy;
	listPushBackElem(def, my, 10);
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	def.merge(mergDef);
	my.merge(mergMy);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sortTestInt(std::string &std, std::string &ft) {
	std::cout << "Sort int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort();
	my.sort();
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort(myComparison);
	my.sort(myComparison);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sortTestFloat(std::string &std, std::string &ft) {
	std::cout << "Sort float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort();
	my.sort();
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort(myComparison);
	my.sort(myComparison);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sortTestStd(std::string &std, std::string &ft) {
	std::cout << "Sort std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort();
	my.sort();
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reverseTestInt(std::string &std, std::string &ft) {
	std::cout << "Reverse int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.reverse();
	my.reverse();
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reverseTestFloat(std::string &std, std::string &ft) {
	std::cout << "Reverse float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.reverse();
	my.reverse();
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reverseTestStr(std::string &std, std::string &ft) {
	std::cout << "Reverse std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.reverse();
	my.reverse();
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Non member list

void equalTest(std::string &std, std::string &ft) {
	std::cout << "Equal int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestFloat(std::string &std, std::string &ft) {
	std::cout << "Equal float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 == defFloat);
	std += (defFloat == defFloat1);
	std += (defFloat == defFloat);
	std += (defFloat1 == defFloat1);
	ft += (myFloat1 == myFloat);
	ft += (myFloat == myFloat1);
	ft += (myFloat == myFloat);
	ft += (myFloat1 == myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestStr(std::string &std, std::string &ft) {
	std::cout << "Equal std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 == defStr);
	std += (defStr == defStr1);
	std += (defStr == defStr);
	std += (defStr1 == defStr1);
	ft += (myStr1 == myStr);
	ft += (myStr == myStr1);
	ft += (myStr == myStr);
	ft += (myStr1 == myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTest(std::string &std, std::string &ft) {
	std::cout << "Non equal int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestFloat(std::string &std, std::string &ft) {
	std::cout << "Non equal float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 != defFloat);
	std += (defFloat != defFloat1);
	std += (defFloat != defFloat);
	std += (defFloat1 != defFloat1);
	ft += (myFloat1 != myFloat);
	ft += (myFloat != myFloat1);
	ft += (myFloat != myFloat);
	ft += (myFloat1 != myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestStr(std::string &std, std::string &ft) {
	std::cout << "Non equal std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 != defStr);
	std += (defStr != defStr1);
	std += (defStr != defStr);
	std += (defStr1 != defStr1);
	ft += (myStr1 != myStr);
	ft += (myStr != myStr1);
	ft += (myStr != myStr);
	ft += (myStr1 != myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTest(std::string &std, std::string &ft) {
	std::cout << "Less int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def1);
	ft += (my < my1);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestFloat(std::string &std, std::string &ft) {
	std::cout << "Less float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 < defFloat);
	ft += (myFloat1 < myFloat);
	std += (defFloat < defFloat1);
	ft += (myFloat < myFloat1);
	std += (defFloat < defFloat);
	ft += (myFloat < myFloat);
	std += (defFloat1 < defFloat1);
	ft += (myFloat1 < myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestStr(std::string &std, std::string &ft) {
	std::cout << "Less std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> def1;
	ft::list<std::string> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def < def1);
	ft += (my < my1);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTest(std::string &std, std::string &ft) {
	std::cout << "Less or equal int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def <= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestFloat(std::string &std, std::string &ft) {
	std::cout << "Less or equal float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 <= defFloat);
	std += (defFloat <= defFloat1);
	std += (defFloat <= defFloat);
	std += (defFloat1 <= defFloat1);
	ft += (myFloat1 <= myFloat);
	ft += (myFloat <= myFloat1);
	ft += (myFloat <= myFloat);
	ft += (myFloat1 <= myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestStr(std::string &std, std::string &ft) {
	std::cout << "Less or equal std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 <= defStr);
	std += (defStr <= defStr1);
	std += (defStr <= defStr);
	std += (defStr1 <= defStr1);
	ft += (myStr1 <= myStr);
	ft += (myStr <= myStr1);
	ft += (myStr <= myStr);
	ft += (myStr1 <= myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTest(std::string &std, std::string &ft) {
	std::cout << "Greater int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 > def);
	std += (def > def1);
	std += (def > def);
	std += (def1 > def1);
	ft += (my1 > my);
	ft += (my > my1);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestFloat(std::string &std, std::string &ft) {
	std::cout << "Greater float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat > defFloat1);
	std += (defFloat1 > defFloat);
	std += (defFloat > defFloat);
	std += (defFloat1 > defFloat1);
	ft += (myFloat > myFloat1);
	ft += (myFloat1 > myFloat);
	ft += (myFloat > myFloat);
	ft += (myFloat1 > myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestStr(std::string &std, std::string &ft) {
	std::cout << "Greater std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr > defStr1);
	std += (defStr1 > defStr);
	std += (defStr > defStr);
	std += (defStr1 > defStr1);
	ft += (myStr > myStr1);
	ft += (myStr1 > myStr);
	ft += (myStr > myStr);
	ft += (myStr1 > myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTest(std::string &std, std::string &ft) {
	std::cout << "Greater or equal int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestFloat(std::string &std, std::string &ft) {
	std::cout << "Greater or equal float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat >= defFloat1);
	std += (defFloat1 >= defFloat);
	std += (defFloat >= defFloat);
	std += (defFloat1 >= defFloat1);
	ft += (myFloat >= myFloat1);
	ft += (myFloat1 >= myFloat);
	ft += (myFloat >= myFloat);
	ft += (myFloat1 >= myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestStr(std::string &std, std::string &ft) {
	std::cout << "Greater or equal std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr >= defStr1);
	std += (defStr1 >= defStr);
	std += (defStr >= defStr);
	std += (defStr1 >= defStr1);
	ft += (myStr >= myStr1);
	ft += (myStr1 >= myStr);
	ft += (myStr >= myStr);
	ft += (myStr1 >= myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTest(std::string &std, std::string &ft) {
	std::cout << "Non member swap int test" << " ";
	std::list<int> def;
	std::list<int> toSwap;
	ft::list<int> my;
	ft::list<int> mySwap;
	listPushBackElem(def, my, 10);
	listPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<int>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<int>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestFloat(std::string &std, std::string &ft) {
	std::cout << "Non member swap float test" << " ";
	std::list<float> def;
	std::list<float> toSwap;
	ft::list<float> my;
	ft::list<float> mySwap;
	listPushBackElem(def, my, 10);
	listPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<float>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<float>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestStr(std::string &std, std::string &ft) {
	std::cout << "Non member swap std::string test" << " ";
	std::list<std::string> def;
	std::list<std::string> toSwap;
	ft::list<std::string> my;
	ft::list<std::string> mySwap;
	listPushBackElem(def, my, 10);
	listPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<std::string>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<std::string>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - List
void  testList() {
	std::cout << "                            CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTest(std, ft);
	fillCnstTest(std, ft, 1000);
	rangeCnstTest(std, ft, 1000);
	std::cout << "                            ASSIGN" << std::endl;
	assignTest(std, ft, 1000);
	assignRangeTestList(std, ft);
	assignRangeTestListFloat(std, ft);
	assignRangeTestListStr(std, ft);
	std::cout << "                            ITERATORS" << std::endl;
	iteratorTest(std, ft, 1000);
	constIteratorTest(std, ft, 1000);
	reverseIteratorTest(std, ft, 1000);
	constReverseIteratorTest(std, ft, 1000);
	std::cout << "                            CAPACITY" << std::endl;
	capacityTests(std, ft);
	std::cout << "                            ELEMENT ACCESS" << std::endl;
	accessTest(std, ft);
	std::cout << "                            MODIFIERS" << std::endl;
	assignModTest(std, ft, 1000);
	pushBackTest(std, ft, 1000);
	pushFrontTest(std, ft, 1000);
	popBackTest(std, ft, 1000);
	popFrontTest(std, ft, 1000);
	insertSinglPositionTest(std, ft);
	insertMultyPositionTest(std, ft);
	insertRangePosotionTest(std, ft);
	eraseSinglTest(std, ft);
	eraseMultyTest(std, ft);
	swapTest();
	resizeTestStr(std, ft);
	resizeTestInt(std, ft);
	resizeTestFloat(std, ft);
	clearTest(std, ft);
	std::cout << "                            OPERATIONS" << std::endl;
	spliceTestEntireInt(std, ft);
	spliceTestEntireFloat(std, ft);
	spliceTestEntireStr(std, ft);
	spliceTestSinglInt(std, ft);
	spliceTestSinglFloat(std, ft);
	spliceTestSinglStr(std, ft);
	spliceTestRangeInt(std, ft);
	spliceTestRangeFloat(std, ft);
	spliceTestRangeStr(std, ft);
	removeTestInt(std, ft);
	removeTestFloat(std, ft);
	removeTestStr(std, ft);
	removeIfTest(std, ft);
	uniqueTest(std, ft);

	mergeTestInt(std, ft);
	mergeTestFloat(std, ft);
	mergeTestStr(std, ft);
	sortTestInt(std, ft);
	sortTestFloat(std, ft);
	sortTestStd(std, ft);
	reverseTestInt(std, ft);
	reverseTestFloat(std, ft);
	reverseTestStr(std, ft);
	std::cout << "                            NON-MEMBER FUNCTION OVERLOADS" << std::endl;
	equalTest(std, ft);
	equalTestFloat(std, ft);
	equalTestStr(std, ft);
	nonEqualTest(std, ft);
	nonEqualTestFloat(std, ft);
	nonEqualTestStr(std, ft);
	lessTest(std, ft);
	lessTestFloat(std, ft);
	lessTestStr(std, ft);
	lessOrEqualTest(std, ft);
	lessOrEqualTestFloat(std, ft);
	lessOrEqualTestStr(std, ft);
	greaterTest(std, ft);
	greaterTestFloat(std, ft);
	greaterTestStr(std, ft);
	greaterOrEqualTest(std, ft);
	greaterOrEqualTestFloat(std, ft);
	greaterOrEqualTestStr(std, ft);
	swapNonMemberTest(std, ft);
	swapNonMemberTestFloat(std, ft);
	swapNonMemberTestStr(std, ft);
}

//MARK: - Defoult constructor vector

void defaultCnstTestVector(std::string &std, std::string &ft) {
	std::cout << "Default constructor int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Default constructor float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Default constructor std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Fill constructor vector

void fillCnstTestVector(std::string &std, std::string &ft) {
	std::cout << "Fill constructor int test" << " ";
	std::vector<int> def(4, 100);
	ft::vector<int> my(4, 100);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillCnstTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Fill constructor float test" << " ";
	std::vector<float> def(4, 100.42);
	ft::vector<float> my(4, 100.42);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillCnstTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Fill constructor std::string test" << " ";
	std::string set;
	set += "100";
	std::vector<std::string> def(4, set);
	ft::vector<std::string> my(4, set);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Range constructor vector

void rangeCnstTestVector(std::string &std, std::string &ft) {
	std::cout << "Range constructor int test" << " ";
	std::vector<int> test;
	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::vector<int> def(++test.begin(), --(--test.end()));
	ft::vector<int> my(++test.begin(), --(--test.end()));
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Range constructor float test" << " ";
	std::vector<float> test;
	for (int i = 0; i < 10; i++)
		test.push_back(i + 0.42);
	std::vector<float> def(++test.begin(), --(--test.end()));
	ft::vector<float> my(++test.begin(), --(--test.end()));
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Range constructor std::string test" << " ";
	std::vector<std::string> test;
	std::string chr;
	for (int i = 0; i < 10; i++) {
		chr += i;
		test.push_back(chr);
		chr.clear();
	}
	std::vector<std::string> def(++test.begin(), test.end());
	ft::vector<std::string> my(++test.begin(), test.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Copy constructor vector

void copyCnstTestVector(std::string &std, std::string &ft) {
	std::cout << "Copy constructor int test" << " ";
	std::vector<int> test;
	ft::vector<int> test1;
	for (int i = 0; i < 10; i++) {
		test.push_back(i);
		test1.push_back(i);
	}
	std::vector<int> def(test);
	ft::vector<int> my(test1);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void copyCnstTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Copy constructor float test" << " ";
	std::vector<float> test;
	ft::vector<float> test1;
	for (int i = 0; i < 10; i++) {
		test.push_back(i + 0.42);
		test1.push_back(i + 0.42);
	}
	std::vector<float> def(test);
	ft::vector<float> my(test1);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void copyCnstTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Copy constructor std::string test" << " ";
	std::vector<std::string> test;
	ft::vector<std::string> test1;
	std::string chr;
	for (int i = 0; i < 10; i++) {
		chr += rand();
		test.push_back(chr);
		test1.push_back(chr);
		chr.clear();
	}
	std::vector<std::string> def(test);
	ft::vector<std::string> my(test1);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Assignation vector

void assignTestVector(std::string &std, std::string &ft) {
	std::cout << "Assign int test" << " ";
	std::vector<int> def;
	std::vector<int> toAssign;
	ft::vector<int> my;
	ft::vector<int> myAssign;
	for (int i = 0; i < 10; i++) {
		toAssign.push_back(i);
		myAssign.push_back(i);
	}
	def = toAssign;
	my = myAssign;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Assign float test" << " ";
	std::vector<float> def;
	std::vector<float> toAssign;
	ft::vector<float> my;
	ft::vector<float> myAssign;
	for (int i = 0; i < 10; i++) {
		toAssign.push_back(i + 0.42);
		myAssign.push_back(i + 0.42);
	}
	def = toAssign;
	my = myAssign;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Assign std::string test" << " ";
	std::vector<std::string> def;
	std::vector<std::string> toAssign;
	ft::vector<std::string> my;
	ft::vector<std::string> myAssign;
	std::string chr;
	for (int i = 0; i < 10; i++) {
		chr += rand();
		toAssign.push_back(chr);
		myAssign.push_back(chr);
		chr.clear();
	}
	def = toAssign;
	my = myAssign;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Iterator vector

void iteratorTestVector(std::string &std, std::string &ft, int number) {
	std::vector<int> testStd;
	ft::vector<int> testFt;
	std::cout << "All iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::vector<int>::iterator it = testStd.begin();
	std::vector<int>::iterator ite = testStd.end();
	ft::vector<int>::iterator itm = testFt.begin();
	ft::vector<int>::iterator item = testFt.end();
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.begin();
	itm = testFt.begin();
	ite--;
	item--;
	while (ite != it) {
		std += *ite;
		ite--;
	}
	while (item != itm) {
		ft += *item;
		item--;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const iterator vector

void constIteratorTestVector(std::string &std, std::string &ft, int number) {
	std::vector<int> testStd;
	ft::vector<int> testFt;
	std::cout << "All const_iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::vector<int>::const_iterator it = testStd.cbegin();
	std::vector<int>::const_iterator ite = testStd.cend();
	ft::vector<int>::const_iterator itm = testFt.cbegin();
	ft::vector<int>::const_iterator item = testFt.cend();
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.cbegin();
	itm = testFt.cbegin();
	ite--;
	item--;
	while (ite != it) {
		std += *ite;
		ite--;
	}
	while (item != itm) {
		ft += *item;
		item--;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Reverse iterator vector

void reverseIteratorTestVector(std::string &std, std::string &ft, int number) {
	std::vector<int> testStd;
	ft::vector<int> testFt;
	std::cout << "All reverse_iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::vector<int>::reverse_iterator it = testStd.rbegin();
	std::vector<int>::reverse_iterator ite = testStd.rend();
	ft::vector<int>::reverse_iterator itm = testFt.rbegin();
	ft::vector<int>::reverse_iterator item = testFt.rend();
	it++;
	itm++;
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.rbegin();
	itm = testFt.rbegin();
	ite--;
	item--;
	while (ite != it) {
		std += *ite;
		ite--;
	}
	while (item != itm) {
		ft += *item;
		item--;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const reverse iterator vector

void constReverseIteratorTestVector(std::string &std, std::string &ft, int number) {
	std::vector<int> testStd;
	ft::vector<int> testFt;
	std::cout << "All const_reverse_iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::vector<int>::const_reverse_iterator it = testStd.crbegin();
	std::vector<int>::const_reverse_iterator ite = testStd.crend();
	ft::vector<int>::const_reverse_iterator itm = testFt.crbegin();
	ft::vector<int>::const_reverse_iterator item = testFt.crend();
	it++;
	itm++;
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.crbegin();
	itm = testFt.crbegin();
	ite--;
	item--;
	while (ite != it) {
		std += *ite;
		ite--;
	}
	while (item != itm) {
		ft += *item;
		item--;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Size vector

void sizeTest(std::string &std, std::string &ft) {
	std::cout << "Size int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Size float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Max size vector

void maxSizeTest(std::string &std, std::string &ft) {
	std::cout << "Max size int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1000);
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void maxSizeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Max size float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1000);
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void maxSizeTestStr(std::string &std, std::string &ft) {
	std::cout << "Max size std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1000);
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Resize vector

void resizeTestIntVector(std::string &std, std::string &ft) {
	std::cout << "Resize int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.resize(80);
	my.resize(80);
	VectorFillStr(def, my, std, ft);
	def.resize(90);
	my.resize(90);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void resizeTestFloatVector(std::string &std, std::string &ft) {
	std::cout << "Resize float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.resize(80);
	my.resize(80);
	VectorFillStr(def, my, std, ft);
	def.resize(90);
	my.resize(90);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void resizeTestStrVector(std::string &std, std::string &ft) {
	std::cout << "Resize std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.resize(80);
	my.resize(80);
	VectorFillStr(def, my, std, ft);
	def.resize(90);
	my.resize(90);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Capacity vector

void capacityTestVector(std::string &std, std::string &ft) {
	std::cout << "Capacity int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 1);
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void capacityTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Capacity float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 1);
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void capacityTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Capacity std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 1);
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Empty vector

void emptyVectorTest(std::string &std, std::string &ft) {
	std::cout << "Empty int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std += def.empty();
	ft += my.empty();
	VectorPushBackElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Empty float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	std += def.empty();
	ft += my.empty();
	VectorPushBackElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Empty std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std += def.empty();
	ft += my.empty();
	VectorPushBackElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Reserve vector

void reserveVectorTest(std::string &std, std::string &ft) {
	std::cout << "Reserve int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(500);
	my.reserve(500);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(1);
	my.reserve(1);
	std += def.capacity();
	ft += my.capacity();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reserveVectorFloatTest(std::string &std, std::string &ft) {
	std::cout << "Reserve float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(500);
	my.reserve(500);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(1);
	my.reserve(1);
	std += def.capacity();
	ft += my.capacity();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reserveVectorStrTest(std::string &std, std::string &ft) {
	std::cout << "Reserve std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(500);
	my.reserve(500);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(1);
	my.reserve(1);
	std += def.capacity();
	ft += my.capacity();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Operator [] vector

void squareBracketsTest(std::string &std, std::string &ft) {
	std::cout << "Operator [] int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	std += def[50];
	ft += my[50];
	std += def[20];
	ft += my[20];
	std += def[10];
	ft += my[10];
	std += def[90];
	ft += my[90];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void squareBracketsTestFloat(std::string &std, std::string &ft) {
	std::cout << "Operator [] float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	std += def[50];
	ft += my[50];
	std += def[20];
	ft += my[20];
	std += def[10];
	ft += my[10];
	std += def[90];
	ft += my[90];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void squareBracketsTestStr(std::string &std, std::string &ft) {
	std::cout << "Operator [] std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	std += def[50];
	ft += my[50];
	std += def[20];
	ft += my[20];
	std += def[10];
	ft += my[10];
	std += def[90];
	ft += my[90];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - At vector

void atTest(std::string &std, std::string &ft) {
	std::cout << "At int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	std += def.at(50);
	ft += my.at(50);
	std += def.at(20);
	ft += my.at(20);
	std += def.at(10);
	ft += my.at(10);
	std += def.at(90);
	ft += my.at(90);
	def.at(20) = 1;
	my.at(20) = 1;
	std += def.at(20);
	ft += my.at(20);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void atTestFloat(std::string &std, std::string &ft) {
	std::cout << "At float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	std += def.at(50);
	ft += my.at(50);
	std += def.at(20);
	ft += my.at(20);
	std += def.at(10);
	ft += my.at(10);
	std += def.at(90);
	ft += my.at(90);
	def.at(20) = 1;
	my.at(20) = 1;
	std += def.at(20);
	ft += my.at(20);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void atTestStr(std::string &std, std::string &ft) {
	std::cout << "At std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	std += def.at(50);
	ft += my.at(50);
	std += def.at(20);
	ft += my.at(20);
	std += def.at(10);
	ft += my.at(10);
	std += def.at(90);
	ft += my.at(90);
	def.at(20) = "1";
	my.at(20) = "1";
	std += def.at(20);
	ft += my.at(20);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Front vector

void frontTest(std::string &std, std::string &ft) {
	std::cout << "Front int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 10);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void frontTestFloat(std::string &std, std::string &ft) {
	std::cout << "Front float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 10);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void frontTestStr(std::string &std, std::string &ft) {
	std::cout << "Front std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 10);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Back vector

void backTest(std::string &std, std::string &ft) {
	std::cout << "Back int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 10);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void backTestFloat(std::string &std, std::string &ft) {
	std::cout << "Back float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 10);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void backTestStr(std::string &std, std::string &ft) {
	std::cout << "Back std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 10);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Range assign vector

void assignRangeTest(std::string &std, std::string &ft) {
	std::cout << "Assign range int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> toAssign;
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 8; i++)
		toAssign.push_back(rand());
	def.assign(++(++toAssign.begin()), --toAssign.end());
	my.assign(++(++toAssign.begin()), --toAssign.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Assign range float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	std::vector<float> toAssign;
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 10; i++)
		toAssign.push_back(rand());
	def.assign(++(++toAssign.begin()), --toAssign.end());
	my.assign(++(++toAssign.begin()), --toAssign.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestStr(std::string &std, std::string &ft) {
	std::cout << "Assign range std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std::vector<std::string> toAssign;
	std::string test;
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 10; i++) {
		test += rand();
		toAssign.push_back(test);
		test.clear();
	}
	def.assign(++(++toAssign.begin()), --toAssign.end());
	my.assign(++(++toAssign.begin()), --toAssign.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Fill assign vector

void assignFillTest(std::string &std, std::string &ft) {
	std::cout << "Assign fill int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	def.assign(10, 42);
	my.assign(10, 42);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignFillTestFloat(std::string &std, std::string &ft) {
	std::cout << "Assign fill float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	def.assign(10, 42.21);
	my.assign(10, 42.21);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignFillTestStr(std::string &std, std::string &ft) {
	std::cout << "Assign fill std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	def.assign(10, "42");
	my.assign(10, "42");
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Push back vector

void pushBackVectorTest(std::string &std, std::string &ft) {
	std::cout << "Push back int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushBackVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Push back float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushBackVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Push back std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Pop back vector

void popBackVectorTest(std::string &std, std::string &ft) {
	std::cout << "Pop back int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 20; i++) {
		def.pop_back();
		my.pop_back();
		VectorFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popBackVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Pop back float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 20; i++) {
		def.pop_back();
		my.pop_back();
		VectorFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popBackVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Pop back std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 20; i++) {
		def.pop_back();
		my.pop_back();
		VectorFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Insert vector

void singleInsertVectorTest(std::string &std, std::string &ft) {
	std::cout << "Single insert int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 10);
	std::vector<int>::iterator it = ++def.begin();
	ft::vector<int>::iterator mit = ++my.begin();
	it = def.insert(it, 42);
	mit = my.insert(mit, 42);
	VectorFillStr(def, my, std, ft);
	if (std == ft && *it == *mit)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleInsertVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Single insert float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 10);
	std::vector<float>::iterator it = ++def.begin();
	ft::vector<float>::iterator mit = ++my.begin();
	it = def.insert(it, 42.21);
	mit = my.insert(mit, 42.21);
	VectorFillStr(def, my, std, ft);
	if (std == ft && *it == *mit)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleInsertVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Single insert std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 10);
	std::vector<std::string>::iterator it = ++def.begin();
	ft::vector<std::string>::iterator mit = ++my.begin();
	std::string test;
	test += "42";
	it = def.insert(it, test);
	mit = my.insert(mit, test);
	VectorFillStr(def, my, std, ft);
	if (std == ft && *it == *mit)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillInsertVectorTest(std::string &std, std::string &ft) {
	std::cout << "Fill insert int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 10);
	def.insert(def.begin() + 5, 5, 21);
	my.insert(my.begin() + 5, 5, 21);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillInsertVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Fill insert float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 10);
	def.insert(def.begin() + 5, 5, 21.42);
	my.insert(my.begin() + 5, 5, 21.42);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillInsertVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Fill insert std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 10);
	def.insert(def.begin() + 5, 5, "21");
	my.insert(my.begin() + 5, 5, "21");
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertVectorTest(std::string &std, std::string &ft) {
	std::cout << "Range insert int test" << " ";
	std::vector<int> test;
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	for (int i = 0; i < 10; i++)
		test.push_back(rand());
	def.insert(def.begin() + 10, test.begin(), test.end());
	my.insert(my.begin() + 10, test.begin(), test.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Range insert float test" << " ";
	std::vector<float> test;
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	for (int i = 0; i < 10; i++)
		test.push_back(rand());
	def.insert(def.begin() + 10, test.begin(), test.end());
	my.insert(my.begin() + 10, test.begin(), test.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Range insert std::string test" << " ";
	std::vector<std::string> test;
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std::string str;
	VectorPushBackElem(def, my, 100);
	for (int i = 0; i < 10; i++) {
		str += rand();
		test.push_back(str);
		str.clear();
	}
	def.insert(def.begin() + 10, test.begin(), test.end());
	my.insert(my.begin() + 10, test.begin(), test.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Erase vector

void singleEraseVectorTest(std::string &std, std::string &ft) {
	std::cout << "Single erase int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40);
	my.erase(my.begin() + 40);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleEraseVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Single erase float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40);
	my.erase(my.begin() + 40);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleEraseVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Single erase std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40);
	my.erase(my.begin() + 40);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeEraseVectorTest(std::string &std, std::string &ft) {
	std::cout << "Range erase int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40, def.begin() + 60);
	my.erase(my.begin() + 40, my.begin() + 60);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeEraseVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Range erase float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40, def.begin() + 60);
	my.erase(my.begin() + 40, my.begin() + 60);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeEraseVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Range erase std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40, def.begin() + 60);
	my.erase(my.begin() + 40, my.begin() + 60);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Swap vector

void swapVectorTest(std::string &std, std::string &ft) {
	std::cout << "Swap int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> toSwap;
	ft::vector<int> mySwap;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(toSwap, mySwap, 50);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Swap float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	std::vector<float> toSwap;
	ft::vector<float> mySwap;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(toSwap, mySwap, 50);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Swap std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std::vector<std::string> toSwap;
	ft::vector<std::string> mySwap;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(toSwap, mySwap, 50);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Clear vector

void clearVectorTest(std::string &std, std::string &ft) {
	std::cout << "Clear int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Clear float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Clear std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Non member vector

void equalTestVector(std::string &std, std::string &ft) {
	std::cout << "Equal int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Equal float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 == defFloat);
	std += (defFloat == defFloat1);
	std += (defFloat == defFloat);
	std += (defFloat1 == defFloat1);
	ft += (myFloat1 == myFloat);
	ft += (myFloat == myFloat1);
	ft += (myFloat == myFloat);
	ft += (myFloat1 == myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Equal std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 == defStr);
	std += (defStr == defStr1);
	std += (defStr == defStr);
	std += (defStr1 == defStr1);
	ft += (myStr1 == myStr);
	ft += (myStr == myStr1);
	ft += (myStr == myStr);
	ft += (myStr1 == myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestVector(std::string &std, std::string &ft) {
	std::cout << "Non equal int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Non equal float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 != defFloat);
	std += (defFloat != defFloat1);
	std += (defFloat != defFloat);
	std += (defFloat1 != defFloat1);
	ft += (myFloat1 != myFloat);
	ft += (myFloat != myFloat1);
	ft += (myFloat != myFloat);
	ft += (myFloat1 != myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Non equal std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 != defStr);
	std += (defStr != defStr1);
	std += (defStr != defStr);
	std += (defStr1 != defStr1);
	ft += (myStr1 != myStr);
	ft += (myStr != myStr1);
	ft += (myStr != myStr);
	ft += (myStr1 != myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestVector(std::string &std, std::string &ft) {
	std::cout << "Less int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def1);
	ft += (my < my1);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Less float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 < defFloat);
	ft += (myFloat1 < myFloat);
	std += (defFloat < defFloat1);
	ft += (myFloat < myFloat1);
	std += (defFloat < defFloat);
	ft += (myFloat < myFloat);
	std += (defFloat1 < defFloat1);
	ft += (myFloat1 < myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Less std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std::vector<std::string> def1;
	ft::vector<std::string> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
	std += (def < def1);
	ft += (my < my1);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestVector(std::string &std, std::string &ft) {
	std::cout << "Less or equal int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def <= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Less or equal float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 <= defFloat);
	std += (defFloat <= defFloat1);
	std += (defFloat <= defFloat);
	std += (defFloat1 <= defFloat1);
	ft += (myFloat1 <= myFloat);
	ft += (myFloat <= myFloat1);
	ft += (myFloat <= myFloat);
	ft += (myFloat1 <= myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Less or equal std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 <= defStr);
	std += (defStr <= defStr1);
	std += (defStr <= defStr);
	std += (defStr1 <= defStr1);
	ft += (myStr1 <= myStr);
	ft += (myStr <= myStr1);
	ft += (myStr <= myStr);
	ft += (myStr1 <= myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestVector(std::string &std, std::string &ft) {
	std::cout << "Greater int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
	std += (def1 > def);
	std += (def > def1);
	std += (def > def);
	std += (def1 > def1);
	ft += (my1 > my);
	ft += (my > my1);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Greater float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat > defFloat1);
	std += (defFloat1 > defFloat);
	std += (defFloat > defFloat);
	std += (defFloat1 > defFloat1);
	ft += (myFloat > myFloat1);
	ft += (myFloat1 > myFloat);
	ft += (myFloat > myFloat);
	ft += (myFloat1 > myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Greater std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
	std += (defStr > defStr1);
	std += (defStr1 > defStr);
	std += (defStr > defStr);
	std += (defStr1 > defStr1);
	ft += (myStr > myStr1);
	ft += (myStr1 > myStr);
	ft += (myStr > myStr);
	ft += (myStr1 > myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestVector(std::string &std, std::string &ft) {
	std::cout << "Greater or equal int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Greater or equal float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat >= defFloat1);
	std += (defFloat1 >= defFloat);
	std += (defFloat >= defFloat);
	std += (defFloat1 >= defFloat1);
	ft += (myFloat >= myFloat1);
	ft += (myFloat1 >= myFloat);
	ft += (myFloat >= myFloat);
	ft += (myFloat1 >= myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Greater or equal std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
	std += (defStr >= defStr1);
	std += (defStr1 >= defStr);
	std += (defStr >= defStr);
	std += (defStr1 >= defStr1);
	ft += (myStr >= myStr1);
	ft += (myStr1 >= myStr);
	ft += (myStr >= myStr);
	ft += (myStr1 >= myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestVector(std::string &std, std::string &ft) {
	std::cout << "Non member swap int test" << " ";
	std::vector<int> def;
	std::vector<int> toSwap;
	ft::vector<int> my;
	ft::vector<int> mySwap;
	VectorPushBackElem(def, my, 10);
	VectorPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::vector<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<int>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<int>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::vector<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<int>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<int>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Non member swap float test" << " ";
	std::vector<float> def;
	std::vector<float> toSwap;
	ft::vector<float> my;
	ft::vector<float> mySwap;
	VectorPushBackElem(def, my, 10);
	VectorPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::vector<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<float>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<float>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::vector<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<float>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<float>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Non member swap std::string test" << " ";
	std::vector<std::string> def;
	std::vector<std::string> toSwap;
	ft::vector<std::string> my;
	ft::vector<std::string> mySwap;
	VectorPushBackElem(def, my, 10);
	VectorPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::vector<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<std::string>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<std::string>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::vector<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<std::string>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<std::string>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Vector

void testVector() {
	std::cout << "                            CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTestVector(std, ft);
	defaultCnstTestVectorFloat(std, ft);
	defaultCnstTestVectorStr(std, ft);
	fillCnstTestVector(std, ft);
	fillCnstTestVectorFloat(std, ft);
	fillCnstTestVectorStr(std, ft);
	rangeCnstTestVector(std, ft);
	rangeCnstTestVectorFloat(std, ft);
	rangeCnstTestVectorStr(std, ft);
	copyCnstTestVector(std, ft);
	copyCnstTestVectorFloat(std, ft);
	copyCnstTestVectorStr(std, ft);
	std::cout << "                            ASSIGNATION" << std::endl;
	assignTestVector(std, ft);
	assignTestVectorFloat(std, ft);
	assignTestVectorStr(std, ft);
	std::cout << "                            ITERATORS" << std::endl;
	iteratorTestVector(std, ft, 1000);
	constIteratorTestVector(std, ft, 1000);
	reverseIteratorTestVector(std, ft, 10);
	constReverseIteratorTestVector(std, ft, 10);
	std::cout << "                            CAPACITY" << std::endl;
	sizeTest(std, ft);
	sizeTestFloat(std, ft);
	sizeTestStr(std, ft);
	maxSizeTest(std, ft);
	maxSizeTestFloat(std, ft);
	maxSizeTestStr(std, ft);
	resizeTestIntVector(std, ft);
	resizeTestFloatVector(std, ft);
	resizeTestStrVector(std, ft);
	capacityTestVector(std, ft);
	capacityTestVectorFloat(std, ft);
	capacityTestVectorStr(std, ft);
	emptyVectorTest(std, ft);
	emptyVectorTestFloat(std, ft);
	emptyVectorTestStr(std, ft);
	reserveVectorTest(std, ft);
	reserveVectorFloatTest(std, ft);
	reserveVectorStrTest(std, ft);
	std::cout << "                            ELEMENT ACCESS" << std::endl;
	squareBracketsTest(std, ft);
	squareBracketsTestFloat(std, ft);
	squareBracketsTestStr(std, ft);
	atTest(std, ft);
	atTestFloat(std, ft);
	atTestStr(std, ft);
	frontTest(std, ft);
	frontTestFloat(std, ft);
	frontTestStr(std, ft);
	backTest(std, ft);
	backTestFloat(std, ft);
	backTestStr(std, ft);
	std::cout << "                            MODIFIERS" << std::endl;
	assignRangeTest(std, ft);
	assignRangeTestFloat(std, ft);
	assignRangeTestStr(std, ft);
	assignFillTest(std, ft);
	assignFillTestFloat(std, ft);
	assignFillTestStr(std, ft);
	pushBackVectorTest(std, ft);
	pushBackVectorTestFloat(std, ft);
	pushBackVectorTestStr(std, ft);
	popBackVectorTest(std, ft);
	popBackVectorTestFloat(std, ft);
	popBackVectorTestStr(std, ft);
	singleInsertVectorTest(std, ft);
	singleInsertVectorTestFloat(std, ft);
	singleInsertVectorTestStr(std, ft);
	fillInsertVectorTest(std, ft);
	fillInsertVectorTestFloat(std, ft);
	fillInsertVectorTestStr(std, ft);
	rangeInsertVectorTest(std, ft);
	rangeInsertVectorTestFloat(std, ft);
	rangeInsertVectorTestStr(std, ft);
	singleEraseVectorTest(std, ft);
	singleEraseVectorTestFloat(std, ft);
	singleEraseVectorTestStr(std, ft);
	rangeEraseVectorTest(std, ft);
	rangeEraseVectorTestFloat(std, ft);
	rangeEraseVectorTestStr(std, ft);
	swapVectorTest(std, ft);
	swapVectorTestFloat(std, ft);
	swapVectorTestStr(std, ft);
	clearVectorTest(std, ft);
	clearVectorTestFloat(std, ft);
	clearVectorTestStr(std, ft);
	std::cout << "                            NON MEMBER FUNCTIONS OVERLOADS" << std::endl;
	equalTestVector(std, ft);
	equalTestVectorFloat(std, ft);
	equalTestVectorStr(std, ft);
	nonEqualTestVector(std, ft);
	nonEqualTestVectorFloat(std, ft);
	nonEqualTestVectorStr(std, ft);
	lessTestVector(std, ft);
	lessTestVectorFloat(std, ft);
	lessTestVectorStr(std, ft);
	lessOrEqualTestVector(std, ft);
	lessOrEqualTestVectorFloat(std, ft);
	lessOrEqualTestVectorStr(std, ft);
	greaterTestVector(std, ft);
	greaterTestVectorFloat(std, ft);
	greaterTestVectorStr(std, ft);
	greaterOrEqualTestVector(std, ft);
	greaterOrEqualTestVectorFloat(std, ft);
	greaterOrEqualTestVectorStr(std, ft);
	swapNonMemberTestVector(std, ft);
	swapNonMemberTestVectorFloat(std, ft);
	swapNonMemberTestVectorStr(std, ft);
}

//MARK: - Default constructor map

void defaultCnstTestMap(std::string &std, std::string &ft) {
	std::cout << "Default constructor int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Default constructor float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Default constructor std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Range constructor map

void rangeCnstTestMap(std::string &std, std::string &ft) {
	std::cout << "Range constructor int test" << " ";
	std::map<int, int> test;
	for (int i = 0; i < 100; i++) {
		std::pair<int, int> res(rand(), rand());
		test.insert(res);
	}
	std::map<int, int> def(++test.begin(), --test.end());
	ft::map<int, int> my(++test.begin(), --test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Range constructor float test" << " ";
	std::map<float, float> test;
	for (int i = 0; i < 100; i++) {
		std::pair<float, float> res(rand(), rand());
		test.insert(res);
	}
	std::map<float, float> def(++test.begin(), --test.end());
	ft::map<float, float> my(++test.begin(), --test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Range constructor std::string test" << " ";
	std::map<std::string, std::string> test;
	std::string key;
	std::string value;
	for (int i = 0; i < 100; i++) {
		key += rand();
		value += rand();
		std::pair<std::string, std::string> res(key, value);
		test.insert(res);
	}
	std::map<std::string, std::string> def(++test.begin(), --test.end());
	ft::map<std::string, std::string> my(++test.begin(), --test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Copy constructor map

void copyCnstTestMap(std::string &std, std::string &ft) {
	std::cout << "Copy constructor int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void copyCnstTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Copy constructor float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void copyCnstTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Copy constructor std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Assignation map

void assignTestMap(std::string &std, std::string &ft) {
	std::cout << "Assignation int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std::map<int, int> test;
	ft::map<int, int> myTest;
	mapInsertElem(test, myTest, 100);
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	def = test;
	my = myTest;
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Assignation float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std::map<float, float> test;
	ft::map<float, float> myTest;
	mapInsertElem(test, myTest, 100);
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	def = test;
	my = myTest;
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Assignation std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std::map<std::string, std::string> test;
	ft::map<std::string, std::string> myTest;
	mapInsertElem(test, myTest, 100);
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	def = test;
	my = myTest;
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Iterator map

void iteratorTestMap(std::string &std, std::string &ft, int number) {
	std::map<int,int> testStd;
	ft::map<int,int> testFt;
	std::cout << "All iterator test" << " ";
	for (int i = 0; i < number; i++) {
		std::pair<int, int> res(rand(), rand());
		testStd.insert(res);
		testFt.insert(res);
	}
	std::map<int,int>::iterator it = testStd.begin();
	std::map<int,int>::iterator ite = testStd.end();
	ft::map<int,int>::iterator itm = testFt.begin();
	ft::map<int,int>::iterator item = testFt.end();
	while (it != ite) {
		std += it->first;
		std += it->second;
		it++;
	}
	while (itm != item) {
		ft += itm->first;
		ft += itm->second;
		itm++;
	}
	it = testStd.begin();
	itm = testFt.begin();
	while (ite != it) {
		ite--;
		std += ite->first;
		std += ite->second;
	}
	while (item != itm) {
		item--;
		ft += item->first;
		ft += item->second;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const iteratot map

void constIteratorTestMap(std::string &std, std::string &ft, int number) {
	std::map<int,int> testStd;
	ft::map<int,int> testFt;
	std::cout << "All const_iterator test" << " ";
	for (int i = 0; i < number; i++) {
		std::pair<int, int> res(rand(), rand());
		testStd.insert(res);
		testFt.insert(res);
	}
	std::map<int,int>::const_iterator it = testStd.cbegin();
	std::map<int,int>::const_iterator ite = testStd.cend();
	ft::map<int,int>::const_iterator itm = testFt.cbegin();
	ft::map<int,int>::const_iterator item = testFt.cend();
	while (it != ite) {
		std += it->first;
		std += it->second;
		it++;
	}
	while (itm != item) {
		ft += itm->first;
		ft += itm->second;
		itm++;
	}
	it = testStd.cbegin();
	itm = testFt.cbegin();
	while (ite != it) {
		ite--;
		std += ite->first;
		std += ite->second;
	}
	while (item != itm) {
		item--;
		ft += item->first;
		ft += item->second;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Reverse iteratot map

void reverseIteratorTestMap(std::string &std, std::string &ft, int number) {
	std::map<int,int> testStd;
	ft::map<int,int> testFt;
	std::cout << "All reverse_iterator test" << " ";
	for (int i = 0; i < number; i++) {
		std::pair<int, int> res(rand(), rand());
		testStd.insert(res);
		testFt.insert(res);
	}
	std::map<int,int>::reverse_iterator it = testStd.rbegin();
	std::map<int,int>::reverse_iterator ite = testStd.rend();
	ft::map<int,int>::reverse_iterator itm = testFt.rbegin();
	ft::map<int,int>::reverse_iterator item = testFt.rend();
	while (it != ite) {
		std += it->first;
		std += it->second;
		it++;
	}
	while (itm != item) {
		ft += itm->first;
		ft += itm->second;
		itm++;
	}
	it = testStd.rbegin();
	itm = testFt.rbegin();
	while (ite != it) {
		ite--;
		std += ite->first;
		std += ite->second;
	}
	while (item != itm) {
		item--;
		ft += item->first;
		ft += item->second;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const reverse iteratot map

void constReverseIteratorTestMap(std::string &std, std::string &ft, int number) {
	std::map<int,int> testStd;
	ft::map<int,int> testFt;
	std::cout << "All const_reverse_iterator test" << " ";
	for (int i = 0; i < number; i++) {
		std::pair<int, int> res(rand(), rand());
		testStd.insert(res);
		testFt.insert(res);
	}
	std::map<int,int>::const_reverse_iterator it = testStd.crbegin();
	std::map<int,int>::const_reverse_iterator ite = testStd.crend();
	ft::map<int,int>::const_reverse_iterator itm = testFt.crbegin();
	ft::map<int,int>::const_reverse_iterator item = testFt.crend();
	while (it != ite) {
		std += it->first;
		std += it->second;
		it++;
	}
	while (itm != item) {
		ft += itm->first;
		ft += itm->second;
		itm++;
	}
	it = testStd.crbegin();
	itm = testFt.crbegin();
	while (ite != it) {
		ite--;
		std += ite->first;
		std += ite->second;
	}
	while (item != itm) {
		item--;
		ft += item->first;
		ft += item->second;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Empty map

void emptyMapTest(std::string &std, std::string &ft) {
	std::cout << "Empty int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std += def.empty();
	ft += my.empty();
	mapInsertElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Empty float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std += def.empty();
	ft += my.empty();
	mapInsertElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Empty std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std += def.empty();
	ft += my.empty();
	mapInsertElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Size map

void sizeMapTest(std::string &std, std::string &ft) {
	std::cout << "Size int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std += def.size();
	ft += my.size();
	mapInsertElem(def, my, 10);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Size float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std += def.size();
	ft += my.size();
	mapInsertElem(def, my, 10);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std += def.size();
	ft += my.size();
	mapInsertElem(def, my, 10);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Max size map

void maxSizeTestMap(std::string &std, std::string &ft) {
	std::cout << "Max size int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void maxSizeTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Max size float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Operator [] map

void squareBracketsTestMap(std::string &std, std::string &ft) {
	std::cout << "Opetator[] int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(21, 42);
	def.insert(test);
	my.insert(test);
	std += def[21];
	ft += my[21];
	std += def[42];
	ft += my[42];
	std += def[42];
	ft += my[42];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void squareBracketsTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Opetator[] float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(21, 42);
	def.insert(test);
	my.insert(test);
	std += def[21];
	ft += my[21];
	std += def[42];
	ft += my[42];
	std += def[42];
	ft += my[42];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void squareBracketsTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Opetator[] std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("21", "42");
	def.insert(test);
	my.insert(test);
	std += def["21"];
	ft += my["21"];
	std += def["42"];
	ft += my["42"];
	std += def["42"];
	ft += my["42"];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Insert map

void singleInsertMap(std::string &std, std::string &ft) {
	std::cout << "Single insert int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapFillStr(def, my, std, ft);
	std::pair<int, int> test(42, 21);
	def.insert(test);
	my.insert(test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleInsertMapFloat(std::string &std, std::string &ft) {
	std::cout << "Single insert float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapFillStr(def, my, std, ft);
	std::pair<float, float> test(42.21, 21.42);
	def.insert(test);
	my.insert(test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleInsertMapStr(std::string &std, std::string &ft) {
	std::cout << "Single insert std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapFillStr(def, my, std, ft);
	std::pair<std::string, std::string> test("42", "21");
	def.insert(test);
	my.insert(test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void withHitInsertMap(std::string &std, std::string &ft) {
	std::cout << "With hit insert int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapFillStr(def, my, std, ft);
	std::pair<int, int> test(42, 21);
	def.insert(def.begin(),test);
	my.insert(my.begin(), test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void withHitInsertMapFloat(std::string &std, std::string &ft) {
	std::cout << "With hit insert float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapFillStr(def, my, std, ft);
	std::pair<float, float> test(42.21, 21.42);
	def.insert(def.begin(),test);
	my.insert(my.begin(), test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void withHitInsertMapStr(std::string &std, std::string &ft) {
	std::cout << "With hit insert std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapFillStr(def, my, std, ft);
	std::pair<std::string, std::string> test("42", "21");
	def.insert(def.begin(),test);
	my.insert(my.begin(), test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertMapTest(std::string &std, std::string &ft) {
	std::cout << "Range insert int test" << " ";
	std::map<int, int> test;
	for (int i = 0; i < 100; i++) {
		std::pair<int, int> l(rand(), rand());
		test.insert(l);
	}
	std::map<int, int> def;
	ft::map<int, int> my;
	def.insert(test.begin(), test.end());
	my.insert(test.begin(), test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Range insert float test" << " ";
	std::map<float, float> test;
	for (int i = 0; i < 100; i++) {
		std::pair<float, float> l(rand(), rand());
		test.insert(l);
	}
	std::map<float, float> def;
	ft::map<float, float> my;
	def.insert(test.begin(), test.end());
	my.insert(test.begin(), test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Range insert std::string test" << " ";
	std::map<std::string, std::string> test;
	for (int i = 0; i < 100; i++) {
		std::string l1;
		std::string l2;
		l1 += rand();
		l2 += rand();
		std::pair<std::string, std::string> l(l1, l2);
		test.insert(l);
	}
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	def.insert(test.begin(), test.end());
	my.insert(test.begin(), test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Erase map

void eraseSingleMapTest(std::string &std, std::string &ft) {
	std::cout << "Single erase int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	std::map<int, int>::iterator it = def.begin();
	ft::map<int, int>::iterator mit = my.begin();
	for (int i = 0; i < 10; i++) {
		it++;
		mit++;
	}
	for (int i = 0; i < 40; i++) {
		std::map<int, int>::iterator tmp = it;
		ft::map<int, int>::iterator mtmp = mit;
		it++;
		mit++;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	it = def.end();
	mit = my.end();
	it--;
	mit--;
	for (int i = 0; i < 20; i++) {
		std::map<int, int>::iterator tmp = it;
		ft::map<int, int>::iterator mtmp = mit;
		it--;
		mit--;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseSingleMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Single erase float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	std::map<float, float>::iterator it = def.begin();
	ft::map<float, float>::iterator mit = my.begin();
	for (int i = 0; i < 10; i++) {
		it++;
		mit++;
	}
	for (int i = 0; i < 40; i++) {
		std::map<float, float>::iterator tmp = it;
		ft::map<float, float>::iterator mtmp = mit;
		it++;
		mit++;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	it = def.end();
	mit = my.end();
	it--;
	mit--;
	for (int i = 0; i < 20; i++) {
		std::map<float, float>::iterator tmp = it;
		ft::map<float, float>::iterator mtmp = mit;
		it--;
		mit--;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseSingleMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Single erase std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	std::map<std::string, std::string>::iterator it = def.begin();
	ft::map<std::string, std::string>::iterator mit = my.begin();
	for (int i = 0; i < 10; i++) {
		it++;
		mit++;
	}
	for (int i = 0; i < 40; i++) {
		std::map<std::string, std::string>::iterator tmp = it;
		ft::map<std::string, std::string>::iterator mtmp = mit;
		it++;
		mit++;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	it = def.end();
	mit = my.end();
	it--;
	mit--;
	for (int i = 0; i < 20; i++) {
		std::map<std::string, std::string>::iterator tmp = it;
		ft::map<std::string, std::string>::iterator mtmp = mit;
		it--;
		mit--;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseKeyMapTest(std::string &std, std::string &ft) {
	std::cout << "Key erase int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	def.insert(test);
	my.insert(test);
	def.erase(42);
	my.erase(42);
	def.erase(1);
	my.erase(1);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseKeyMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Key erase float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	def.insert(test);
	my.insert(test);
	def.erase(42.21);
	my.erase(42.21);
	def.erase(1.7);
	my.erase(1.7);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseKeyMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Key erase std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	def.insert(test);
	my.insert(test);
	def.erase("42");
	my.erase("42");
	def.erase("1");
	my.erase("1");
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseRangeTest(std::string &std, std::string &ft) {
	std::cout << "Range erase int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::map<int, int>::iterator it = def.begin();
	std::map<int, int>::iterator ite = def.end();
	ft::map<int, int>::iterator itm = my.begin();
	ft::map<int, int>::iterator item = my.end();
	for (int i = 0; i < 20; i++) {
		++it;
		++itm;
		--ite;
		--item;
	}
	def.erase(it, ite);
	my.erase(itm, item);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseRangeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Range erase float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::map<float, float>::iterator it = def.begin();
	std::map<float, float>::iterator ite = def.end();
	ft::map<float, float>::iterator itm = my.begin();
	ft::map<float, float>::iterator item = my.end();
	for (int i = 0; i < 20; i++) {
		++it;
		++itm;
		--ite;
		--item;
	}
	def.erase(it, ite);
	my.erase(itm, item);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseRangeTestStr(std::string &std, std::string &ft) {
	std::cout << "Range erase std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::map<std::string, std::string>::iterator it = def.begin();
	std::map<std::string, std::string>::iterator ite = def.end();
	ft::map<std::string, std::string>::iterator itm = my.begin();
	ft::map<std::string, std::string>::iterator item = my.end();
	for (int i = 0; i < 20; i++) {
		++it;
		++itm;
		--ite;
		--item;
	}
	def.erase(it, ite);
	my.erase(itm, item);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Swap map

void swapTestMap(std::string &std, std::string &ft) {
	std::cout << "Swap int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std::map<int, int> toSwap;
	ft::map<int, int> mySwap;
	mapInsertElem(def, my, 100);
	mapInsertElem(toSwap, mySwap, 50);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Swap float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std::map<float, float> toSwap;
	ft::map<float, float> mySwap;
	mapInsertElem(def, my, 100);
	mapInsertElem(toSwap, mySwap, 50);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Swap std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std::map<std::string, std::string> toSwap;
	ft::map<std::string, std::string> mySwap;
	mapInsertElem(def, my, 100);
	mapInsertElem(toSwap, mySwap, 50);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Clear map

void clearTestMap(std::string &std, std::string &ft) {
	std::cout << "Clear int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Clear float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Clear std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Key compare map

void keyCompareTest(std::string &std, std::string &ft) {
	std::cout << "Key comp int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std::map<int,int>::key_compare comp = def.key_comp();
	ft::map<int,int>::key_compare myComp = my.key_comp();
	int i = 10000;
	mapInsertElem(def, my, 100);
	for (std::map<int, int>::iterator it = def.begin(); it != def.end(); ++it) {
		std += comp(i, it->first);
		ft += myComp(i, it->first);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void keyCompareTestFloat(std::string &std, std::string &ft) {
	std::cout << "Key comp float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std::map<float,float>::key_compare comp = def.key_comp();
	ft::map<float,float>::key_compare myComp = my.key_comp();
	float i = 10000.42;
	mapInsertElem(def, my, 100);
	for (std::map<float, float>::iterator it = def.begin(); it != def.end(); ++it) {
		std += comp(i, it->first);
		ft += myComp(i, it->first);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void keyCompareTestStr(std::string &std, std::string &ft) {
	std::cout << "Key comp std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std::map<std::string,std::string>::key_compare comp = def.key_comp();
	ft::map<std::string,std::string>::key_compare myComp = my.key_comp();
	std::string i = "10000";
	mapInsertElem(def, my, 100);
	for (std::map<std::string, std::string>::iterator it = def.begin(); it != def.end(); ++it) {
		std += comp(i, it->first);
		ft += myComp(i, it->first);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Value compare map

void valueCompareTest(std::string &std, std::string &ft) {
	std::cout << "Value comp int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> res(100,100);
	for (std::map<int, int>::iterator it = def.begin(); it != def.end(); ++it) {
		std += def.value_comp()(res, *it);
		ft += my.value_comp()(res, *it);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void valueCompareTestFloat(std::string &std, std::string &ft) {
	std::cout << "Value comp float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> res(100.42,100.42);
	for (std::map<float, float>::iterator it = def.begin(); it != def.end(); ++it) {
		std += def.value_comp()(res, *it);
		ft += my.value_comp()(res, *it);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void valueCompareTestStr(std::string &std, std::string &ft) {
	std::cout << "Value comp std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> res("100","100");
	for (std::map<std::string, std::string>::iterator it = def.begin(); it != def.end(); ++it) {
		std += def.value_comp()(res, *it);
		ft += my.value_comp()(res, *it);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Find map

void findTest(std::string &std, std::string &ft) {
	std::cout << "Find int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	def.insert(test);
	my.insert(test);
	std::map<int, int>::iterator it;
	ft::map<int, int>::iterator ite;
	it = def.find(42);
	ite = my.find(42);
	std += it->first;
	std += it->second;
	ft += ite->first;
	ft += ite->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void findTestFloat(std::string &std, std::string &ft) {
	std::cout << "Find float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	def.insert(test);
	my.insert(test);
	std::map<float, float>::iterator it;
	ft::map<float, float>::iterator ite;
	it = def.find(42.21);
	ite = my.find(42.21);
	std += it->first;
	std += it->second;
	ft += ite->first;
	ft += ite->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void findTestStr(std::string &std, std::string &ft) {
	std::cout << "Find std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	def.insert(test);
	my.insert(test);
	std::map<std::string, std::string>::iterator it;
	ft::map<std::string, std::string>::iterator ite;
	it = def.find("42");
	ite = my.find("42");
	std += it->first;
	std += it->second;
	ft += ite->first;
	ft += ite->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Count map

void countTest(std::string &std, std::string &ft) {
	std::cout << "Count int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	std::pair<int, int> test1(21, 21);
	def.insert(test);
	my.insert(test);
	def.insert(test);
	my.insert(test);
	std += def.count(42);
	ft += my.count(42);
	std += def.count(21);
	ft += my.count(21);
	std += def.count(72);
	ft += my.count(72);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void countTestFloat(std::string &std, std::string &ft) {
	std::cout << "Count float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	std::pair<float, float> test1(21.42, 21.42);
	def.insert(test);
	my.insert(test);
	def.insert(test);
	my.insert(test);
	std += def.count(42.21);
	ft += my.count(42.21);
	std += def.count(21.42);
	ft += my.count(21.42);
	std += def.count(72.1);
	ft += my.count(72.1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void countTestStr(std::string &std, std::string &ft) {
	std::cout << "Count std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	std::pair<std::string, std::string> test1("21", "21");
	def.insert(test);
	my.insert(test);
	def.insert(test);
	my.insert(test);
	std += def.count("42");
	ft += my.count("42");
	std += def.count("21");
	ft += my.count("21");
	std += def.count("72");
	ft += my.count("72");
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Lover bound map

void lowerBoundTest(std::string &std, std::string &ft) {
	std::cout << "Lower bound int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	def.insert(test);
	my.insert(test);
	std::map<int, int>::iterator it;
	ft::map<int, int>::iterator itm;
	it = def.lower_bound(42);
	itm = my.lower_bound(42);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(43);
	itm = my.lower_bound(43);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(-9999999);
	itm = my.lower_bound(-9999999);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(999999999);
	itm = my.lower_bound(999999999);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lowerBoundTestFloat(std::string &std, std::string &ft) {
	std::cout << "Lower bound float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	def.insert(test);
	my.insert(test);
	std::map<float, float>::iterator it;
	ft::map<float, float>::iterator itm;
	it = def.lower_bound(42.21);
	itm = my.lower_bound(42.21);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(43.21);
	itm = my.lower_bound(43.21);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(-9999999.0);
	itm = my.lower_bound(-9999999.0);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(999999999.0);
	itm = my.lower_bound(999999999.0);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lowerBoundTestStr(std::string &std, std::string &ft) {
	std::cout << "Lower bound std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	def.insert(test);
	my.insert(test);
	std::map<std::string, std::string>::iterator it;
	ft::map<std::string, std::string>::iterator itm;
	it = def.lower_bound("42");
	itm = my.lower_bound("42");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound("43");
	itm = my.lower_bound("43");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound("a");
	itm = my.lower_bound("a");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound("zzzzzzzzzzzzzzz");
	itm = my.lower_bound("zzzzzzzzzzzzzzz");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Upper bound map

void upperBoundTest(std::string &std, std::string &ft) {
	std::cout << "Upper bound int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	def.insert(test);
	my.insert(test);
	std::map<int, int>::iterator it;
	ft::map<int, int>::iterator itm;
	it = def.upper_bound(42);
	itm = my.upper_bound(42);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(43);
	itm = my.upper_bound(43);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(-9999999);
	itm = my.upper_bound(-9999999);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(999999999);
	itm = my.upper_bound(999999999);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void upperBoundTestFloat(std::string &std, std::string &ft) {
	std::cout << "Upper bound float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	def.insert(test);
	my.insert(test);
	std::map<float, float>::iterator it;
	ft::map<float, float>::iterator itm;
	it = def.upper_bound(42.21);
	itm = my.upper_bound(42.21);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(43.21);
	itm = my.upper_bound(43.21);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(-9999999.0);
	itm = my.upper_bound(-9999999.0);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(999999999.0);
	itm = my.upper_bound(999999999.0);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void upperBoundTestStr(std::string &std, std::string &ft) {
	std::cout << "Upper bound std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	def.insert(test);
	my.insert(test);
	std::map<std::string, std::string>::iterator it;
	ft::map<std::string, std::string>::iterator itm;
	it = def.upper_bound("42");
	itm = my.upper_bound("42");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound("43");
	itm = my.upper_bound("43");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound("a");
	itm = my.upper_bound("a");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound("zzzzzzzzzzzzzzz");
	itm = my.upper_bound("zzzzzzzzzzzzzzz");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Equal range map

void equalRangeTest(std::string &std, std::string &ft) {
	std::cout << "Equal range int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> test;
	std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> myTest;
	test = def.equal_range(100);
	myTest = my.equal_range(100);
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	std::pair<int, int> toTest(42, 42);
	def.insert(toTest);
	my.insert(toTest);
	test = def.equal_range(42);
	myTest = my.equal_range(42);
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalRangeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Equal range float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<std::map<float, float>::iterator, std::map<float, float>::iterator> test;
	std::pair<ft::map<float, float>::iterator, ft::map<float, float>::iterator> myTest;
	test = def.equal_range(100);
	myTest = my.equal_range(100);
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	std::pair<float, float> toTest(42.21, 42.21);
	def.insert(toTest);
	my.insert(toTest);
	test = def.equal_range(42.21);
	myTest = my.equal_range(42.21);
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalRangeTestStr(std::string &std, std::string &ft) {
	std::cout << "Equal range std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::map<std::string, std::string>::iterator, std::map<std::string, std::string>::iterator> test;
	std::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> myTest;
	test = def.equal_range("100");
	myTest = my.equal_range("100");
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	std::pair<std::string, std::string> toTest("42", "42");
	def.insert(toTest);
	my.insert(toTest);
	test = def.equal_range("42");
	myTest = my.equal_range("42");
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Map

void testMap() {
	std::cout << "                            CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTestMap(std, ft);
	defaultCnstTestMapFloat(std, ft);
	defaultCnstTestMapStr(std, ft);
	rangeCnstTestMap(std, ft);
	rangeCnstTestMapFloat(std, ft);
	rangeCnstTestMapStr(std, ft);
	copyCnstTestMap(std, ft);
	copyCnstTestMapFloat(std, ft);
	copyCnstTestMapStr(std, ft);
	std::cout << "                            ASSIGNATION" << std::endl;
	assignTestMap(std, ft);
	assignTestMapFloat(std, ft);
	assignTestMapStr(std, ft);
	std::cout << "                            ITERATORS" << std::endl;
	iteratorTestMap(std, ft, 1000);
	constIteratorTestMap(std, ft, 1000);
	reverseIteratorTestMap(std, ft, 1000);
	constReverseIteratorTestMap(std, ft, 1000);
	std::cout << "                            CAPACITY" << std::endl;
	emptyMapTest(std, ft);
	emptyMapTestFloat(std, ft);
	emptyMapTestStr(std, ft);
	sizeMapTest(std, ft);
	sizeMapTestFloat(std, ft);
	sizeMapTestStr(std, ft);
	maxSizeTestMap(std, ft);
	maxSizeTestMapFloat(std, ft);
	std::cout << "                            ELEMENT ACCESS" << std::endl;
	squareBracketsTestMap(std, ft);
	squareBracketsTestMapFloat(std, ft);
	squareBracketsTestMapStr(std, ft);
	std::cout << "                            MODIFIERS" << std::endl;
	singleInsertMap(std, ft);
	singleInsertMapFloat(std, ft);
	singleInsertMapStr(std, ft);
	withHitInsertMap(std, ft);
	withHitInsertMapFloat(std, ft);
	withHitInsertMapStr(std, ft);
	rangeInsertMapTest(std, ft);
	rangeInsertMapTestFloat(std, ft);
	rangeInsertMapTestStr(std, ft);
	eraseSingleMapTest(std, ft);
	eraseSingleMapTestFloat(std, ft);
	eraseSingleMapTestStr(std, ft);
	eraseKeyMapTest(std, ft);
	eraseKeyMapTestFloat(std, ft);
	eraseKeyMapTestStr(std, ft);
	eraseRangeTest(std, ft);
	eraseRangeTestFloat(std, ft);
	eraseRangeTestStr(std, ft);
	swapTestMap(std, ft);
	swapTestMapFloat(std, ft);
	swapTestMapStr(std, ft);
	clearTestMap(std, ft);
	clearTestMapFloat(std, ft);
	clearTestMapStr(std, ft);
	std::cout << "                            OBSERVERS" << std::endl;
	keyCompareTest(std, ft);
	keyCompareTestFloat(std, ft);
	keyCompareTestStr(std, ft);
	valueCompareTest(std, ft);
	valueCompareTestFloat(std, ft);
	valueCompareTestStr(std, ft);
	std::cout << "                            OPERATIONS" << std::endl;
	findTest(std, ft);
	findTestFloat(std, ft);
	findTestStr(std, ft);
	countTest(std, ft);
	countTestFloat(std, ft);
	countTestStr(std, ft);
	lowerBoundTest(std, ft);
	lowerBoundTestFloat(std, ft);
	lowerBoundTestStr(std, ft);
	upperBoundTest(std, ft);
	upperBoundTestFloat(std, ft);
	upperBoundTestStr(std, ft);
	equalRangeTest(std, ft);
	equalRangeTestFloat(std, ft);
	equalRangeTestStr(std, ft);
}

//MARK: - Default constructor queue

void defaultCnstTestQueue(std::string &std, std::string &ft) {
	std::cout << "Default int constructor test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Default float constructor test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Default std::string constructor test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Empty queue

void emptyTestQueue(std::string &std, std::string &ft) {
	std::cout << "Empty int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std += def.empty();
	ft += my.empty();
	queuePushElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Empty float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std += def.empty();
	ft += my.empty();
	queuePushElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Empty std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std += def.empty();
	ft += my.empty();
	queuePushElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Size queue

void sizeTestQueue(std::string &std, std::string &ft) {
	std::cout << "Size int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 50);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Size float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 50);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string  test" << " ";
	std::queue<std::string > def;
	ft::queue<std::string > my;
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 50);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Front queue

void frontTestQueue(std::string &std, std::string &ft) {
	std::cout << "Front int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void frontTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Front float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void frontTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Front std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Back queue

void backTestQueue(std::string &std, std::string &ft) {
	std::cout << "Back int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void backTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Back float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void backTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Back std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Push queue

void pushTestQueue(std::string &std, std::string &ft) {
	std::cout << "Push int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Push float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Push std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Pop queue

void popTestQueue(std::string &std, std::string &ft) {
	std::cout << "Pop int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Pop float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Pop std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Non member Queue

void equalTestQueue(std::string &std, std::string &ft) {
	std::cout << "Equal int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Equal float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Equal std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestQueue(std::string &std, std::string &ft) {
	std::cout << "Non equal int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Non equal float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Non equal std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestQueue(std::string &std, std::string &ft) {
	std::cout << "Less int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def1);
	ft += (my < my1);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Less float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def1);
	ft += (my < my1);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Less std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def < def1);
	ft += (my < my1);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestQueue(std::string &std, std::string &ft) {
	std::cout << "Less or equal int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def <= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Less or equal float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def<= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Less or equal std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def <= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestQueue(std::string &std, std::string &ft) {
	std::cout << "Greater int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 > def);
	std += (def > def1);
	std += (def > def);
	std += (def1 > def1);
	ft += (my1 > my);
	ft += (my > my1);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Greater float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def > def1);
	std += (def1 > def);
	std += (def > def);
	std += (def1 > def1);
	ft += (my > my1);
	ft += (my1 > my);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Greater std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def > def1);
	std += (def1 > def);
	std += (def > def);
	std += (def1 > def1);
	ft += (my > my1);
	ft += (my1 > my);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestQueue(std::string &std, std::string &ft) {
	std::cout << "Greater or equal int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Greater or equal float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Greater or equal std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Queue

void testQueue() {
	std::cout << "                         CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTestQueue(std, ft);
	defaultCnstTestQueueFloat(std, ft);
	defaultCnstTestQueueStr(std, ft);
	std::cout << "                         EMPTY" << std::endl;
	emptyTestQueue(std, ft);
	emptyTestQueueFloat(std, ft);
	emptyTestQueueStr(std, ft);
	std::cout << "                         SIZE" << std::endl;
	sizeTestQueue(std, ft);
	sizeTestQueueFloat(std, ft);
	sizeTestQueueStr(std, ft);
	std::cout << "                         FRONT" << std::endl;
	frontTestQueue(std, ft);
	frontTestQueueFloat(std, ft);
	frontTestQueueStr(std, ft);
	std::cout << "                         BACK" << std::endl;
	backTestQueue(std, ft);
	backTestQueueFloat(std, ft);
	backTestQueueStr(std, ft);
	std::cout << "                         PUSH" << std::endl;
	pushTestQueue(std, ft);
	pushTestQueueFloat(std, ft);
	pushTestQueueStr(std, ft);
	std::cout << "                         POP" << std::endl;
	popTestQueue(std, ft);
	popTestQueueFloat(std, ft);
	popTestQueueStr(std, ft);
	std::cout << "                         NON MEMBER FUNCTIONS OVERLOADS" << std::endl;
	equalTestQueue(std, ft);
	equalTestQueueFloat(std, ft);
	equalTestQueueStr(std, ft);
	nonEqualTestQueue(std, ft);
	nonEqualTestQueueFloat(std, ft);
	nonEqualTestQueueStr(std, ft);
	lessTestQueue(std, ft);
	lessTestQueueFloat(std, ft);
	lessTestQueueStr(std, ft);
	lessOrEqualTestQueue(std, ft);
	lessOrEqualTestQueueFloat(std, ft);
	lessOrEqualTestQueueStr(std, ft);
	greaterTestQueue(std, ft);
	greaterTestQueueFloat(std, ft);
	greaterTestQueueStr(std, ft);
	greaterOrEqualTestQueue(std, ft);
	greaterOrEqualTestQueueFloat(std, ft);
	greaterOrEqualTestQueueStr(std, ft);
};

//MARK: - Default constructor stack

void defaultCnstTestStack(std::string &std, std::string &ft) {
	std::cout << "Default constructor int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Default constructor float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Default constructor std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Empty stack

void emptyTestStack(std::string &std, std::string &ft) {
	std::cout << "Empty int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Empty float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Empty std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Size stack

void sizeTestStack(std::string &std, std::string &ft) {
	std::cout << "Size int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 20);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Size float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 20);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 20);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Top stack

void topTestStack(std::string &std, std::string &ft) {
	std::cout << "Top int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	stackPushElem(def, my, 10);
	std += def.top();
	ft += my.top();
	stackPushElem(def, my, 20);
	std += def.top();
	ft += my.top();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void topTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Top float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	stackPushElem(def, my, 10);
	std += def.top();
	ft += my.top();
	stackPushElem(def, my, 20);
	std += def.top();
	ft += my.top();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void topTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	stackPushElem(def, my, 10);
	std += def.top();
	ft += my.top();
	stackPushElem(def, my, 20);
	std += def.top();
	ft += my.top();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Push stack

void pushTestStack(std::string &std, std::string &ft) {
	std::cout << "Push int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	stackPushElem(def, my, 1);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 20);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushTestQueueStack(std::string &std, std::string &ft) {
	std::cout << "Push float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	stackPushElem(def, my, 1);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 20);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Push std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	stackPushElem(def, my, 1);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 20);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Pop stack

void popTestStack(std::string &std, std::string &ft) {
	std::cout << "Pop int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Pop float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Pop std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Non member Queue

void equalTestStack(std::string &std, std::string &ft) {
	std::cout << "Equal int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Equal float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Equal std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestStack(std::string &std, std::string &ft) {
	std::cout << "Non equal int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Non equal float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Non equal std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestStack(std::string &std, std::string &ft) {
	std::cout << "Less int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def1);
	ft += (my < my1);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Less float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def1);
	ft += (my < my1);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Less std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def < def1);
	ft += (my < my1);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestStack(std::string &std, std::string &ft) {
	std::cout << "Less or equal int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def <= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Less or equal float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def<= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Less or equal std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def <= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestStack(std::string &std, std::string &ft) {
	std::cout << "Greater int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def1 > def);
	std += (def > def1);
	std += (def > def);
	std += (def1 > def1);
	ft += (my1 > my);
	ft += (my > my1);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Greater float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def > def1);
	std += (def1 > def);
	std += (def > def);
	std += (def1 > def1);
	ft += (my > my1);
	ft += (my1 > my);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Greater std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def > def1);
	std += (def1 > def);
	std += (def > def);
	std += (def1 > def1);
	ft += (my > my1);
	ft += (my1 > my);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestStack(std::string &std, std::string &ft) {
	std::cout << "Greater or equal int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Greater or equal float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Greater or equal std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Stack

void testStack() {
	//MARK: - Constructor
	std::cout << "                         CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTestStack(std, ft);
	defaultCnstTestStackFloat(std, ft);
	defaultCnstTestStackStr(std, ft);
	std::cout << "                         EMPTY" << std::endl;
	emptyTestStack(std, ft);
	emptyTestStackFloat(std, ft);
	emptyTestStackStr(std, ft);
	std::cout << "                         SIZE" << std::endl;
	sizeTestStack(std, ft);
	sizeTestStackFloat(std, ft);
	sizeTestStackStr(std, ft);
	std::cout << "                         TOP" << std::endl;
	topTestStack(std, ft);
	topTestStackFloat(std, ft);
	topTestStackStr(std, ft);
	std::cout << "                         POP" << std::endl;
	popTestStack(std, ft);
	popTestStackFloat(std, ft);
	popTestStackStr(std, ft);
	std::cout << "                         NON MEMBER FUNCTIONS OVERLOADS" << std::endl;
	equalTestStack(std, ft);
	equalTestStackFloat(std, ft);
	equalTestStackStr(std, ft);
	nonEqualTestStack(std, ft);
	nonEqualTestStackFloat(std, ft);
	nonEqualTestStackStr(std, ft);
	lessTestStack(std, ft);
	lessTestStackFloat(std, ft);
	lessTestStackStr(std, ft);
	lessOrEqualTestStack(std, ft);
	lessOrEqualTestStackFloat(std, ft);
	lessOrEqualTestStackStr(std, ft);
	greaterTestStack(std, ft);
	greaterTestStackFloat(std, ft);
	greaterTestStackStr(std, ft);
	greaterOrEqualTestStack(std, ft);
	greaterOrEqualTestStackFloat(std, ft);
	greaterOrEqualTestStackStr(std, ft);
};

int main()
{
	std::cout << "                                                LIST" << std::endl;
	testList();
	std::cout << "                                                VECTOR" << std::endl;
	testVector();
	std::cout << "                                                MAP" << std::endl;
	testMap();
	std::cout << "                                                QUEUE" << std::endl;
	testQueue();
	std::cout << "                                                STACK" << std::endl;
	testStack();
	while (1)
		;
	return (0);
}


