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

int main()
{
	int n;
	scanf("%d\n", &n);
	int cost = 0;

	for (int i = 0; i < n; i++)
	{
		std::string str;
		int h, m, d;
		std::getline(std::cin, str);

		h = std::stoi(str.substr(0, 2));
		m = std::stoi(str.substr(3, 2));
		d = std::stoi(str.substr(str.size() - 2));

		int now = m + h * 60;
		
		for (int j = now + 1; j <= now + d; j++)
		{
			if (j > 60 * 7 && j <= 60 * 19)
				cost += 10;
			else
				cost += 5;
		}
	}
	printf("%d", cost);

	return 0;
}