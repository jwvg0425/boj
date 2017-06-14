#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int arr[10];

		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &arr[j]);
		}

		std::sort(arr, arr + 10);

		printf("%d\n", arr[7]);
	}
}