#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		double n;
		std::string x;

		std::cin >> n >> x;

		if (x == "kg")
		{
			printf("%.4lf lb\n", n * 2.2046);
		}
		else if (x == "lb")
		{
			printf("%.4lf kg\n", n * 0.4536);
		}
		else if (x == "l")
		{
			printf("%.4lf g\n", n * 0.2642);
		}
		else if (x == "g")
		{
			printf("%.4lf l\n", n * 3.7854);
		}
	}

	return 0;
}