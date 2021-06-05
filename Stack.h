#pragma once
#include <stdexcept>

template <class Type>
struct Node {
	Node(const Type& _data) : data(_data)
	{
	}

	Type data;
	Node<Type>* next = nullptr;
	Node<Type>* back = nullptr;
};

template <class Type>
class Stack
{
public:
	void push(const Type& type)
	{
		auto newNode = new Node<Type>(type);
		if (lastNode == nullptr)
		{
			lastNode = newNode;
		}
		else
		{
			lastNode->next = newNode;
			newNode->back = lastNode;
			lastNode = newNode;
		}
		_size++;
	}

	void pop()
	{
		if (empty())
		{
			throw std::runtime_error{ "The stack is empty." };
		}

		auto backNode = lastNode->back;
		if (backNode != nullptr)
		{
			backNode->next = nullptr;
		}

		delete lastNode;

		lastNode = backNode;
		_size--;
	}

	Type& top() const
	{
		if (empty())
		{
			throw std::runtime_error{ "The stack is empty." };
		}
		return lastNode->data;
	}

	/*Type top() const
	{
		if (empty())
		{
			throw std::runtime_error{ "The stack is empty." };
		}
		return lastNode->data;
	}*/

	int size() const
	{
		return this->_size;
	}

	bool empty() const
	{
		return this->_size == 0;
	}

	~Stack()
	{
		Node<Type>* node = lastNode;
		Node<Type>* next;

		while (node)
		{
			next = node->next;
			delete node;
			node = next;
		}
	}

private:
	Node<Type>* lastNode = nullptr;
	int _size = 0;
};
