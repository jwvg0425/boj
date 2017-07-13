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

using ii = std::pair<int, int>;

int main()
{
	std::string h;
	std::string n;

	std::cin >> h >> n;

	int count = 0;

	for (int i = 0; i < h.size(); i++)
	{
		if (h.substr(i, n.size()) == n)
			count++;
	}

	printf("%d", count);

	return 0;
}