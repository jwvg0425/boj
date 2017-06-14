#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	bool rooms[101] = { false, };
	int count[101] = { 0, };

	for (int n = 1; n <= 100; n++)
	{
		for (int i = n; i <= 100; i += n)
		{
			rooms[i] = !rooms[i];
		}

		for (int i = 1; i <= n; i++)
			if (rooms[i])
				count[n]++;
	}

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		printf("%d\n", count[n]);
	}
	
	return 0;
}