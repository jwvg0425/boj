#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	for(int i = 1; true; i++)
	{
		std::string a, b;

		std::cin >> a >> b;

		if (a == "END" && b == "END")
			break;

		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());

		if (a == b)
			printf("Case %d: same\n", i);
		else
			printf("Case %d: different\n", i);
	}

	return 0;
}