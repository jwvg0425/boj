#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

using ii = std::pair<int, int>;

//(strike, ball)
ii check(int ans, int call)
{
	ii res;

	int ad[] = { ans / 100, (ans / 10) % 10, ans % 10 };
	int cd[] = { call / 100, (call / 10) % 10,  call % 10 };

	for (int i = 0; i < 3; i++)
	{
		if (cd[i] == ad[i])
		{
			res.first++;
			continue;
		}

		for (int j = 0; j < 3; j++)
		{
			if (cd[i] == ad[j])
			{
				res.second++;
				break;
			}
		}
	}

	return res;
}

int main()
{
	std::vector<std::pair<int, ii>> q;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		q.push_back({ a, {b,c} });
	}

	int count = 0;

	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1; b <= 9; b++)
		{
			for (int c = 1; c <= 9; c++)
			{
				if (a == b || b == c || a == c)
					continue;

				bool allAc = true;

				for (auto& qi : q)
				{
					auto res = check(qi.first, a * 100 + b * 10 + c);

					if (res != qi.second)
					{
						allAc = false;
						break;
					}
				}

				if (allAc)
					count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}