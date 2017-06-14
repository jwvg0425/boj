#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

long long int table[20][20];

long long int solve(int x, int y)
{
	if (x == 1 && y == 1)
		return 1;

	if (table[x][y] != -1)
		return table[x][y];

	long long int& res = table[x][y];
	res = 0;

	if (x > 1)
		res += solve(x - 1, y);
	
	if (y > 1)
		res += solve(x, y - 1);

	return res;
}

int main()
{
	std::string s;

	int b;

	std::cin >> s >> b;

	int k = 0;

	for (int i =0; i < s.size();i++)
	{
		auto c = s[i];

		if (c >= '0' && c <= '9')
			k += c - '0';
		else
			k += c - 'A' + 10;

		if (i < s.size() - 1)
			k *= b;
	}

	printf("%d", k);

	return 0;
}