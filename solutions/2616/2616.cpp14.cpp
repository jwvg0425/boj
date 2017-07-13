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
#include <time.h>

using ii = std::pair<int, int>;

int table[50001][4];

int t;

std::vector<int> people;

//k ~ 끝까지 num개의 소형 객차를 이용해서 끌 수 있는 최대치
int solve(int k, int num)
{
	if (num == 0 || k >= people.size())
		return 0;

	if (table[k][num] != -1)
		return table[k][num];

	int& res = table[k][num];

	res = std::max(solve(k + 1, num), solve(k + t, num - 1) + people[std::min<int>(people.size() - 1, k + t)] - people[k]);

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n;
	scanf("%d", &n);

	people.push_back(0);

	for (int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);

		people.push_back(people.back() + p);
	}

	scanf("%d", &t);

	printf("%d", solve(0, 3));

	return 0;
}