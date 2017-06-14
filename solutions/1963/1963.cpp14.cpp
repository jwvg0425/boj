#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>

bool isPrime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
			return false;
	}

	return true;
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		std::string a, b;

		std::cin >> a >> b;

		int visit[10001] = { 0, };

		std::queue<std::string> q;

		q.push(a);
		visit[std::stoi(a)] = 1;
		int ans = -1;

		while (!q.empty())
		{
			std::string now = q.front();
			q.pop();

			if (now == b)
			{
				ans = visit[std::stoi(now)];
			}

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					std::string change = now;
					change[i] = j + '0';
					int k = std::stoi(change);

					if (k >= 1000 && visit[k] == 0 && isPrime(k))
					{
						visit[k] = visit[std::stoi(now)] + 1;
						q.push(change);
					}
				}
			}
		}

		if (ans == -1)
			printf("Impossible\n");
		else
			printf("%d\n", ans - 1);
	}

	return 0;
}