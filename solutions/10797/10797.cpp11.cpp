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

	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		int val;
		scanf("%d", &val);
		
		if (val == n)
			count++;
	}

	printf("%d", count);
}