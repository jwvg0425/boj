#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string display;

		std::cin >> display;

		int k = 0;
		int d = 1;

		for (int j = display.size() - 1; j >= 0; j--)
		{
			k += d * (display[j] - '0');
			d *= 2;
		}

		printf("%d\n", k);
	}

	return 0;
}