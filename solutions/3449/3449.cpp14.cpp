#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string a;
		std::string b;
		int c = 0;

		std::cin >> a >> b;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
				c++;
		}

		printf("Hamming distance is %d.\n", c);
	}

	return 0;
}