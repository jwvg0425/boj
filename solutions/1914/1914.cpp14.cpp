#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

void hanoi(int a, int b, int c, int n)
{
	if (n <= 1)
	{
		printf("%d %d\n", a, c);
		return;
	}
	else
	{
		hanoi(a, c, b, n - 1);
		printf("%d %d\n", a, c);
		hanoi(b, a, c, n - 1);
	}
}

int main()
{
	int n;
	long double k = 1.0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		k *= 2;


	char str[10000];

	sprintf(str, "%.0Lf", k);

	str[strlen(str) - 1]--;

	printf("%s\n", str);

	if (n <= 20)
		hanoi(1, 2, 3, n);

	return 0;
}