#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

std::map<std::string, int> cookie;
int sum = 0;

int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		
		sum++;

		if (sum - cookie[str] <= cookie[str])
			count++;

		cookie[str]++;
	}

	printf("%d", count);

	return 0;
}