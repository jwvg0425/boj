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

std::map<std::string, int> seller;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		seller[str]++;
	}

	std::string maxBook;
	int maxNum = 0;

	for (auto& p : seller)
	{
		if (p.second > maxNum || (p.second == maxNum && p.first < maxBook))
		{
			maxBook = p.first;
			maxNum = p.second;
		}
	}
	
	std::cout << maxBook;

	return 0;
}