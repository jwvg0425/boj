#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

void solve()
{
	int n;
	std::vector<std::pair<int, std::string>> arr;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int price;
		std::string name;
	
		std::cin >> price >> name;

		arr.emplace_back(price, name);
	}

	std::sort(arr.begin(), arr.end());

	std::cout << arr.back().second << std::endl;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}