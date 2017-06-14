#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

std::set<char> mo = { 'a','e','i','o','u' };
std::string cand;

int l, c;

bool isOk(const std::string& s)
{
	int j = 0;
	int m = 0;

	for (auto& c : s)
	{
		if (mo.find(c) != mo.end())
			m++;
		else
			j++;
	}

	int left = l - s.size();

	m = std::max(0, 1 - m);
	j = std::max(0, 2 - j);

	if (left < m + j)
		return false;

	return true;
}

void print(std::string now, int k)
{
	if (now.size() == l)
	{
		std::cout << now << std::endl;
		return;
	}

	for (int i = k + 1; i < c; i++)
	{
		std::string next = now + cand[i];

		if (isOk(next))
			print(next, i);
	}
}

int main()
{
	scanf("%d %d", &l, &c);

	for (int i = 0; i < c; i++)
	{
		std::string s;
		std::cin >> s;

		cand.push_back(s[0]);
	}

	std::sort(cand.begin(), cand.end());

	for (int i = 0; i < c; i++)
	{
		std::string start;
		start.push_back(cand[i]);
		print(start, i);
	}

	return 0;
}