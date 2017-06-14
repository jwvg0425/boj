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

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		std::string str;

		for (int j = 0; j < 10; j++)
		{
			int k;
			scanf("%d", &k);

			str.push_back(k + '0');
		}

		if (str == "1234512345")
		{
			printf("%d\n", i);
		}
	}

	return 0;
}