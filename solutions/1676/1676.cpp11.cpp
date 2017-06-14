#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;
	scanf("%d", &n);

	int k = 0;

	for (int i = 1; i <= n; i++)
	{
		int t = i;
		while (t != 0 && t % 5 == 0)
		{
			k++;
			t /= 5;
		}
	}

	printf("%d", k);
}