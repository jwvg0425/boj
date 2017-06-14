#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		int a;
		scanf("%d", &a);

		sum += std::max(40, a);
	}

	printf("%d", sum / 5);
}