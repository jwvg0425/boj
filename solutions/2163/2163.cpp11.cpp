#include <stdio.h>
#include <algorithm>
#include <memory.h>

int table[301][301];

int solve(int n, int m)
{
	if (n == 1 && m == 1)
		return 0;

	if (table[n][m] != -1)
		return table[n][m];

	//n,m 각각에 대해 자를 수 있는 위치 모두 테스트

	int& res = table[n][m];
	res = 0;

	for (int i = 1; i < n; i++)
	{
		res = std::max(res, 1 + solve(i, m) + solve(n - i, m));
	}

	for (int i = 1; i < m; i++)
	{
		res = std::max(res, 1 + solve(n, i) + solve(n, m - i));
	}

	return res;
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	memset(table, -1, sizeof(table));

	printf("%d", solve(n, m));

	return 0;
}