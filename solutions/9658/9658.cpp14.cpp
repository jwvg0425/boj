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

// table[a] = a개일 때 승자 1이면 선공 2면 후공
int table[1001];
int winner(int k)
{
	if (k == 1)
		return 2;

	if (k == 2)
		return 1;

	if (k == 3)
		return 2;

	if (k == 4)
		return 1;

	if (table[k] != 0)
		return table[k];

	int one = winner(k - 1);
	int three = winner(k - 3);
	int four = winner(k - 4);

	if (one == 2 || three == 2 || four == 2)
		table[k] = 1;
	else
		table[k] = 2;

	return table[k];
}

int main()
{
	int n;
	scanf("%d", &n);

	printf("%s", winner(n) == 1 ? "SK" : "CY");

	return 0;
}