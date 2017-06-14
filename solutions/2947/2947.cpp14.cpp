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
#define MAX 987654321

std::vector<int> arr;

void print()
{
	for (auto& a : arr)
	{
		printf("%d ", a);
	}

	printf("\n");
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		int k;
		scanf("%d", &k);
		arr.push_back(k);
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				print();
			}
		}
	}

	return 0;
}