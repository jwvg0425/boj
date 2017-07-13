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

std::string order;
std::string bridge[2];
int table[2][101][21];

//bridge[line][pos]에서 시작하고 order[idx]~끝까지 밟는 경우의 수
int solve(int line, int pos, int idx)
{
	if (idx == order.size() - 1)
		return 1;

	if (table[line][pos][idx] != -1)
		return table[line][pos][idx];

	int& res = table[line][pos][idx];
	res = 0;

	int nextLine = (line + 1) % 2;

	for (int p = pos + 1; p < bridge[nextLine].size(); p++)
	{
		if (bridge[nextLine][p] == order[idx + 1])
		{
			res += solve(nextLine, p, idx + 1);
		}
	}

	return res;
}

int main()
{
	std::cin >> order >> bridge[0] >> bridge[1];

	bridge[0].insert(bridge[0].begin(), ' ');
	bridge[1].insert(bridge[1].begin(), ' ');
	order.insert(order.begin(), ' ');

	memset(table, -1, sizeof(table));

	printf("%d", solve(0, 0, 0) + solve(1, 0, 0));
	
	return 0;
}