#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

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
			t->minVal = numbers[begin];
			return t;
		}

		int mid = begin + (end - begin) / 2;
		t->left = Tree::create(numbers, begin, mid);
		t->right = Tree::create(numbers, mid + 1, end);

		t->minVal = std::min(t->left->minVal, t->right->minVal);

		return t;
	}

	void change(int idx, int k)
	{
		if (left == nullptr && right == nullptr)
		{
			minVal = k;
			return;
		}

		int lmin = 987654321;
		int rmin = 987654321;

		if (left != nullptr &&left->interval.first <= idx && left->interval.second >= idx)
		{
			left->change(idx, k);
		}

		if (right != nullptr &&right->interval.first <= idx && right->interval.second >= idx)
		{
			right->change(idx, k);
		}

		if (left != nullptr)
			lmin = left->minVal;

		if (right != nullptr)
			rmin = right->minVal;

		minVal = std::min(lmin, rmin);
	}

	int query(int begin, int end)
	{
		if (interval.first == begin && interval.second == end)
			return minVal;

		if (end < right->interval.first)
			return left->query(begin, end);

		if (begin > left->interval.second)
			return right->query(begin, end);

		auto lquery = left->query(begin, left->interval.second);
		auto rquery = right->query(right->interval.first, end);

		return std::min(lquery, rquery);
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
	Tree* left;
	Tree* right;
};

int main()
{
	int n;

	scanf("%d", &n);

	std::vector<int> vi;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		vi.push_back(a);
	}

	auto tree = Tree::create(vi, 0, vi.size() - 1);

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int order, start, end;
		scanf("%d %d %d", &order, &start, &end);

		if (order == 1)
		{
			tree->change(start - 1, end);
		}
		else
		{
			printf("%d\n", tree->query(start - 1, end - 1));
		}
	}

	return 0;
}