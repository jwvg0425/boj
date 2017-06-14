#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int sum(const std::vector<int>& vi)
{
	int s = 0;

	for (auto& i : vi)
		s += i;

	return s;
}

int main()
{
	std::vector<int> vi = { 64, };
	int x;

	scanf("%d", &x);

	while (sum(vi) > x)
	{
		std::sort(vi.begin(), vi.end());

		int v = vi[0] / 2;

		if (sum(vi) - v >= x)
		{
			vi[0] = v;
		}
		else
		{
			vi[0] = v;
			vi.push_back(v);
		}
	}

	printf("%d", vi.size());
}