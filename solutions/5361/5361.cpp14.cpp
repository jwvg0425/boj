#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>

float price[] = { 350.34f, 230.9f, 190.55f, 125.3f, 180.9f };

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		float total = 0.0f;

		for (int j = 0; j < 5; j++)
		{
			int num;
			scanf("%d", &num);
			total += price[j] * num;
		}

		printf("$%.2f\n", total);
	}

	return 0;
}