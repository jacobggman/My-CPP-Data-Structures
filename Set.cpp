#include "Set.h"

Set::Set(int size)
{
	resize(size / 10);
}

Set::~Set()
{
	for (auto& bucket : (*this->buckets))
	{
		for (size_t i = 0; i < bucket.size(); i++)
		{
			delete (bucket[i]);
		}
	}
	delete this->buckets;
}

void Set::add(const string& value)
{
	if (find(value))
	{
		return;
	}
	_add(new string(value));
}

void Set::remove(const string& value)
{
	auto& bucket = getBucket(value);
	auto it = find_if(bucket.begin(), bucket.end(), [&](const string* s) {
		return (*s) == value;
		});
	if (it == bucket.end())
	{
		return;
	}
	delete (*it);
	bucket.erase(it);
	setSize--;
}

bool Set::find(const string& value) const
{
	auto& bucket = getBucket(value);
	auto it = find_if(bucket.begin(), bucket.end(), [&](const string* s) {
		return (*s) == value;
		});

	return it != bucket.end();
}

int Set::size() const
{
	return setSize;
}

void Set::reserve(int size)
{
	if (size > (buckets->size() * 10))
	{
		resize(size / 10);
	}
}

unsigned int Set::hash(const string& value)
{
	unsigned int hashValue = std::hash<std::string>{}(value);
	/*for (size_t i = 0; i < value.size(); i++)
	{
		hashValue += value[i] ^ i;
	}
	std::hash(value);*/
	// std::cout << hashValue << "\n";
	return hashValue;
}

bool Set::findInBucket(const Bucket& bucket, string* value)
{
	/*for (string* checkValue : bucket)
	{
		if (checkValue)
	}*/
	return true;
}

Bucket& Set::getBucket(const string& value) const
{
	int index = hash(value) % maxHashValue();
	return (*buckets)[index];
}

int Set::maxHashValue() const
{
	return this->buckets->size();
}

void Set::resize(int newSize)
{
	auto oldBuckets = buckets;
	buckets = new std::vector<std::vector<string*>>(newSize);

	bool loadOldStrings = oldBuckets != nullptr;
	if (loadOldStrings)
	{
		for (auto& bucket : (*oldBuckets))
		{
			for (size_t i = 0; i < bucket.size(); i++)
			{
				_add(bucket[i]);
			}
		}
	}
}

void Set::_add(string* value)
{
	auto& bucket = getBucket(*value);
	bucket.push_back(value);
	setSize++;
	int mapSizeRatio = setSize / buckets->size();

	if (mapSizeRatio > 10)
	{
		resize(buckets->size() * 10);
	}
}