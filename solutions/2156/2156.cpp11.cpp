#include <stdio.h>
#include <algorithm>

int table[10002][3];
int value;

int main()
{
	int n;-

	scanf("%d", &n);

	for (int i = 2; i < n + 2; i++)
	{
		int value;
		scanf("%d", &value);

		//이전에 연속해서 마신게 없는 경우 - 바로전 거는 마시면 안 됨 
		table[i][0] = value + table[i - 2][2];
		table[i][1] = value + table[i - 1][0];

		table[i][2] = std::max({ table[i-1][2], table[i][0], table[i][1] });
	}

	printf("%d", table[n+1][2]);

	return 0;
}