#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::set<std::string> remain;

	for (int i = 0; i < n; i++)
	{
		std::string name, order;

		std::cin >> name >> order;

		if (order == "leave")
			remain.erase(name);
		else
			remain.insert(name);
	}

	for (auto r = remain.rbegin(); r != remain.rend(); r++)
		printf("%s\n", r->c_str());

	return 0;
}