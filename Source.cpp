#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <conio.h>

using namespace std;

struct MyType
{
	int x;
	char c;
};

bool operator>(MyType x, MyType y)
{
	return x.x > y.x;
}

bool operator<(MyType x, MyType y)
{
	return x.x < y.x;
}

bool operator==(MyType x, MyType y)
{
	return x.x == y.x;
}

bool pred(const MyType &a)	// Условие 1
{
	return a.x == 15;
}

bool pred2(const MyType &a)	// Условие 2
{
	return a.x > 0;
}

int main()
{
	// Программа 1

	map<int, long> myMap = { {1, 1000}, {2, 655485}, {3, -84651}, {4, 985465}, {-100, 984512}, {11, 51684} };
	for (map<int, long>::iterator i = myMap.begin(); i != myMap.end(); ++i)
		cout << i->second << " ";
	cout << "\n";
	myMap.erase(11);
	myMap.erase(-100);
	myMap.insert({ 5, 159 });
	myMap.insert({ 6, -9846512135 });
	for (map<int, long>::iterator i = myMap.begin(); i != myMap.end(); ++i)
		cout << i->second << " ";
	cout << "\n";
	map<int, long> myMap1 = { { -1, 1250 },{ -2, 6485 },{ -3, -9845651 },{ -4, -885465 },{ -5, 2 },{ -6, 0 } };
	// Заданный элемент 159
	long cur = 0;
	for (map<int, long>::iterator i = myMap.begin(); i != myMap.end(); ++i)
		if (i->second == 159)
			cur = i->first;
	int begin = myMap.begin()->first, end = (--(myMap.end()))->first;
	for (int i = begin; i <= end; ++i)
		if (i >= cur)
			myMap.erase(i);
	for (map<int, long>::iterator i = myMap1.begin(); i != myMap1.end(); ++i)
		myMap.insert(*i);
	for (map<int, long>::iterator i = myMap.begin(); i != myMap.end(); ++i)
		cout << i->second << " ";
	cout << "\n";
	for (map<int, long>::iterator i = myMap1.begin(); i != myMap1.end(); ++i)
		cout << i->second << " ";
	cout << "\n";

	// Программа 2
	
	list<MyType> myList = { {15, 'a'}, {-99, 'b'}, {85286, 'q'}, {-100000, 'r'}, {0, 'u'} };
	myList.sort();
	myList.reverse();
	for (list<MyType>::iterator i = myList.begin(); i != myList.end(); ++i)
		cout << i->x << " " << i->c << " ";
	cout << "\n";
	// Условие x = 15
	MyType x =  *find_if(myList.begin(), --(myList.end()), pred);
	cout << x.c << " " << x.x << "\n";
	// Условие 2: x>0
	list<MyType> myList1;
	for (list<MyType>::iterator i = myList.begin(); i != myList.end(); ++i)
		if (i->x > 0)
			myList1.push_back(*i);
	for (list<MyType>::iterator i = myList1.begin(); i != myList1.end(); ++i)
		cout << i->x << " " << i->c << " ";
	cout << "\n";
	myList.sort();
	myList1.sort();
	for (list<MyType>::iterator i = myList.begin(); i != myList.end(); ++i)
		cout << i->x << " " << i->c << " ";
	cout << "\n";
	for (list<MyType>::iterator i = myList1.begin(); i != myList1.end(); ++i)
		cout << i->x << " " << i->c << " ";
	cout << "\n";
	list<MyType> myList2;
	for (list<MyType>::iterator i = myList.begin(); i != myList.end(); ++i)
		myList2.push_back(*i);
	for (list<MyType>::iterator i = myList1.begin(); i != myList1.end(); ++i)
		myList2.push_back(*i);
	for (list<MyType>::iterator i = myList2.begin(); i != myList2.end(); ++i)
		cout << i->x << " " << i->c << " ";
	cout << "\n";
	int cou = count_if(myList2.begin(), myList2.end(), pred2);
	cout << cou << "\n";
	if (find_if(myList2.begin(), myList2.end(), pred2) != myList2.end())
		cout << "yes\n";
	else
		cout << "no\n";
	_getch();
	return 0;
	_getch();
}