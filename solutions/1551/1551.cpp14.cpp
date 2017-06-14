#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	std::string s;

	std::cin >> s;
	s.push_back(',');

	std::vector<int> v;
	
	int prev = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ',')
		{
			v.push_back(std::stoi(s.substr(prev, i - prev)));
			prev = i + 1;
		}
	}

	for (int i = 0; i < k; i++)
	{
		std::vector<int> v2;

		for (int j = 1; j < v.size(); j++)
		{
			v2.push_back(v[j] - v[j - 1]);
		}

		v = v2;
	}

	for (int i = 0; i < v.size(); i++)
	{
		printf("%d", v[i]);

		if (i != v.size() - 1)
			printf(",");
	}

	return 0;
}