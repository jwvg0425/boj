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

int bases[1000001][11];

int solve()
{
	std::string s;

	std::getline(std::cin, s);

	std::vector<int> p;

	int i = 0;
	for (; i < s.size() - 2; i += 2)
	{
		p.push_back(std::stoi(s.substr(i, 1)));
	}

	p.push_back(std::stoi(s.substr(i)));

	//제일 작은 것부터 찾는다
	for (i = 2; true; i++)
	{
		bool find = true;

		for (auto& j : p)
		{
			if (bases[i][j] == -1)
			{
				//각 요소에 대해 해당 진법으로 happy한지 체크
				int icopy = i;

				std::vector<int> path;

				while (true)
				{
					if (bases[icopy][j] != -1 || icopy == 1)
					{
						break;
					}
					bases[icopy][j] = 0;

					path.push_back(icopy);

					int next = 0;

					while (icopy > 0)
					{
						int digit = icopy % j;
						next += digit *digit;
						icopy /= j;
					}

					icopy = next;
				}

				if (icopy == 1)
					bases[icopy][j] = 1;

				for (auto& p : path)
				{
					bases[p][j] = bases[icopy][j];
				}
			}

			if (bases[i][j] == 0)
			{
				find = false;
				break;
			}
		}

		if (find)
		{
			return i;
		}
	}
	
	return 0;
}


int main()
{
	memset(bases, -1, sizeof(bases));

	int t;
	scanf("%d\n", &t);

	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: %d\n", i, solve());
	}

	return 0;
}