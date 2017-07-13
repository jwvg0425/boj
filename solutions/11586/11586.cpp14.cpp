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
	int n;
	scanf("%d\n", &n);
	std::vector<std::string> mirror;

	for (int i = 0; i < n; i++)
	{
		std::string line;
		std::getline(std::cin, line);

		mirror.push_back(line);
	}

	int k;
	scanf("%d", &k);

	if (k == 2)
	{
		for (auto& s : mirror)
			std::reverse(s.begin(), s.end());
	}
	else if (k == 3)
	{
		std::reverse(mirror.begin(), mirror.end());
	}

	for (auto& s : mirror)
		std::cout << s << std::endl;

	return 0;
}