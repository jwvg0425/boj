#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> xs;
	std::vector<int> ys;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		xs.push_back(x);
		ys.push_back(y);
	}

	std::sort(xs.begin(), xs.end());
	std::sort(ys.begin(), ys.end());

	int midx = xs[xs.size() / 2];
	int midy = ys[ys.size() / 2];

	int sum = 0;

	for (int i = 0; i < xs.size(); i++)
	{
		sum += abs(midx - xs[i]);
		sum += abs(midy - ys[i]);
	}

	printf("%d", sum);


	return 0;
}