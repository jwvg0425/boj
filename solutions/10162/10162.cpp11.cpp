#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	int n;

	scanf("%d", &n);

	if (n % 10 != 0)
	{
		printf("-1");
		return 0;
	}

	printf("%d %d %d", n / 300, (n % 300) / 60, (n % 60) / 10);
}