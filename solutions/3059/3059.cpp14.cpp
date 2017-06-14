#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

void solve()
{
	std::string str;

	std::cin >> str;

	bool exist[27] = { false, };

	for (auto& c : str)
	{
		exist[c - 'A'] = true;
	}

	int sum = 0;

	for (char t = 'A'; t <= 'Z'; t++)
	{
		if (!exist[t - 'A'])
			sum += t;
	}

	std::cout << sum << std::endl;

}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}
	
	return 0;
}