#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	while (true)
	{
		int arr[3];

		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &arr[i]);
		}

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;

		std::sort(arr, arr + 3);

		printf("%s\n", (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1]) ? "right" : "wrong");
	}

	return 0;
}