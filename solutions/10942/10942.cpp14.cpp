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

// table[a][b] = a에서 b까지 구간이 팰린드롬인가 아닌가
int table[2001][2001];
std::vector<int> num;

int isPalindrome(int a, int b)
{
	if (b < a)
		return 1;

	if (a == b)
		return 1;
	
	if (table[a][b] != -1)
		return table[a][b];

	if (num[a] != num[b])
		return table[a][b] = 0;

	return table[a][b] = isPalindrome(a + 1, b - 1);
}

int main()
{
	int n;
	scanf("%d", &n);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < n; i ++)
	{
		int k;
		scanf("%d", &k);
		num.push_back(k);
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", isPalindrome(s - 1, e - 1));
	}

	return 0;
}