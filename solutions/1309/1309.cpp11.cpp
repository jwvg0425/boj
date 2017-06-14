#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

//0 - 0번 배치 1 - 1번 배치 2 - 둘다 배치 안 함
int table[100001][3];

int main()
{
	int n;

	scanf("%d", &n);

	table[0][0] = table[0][1] = table[0][2] = 1;

	for (int i = 1; i <= n; i++)
	{
		table[i][0] = (table[i-1][1] + table[i-1][2]) % 9901;
		table[i][1] = (table[i-1][0] + table[i-1][2]) % 9901;
		table[i][2] = (table[i-1][0] + table[i-1][1] + table[i-1][2]) % 9901;
	}

	printf("%d", table[n][2]);

	return 0;
}