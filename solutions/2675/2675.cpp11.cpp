#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

void solve()
{
	int n;
	std::string str;

	std::cin >> n >> str;

	for (auto c : str)
	{
		for (int i = 0; i < n; i++)
			std::cout << c;
	}

	std::cout << std::endl;
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}