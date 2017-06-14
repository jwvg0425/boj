#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		long long int arr[3];
		
		for (int j = 0; j < 3; j++)
			scanf("%lld", &arr[j]);

		std::sort(arr, arr + 3);

		printf("Scenario #%d:\n", i + 1);
		printf("%s\n\n", (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0]) ? "yes" : "no");
	}

	return 0;
}