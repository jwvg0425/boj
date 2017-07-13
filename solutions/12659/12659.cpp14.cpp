#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

using ii = std::pair<int, int>;

std::string paragraph;
std::string welcome = "welcome to code jam";
int table[501][19];

int count(int pi, int wi)
{
	if (wi == welcome.size())
		return 1;

	if (pi == paragraph.size())
		return 0;

	if (table[pi][wi] != -1)
		return table[pi][wi];

	int& res = table[pi][wi];
	res = count(pi + 1, wi);

	if (paragraph[pi] == welcome[wi])
	{
		res += count(pi + 1, wi + 1);
	}

	res %= 10000;

	return res;
}

int solve()
{
	memset(table, -1, sizeof(table));

	std::getline(std::cin, paragraph);

	return count(0, 0);
}

int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: %04d\n", i, solve());
	}

	return 0;
}