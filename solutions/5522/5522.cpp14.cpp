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
	int s = 0;

	for (int i = 0; i < 5; i++)
	{
		int a;
		scanf("%d", &a);
		s += a;
	}

	printf("%d", s);

	return 0;
}