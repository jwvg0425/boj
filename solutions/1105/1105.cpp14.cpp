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
	std::string l, r;

	std::cin >> l >> r;

	if (r.size() > l.size())
	{
		printf("0");
		return 0;
	}

	int count = 0;

	for (int i = 0; i < l.size(); i++)
	{
		if (l[i] != r[i])
			break;

		if (l[i] == '8')
			count++;
	}

	printf("%d", count);

	return 0;
}