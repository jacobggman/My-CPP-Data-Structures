#pragma once
#include <vector>
#include <stdexcept>

#define D_SIZE 2

class NonCopyVector
{
public:
	NonCopyVector(int size = 0)
	{
		resize(size);
	}

	void resize(int size)
	{
		reserve(size);
		this->_size = size;
	}

	void reserve(int n)
	{
		if (n <= _capacity)
		{
			return;
		}

		int oldNumArray = arrays.size();

		arrays.push_back(std::vector<int>());
		arrays[oldNumArray].reserve(n - _capacity);

		_capacity = n;
	}

	void push(int value)
	{
		if (_size >= _capacity)
		{
			reserve(_capacity == 0 ? D_SIZE : _capacity * 2);
		}

		getArrayIndex(_size).push_back(value);

		_size++;
	}

	void pop()
	{
		getArrayIndex(_size - 1).pop_back();

		_size--;
	}

	int& operator[](int i)
	{
		int beforeArraysSize = 0;
		for (auto& array : arrays)
		{
			if (i < beforeArraysSize + array.capacity())
			{
				int thisArrayIndex = i - beforeArraysSize;

				if (beforeArraysSize + thisArrayIndex >= _size)
				{
					throw std::runtime_error{ "Index out of range." };
				}
				return array[thisArrayIndex];
			}

			beforeArraysSize += array.capacity();
		}
	}

	int size() const
	{
		return _size;
	}

	int capacity() const
	{
		return _capacity;
	}

private:
	// check each array for the index. use the size of the array.
	// arrays of sizes 2, 4, 8:
	// 2: 0, 1
	// 4: 2, 3, 4, 5
	// 8: 6, 7, 8, 8, 9, 10, 11, 12
	std::vector<int>& getArrayIndex(int i)
	{
		int beforeArraysSize = 0;
		for (auto& array : arrays)
		{
			beforeArraysSize += array.capacity();
			if (i < beforeArraysSize)
			{
				return array;
			}
		}
	}

	int _size = 0;
	int _capacity = 0;
	std::vector<std::vector<int>> arrays;
};
