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
#include <bitset>

long long int table[64][64];

long long int solve(int sec, int height)
{
	//수면에 닿아버리는 경우 제외
	if (height == 0)
		return 0;

	//남은 시간이 0 - 가짓수 1
	if (sec == 0)
		return 1;
	
	if (table[sec][height] != -1)
		return table[sec][height];

	return table[sec][height] = solve(sec - 1, height - 1) + solve(sec - 1, height + 1);
}

int main()
{
	memset(table, -1, sizeof(table));
	int k, n;
	scanf("%d %d", &k, &n);

	printf("%lld", solve(n, k));

	return 0;
}