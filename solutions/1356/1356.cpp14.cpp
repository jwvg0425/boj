#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int mult(const std::string& s)
{
	int k = s[0] - '0';

	for (int i = 1; i < s.size(); i++)
		k *= s[i] - '0';

	return k;
}

int main()
{
	std::string n;

	std::cin >> n;

	for (int split = 1; split < n.size(); split++)
	{
		if (mult(n.substr(0, split)) == mult(n.substr(split)))
		{
			printf("YES");
			return 0;
		}
	}

	printf("NO");

	return 0;
}