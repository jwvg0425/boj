#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int arr[10];
	int max = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		max = std::max(max, arr[i]);
	}

	for (int i = 0; i < 9; i++)
	{
		if (arr[i] == max)
		{
			printf("%d\n%d", max, i + 1);
			return 0;
		}
	}

}