#pragma once

#include <string>
#include <array>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using std::string;

typedef std::vector<string*> Bucket;
typedef std::vector<Bucket> Buckets;

struct ptrCompare : public std::unary_function<std::string*, bool>
{
	explicit ptrCompare(const std::string* baseline) : baseline(baseline) {}
	bool operator() (const std::string*& arg)
	{
		return (*arg) == (*baseline);
	}
	const std::string* baseline;
};

class Set
{
public:
	Set(int size = 160);
	~Set();
	void add(const string& value);
	void remove(const string& value);
	bool find(const string& value) const;
	int size() const;
	void reserve(int size);

private:
	static unsigned int hash(const string& value);
	static bool findInBucket(const Bucket& bucket, string* value);
	Bucket& getBucket(const string& value) const;
	int maxHashValue() const;
	void resize(int newSize);
	void _add(string* value);

private:
	Buckets* buckets = nullptr;
	int setSize = 0;
};
