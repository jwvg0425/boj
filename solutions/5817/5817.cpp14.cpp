#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MOD 1234567

using ii = std::pair<int, int>;

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

	std::pair<int, int> update(int idx, int val)
	{
		if (interval.first == idx && interval.second == idx)
		{
			minVal = val;
			maxVal = val;

			return std::make_pair(minVal, maxVal);
		}

		auto l = std::make_pair(left->minVal, left->maxVal);
		auto r = std::make_pair(right->minVal, right->maxVal);

		if (idx < right->interval.first)
		{
			l = left->update(idx, val);
		}
		else
		{
			r = right->update(idx, val);
		}

		minVal = std::min(l.first, r.first);
		maxVal = std::max(l.second, r.second);

		return std::make_pair(minVal, maxVal);
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
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> initial;
	std::vector<int> pos;

	initial.resize(n);

	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);

		initial[k-1] = i;
		pos.push_back(k);
	}

	auto tree = Tree::create(initial, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		int o, a, b;

		scanf("%d %d %d", &o, &a, &b);

		if (o == 1)
		{
			std::swap(pos[a-1], pos[b-1]);
			std::swap(initial[pos[a - 1] - 1], initial[pos[b - 1] - 1]);

			tree->update(pos[a-1] - 1, initial[pos[a-1] - 1]);
			tree->update(pos[b-1] - 1, initial[pos[b-1] - 1]);
		}
		else
		{
			auto range = tree->query(a-1, b-1);

			if (range.second - range.first == b - a)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}