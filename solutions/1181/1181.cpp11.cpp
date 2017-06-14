#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	int n;
	std::vector<std::string> v;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string s;

		std::cin >> s;

		v.push_back(s);
	}

	std::sort(v.begin(), v.end(), [](const std::string& a, const std::string& b)
	{
		if (a.size() != b.size())
			return a.size() < b.size();

		return a < b;
	});

	for (int i = 0; i < v.size(); i++)
	{
		if (i > 0 && v[i - 1] == v[i])
			continue;

		std::cout << v[i] << std::endl;
	}
}