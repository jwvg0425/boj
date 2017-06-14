#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	std::vector<int> p;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		p.push_back(a);
	}

	std::sort(p.begin(), p.end());

	for (int i = 1; i < p.size(); i++)
	{
		p[i] += p[i - 1];
	}

	int sum = 0;

	for (auto& a : p)
		sum += a;

	printf("%d", sum);

	return 0;
}