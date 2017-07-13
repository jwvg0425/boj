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

int main()
{
	while (true)
	{
		int arr[3];

		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;

		std::sort(arr, arr + 3);

		if (arr[2] >= arr[0] + arr[1])
			printf("Invalid\n");
		else if (arr[0] == arr[1] && arr[1] == arr[2])
			printf("Equilateral\n");
		else if (arr[0] == arr[1] || arr[1] == arr[2])
			printf("Isosceles\n");
		else
			printf("Scalene\n");
	}

	return 0;
}