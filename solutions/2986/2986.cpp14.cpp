#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>


int main()
{
	int n;
	scanf("%d", &n);

	int count = n - 1;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			count = n - (n / i);
			break;
		}
	}

	printf("%d", count);

	return 0;
}