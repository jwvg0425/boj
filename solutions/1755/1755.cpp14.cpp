#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int digits[] =
{
	9,
	4,
	8,
	7,
	2,
	1,
	6,
	5,
	0,
	3
};

int main()
{
	int m, n;
	std::vector<std::string> v;

	scanf("%d %d", &m, &n);

	for (int i = m; i <= n; i++)
	{
		v.push_back(std::to_string(i));
	}

	std::sort(v.begin(), v.end(), [](const std::string& l, const std::string& r)
	{
		int lc = digits[l[0] - '0'];
		int rc = digits[r[0] - '0'];

		if (lc < rc)
			return true;

		if (lc > rc)
			return false;

		if (l.size() > 1)
			lc = lc * 10 + digits[l[1] - '0'];

		if (r.size() > 1)
			rc = rc * 10 + digits[r[1] - '0'];

		return lc < rc;
	});

	int idx = 0;
	while (idx < v.size())
	{
		for (int i = 0; i < 10 && idx + i < v.size(); i++)
		{
			std::cout << v[idx + i] << ' ';
		}
		idx += 10;
		std::cout << std::endl;
	}

	return 0;
}