#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	std::set<int> s;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		s.insert(k);
	}

	int count = 0;

	for (auto& i : s)
	{
		if (s.find(m - i) != s.end())
			count++;
	}

	printf("%d", count / 2);

	return 0;
}