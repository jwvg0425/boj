#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int arr[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);

		sum += arr[i];
	}

	std::sort(arr, arr + 9);

	int s = 0, e = 8;

	while (arr[s] + arr[e] != sum - 100)
	{
		if (arr[s] + arr[e] > sum - 100)
			e--;
		else
			s++;
	}

	for (int i = 0; i < 9; i++)
	{
		if (i == s || i == e)
			continue;

		printf("%d\n", arr[i]);
	}
}