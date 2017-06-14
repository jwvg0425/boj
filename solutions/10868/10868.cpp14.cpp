#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

class Tree
{
public:
	static Tree* create(const std::vector<int>& numbers, int begin, int end)
	{
		Tree* t = new Tree();
		t->interval.first = begin;
		t->interval.second = end;

		//leaf
		if (begin == end)
		{
			t->minVal = t->maxVal = numbers[begin];
			return t;
		}

		int mid = begin + (end - begin) / 2;
		t->left = Tree::create(numbers, begin, mid);
		t->right = Tree::create(numbers, mid + 1, end);

		t->maxVal = std::max(t->left->maxVal, t->right->maxVal);
		t->minVal = std::min(t->left->minVal, t->right->minVal);

		return t;
	}

	std::pair<int, int> query(int begin, int end)
	{
		if (interval.first == begin && interval.second == end)
			return std::make_pair(minVal, maxVal);

		if (end < right->interval.first)
			return left->query(begin, end);

		if (begin > left->interval.second)
			return right->query(begin, end);

		auto lquery = left->query(begin, left->interval.second);
		auto rquery = right->query(right->interval.first, end);

		return std::make_pair(std::min(lquery.first, rquery.first),
			std::max(lquery.second, rquery.second));
	}

	~Tree()
	{
		if (left != nullptr)
			delete left;

		if (right != nullptr)
			delete right;
	}

private:
	Tree() : left(nullptr), right(nullptr)
	{
	}

	std::pair<int, int> interval;
	int minVal;
	int maxVal;
	Tree* left;
	Tree* right;
};

int main()
{
	std::vector<int> arr;
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	auto tree = Tree::create(arr, 0, arr.size() - 1);

	for (int i = 0; i < m; i++)
	{
		int start, end;

		scanf("%d %d", &start, &end);

		printf("%d\n", tree->query(start - 1, end - 1));
	}

	return 0;
}