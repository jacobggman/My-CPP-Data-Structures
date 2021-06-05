// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <assert.h>
#include <vector>

#include "NonCopyVector.h"

class Test
{
public:
	Test()
	{
		std::cout << "Test() " << "\n";
	}
	Test(const Test& other) : name(other.name), isDeleted(other.isDeleted)
	{
		std::cout << "Test(const Test& other) " << "\n";
	}

	/*Test(const char* name)
	{
		this->name = name;
		std::cout << "Test(const char* name) " << name << "\n";
	}*/

	~Test()
	{
		std::cout << "~Test() " << "\n";
		isDeleted = true;
	}

	const char* name;
	bool isDeleted = false;
	//const char* randomField;
};

int main()
{
	NonCopyVector n = NonCopyVector();
	n.push(1);
	n.push(1);
	n.push(1);
	n.push(1);

	n[1] = 2;
	n[3] = 2;

	n.pop();
	n.pop();
	n.pop();
	n.pop();

	/*v.push_back(5);
	int five = v.pop_back();
	v.capacity();
	Stack<Test> stack;

	Test a = Test();
	stack.push(a);

	auto& ap = stack.top();
	std::cout << "after peek " << "\n";
	Test b = stack.top();
	stack.pop();
	std::cout << "after pop" << "\n";*/

	/*std::stack<Test> stack;
	Test a = Test();
	stack.push(a);

	auto& ap = stack.top();
	std::cout << "after peek " << "\n";
	Test b = stack.top();
	stack.pop();
	std::cout << "after pop" << "\n";*/
}