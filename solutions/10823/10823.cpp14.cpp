#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;

int main()
{
	std::string total;

	std::string str;

	while (std::getline(std::cin, str))
	{
		total += str;
	}

	total.push_back(',');

	int prev = 0;
	int sum = 0;

	for (int i = 0; i < total.size(); i++)
	{
		if (total[i] == ',')
		{
			sum += std::stoi(total.substr(prev, i - prev));
			prev = i + 1;
		}
	}

	printf("%d", sum);

	return 0;
}