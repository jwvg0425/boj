#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>

int main()
{
	int t;
	scanf("%d", &t);

	std::vector<int> fibos;

	fibos.push_back(1);
	fibos.push_back(2);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		while (fibos.back() < n)
		{
			fibos.push_back(fibos[fibos.size() - 1] + fibos[fibos.size() - 2]);
		}

		std::vector<int> ans;

		for (int j = fibos.size() - 1; j >= 0; j--)
		{
			if (fibos[j] <= n)
			{
				ans.push_back(fibos[j]);
				n -= fibos[j];
			}

			if (n == 0)
				break;
		}

		std::reverse(ans.begin(), ans.end());

		for (auto& a : ans)
		{
			printf("%d ", a);
		}

		printf("\n");
	}

	return 0;
}