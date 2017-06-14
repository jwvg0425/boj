#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int main()
{
	std::string s;
	int m;

	std::cin >> s >> m;

	int n = std::stoi(s);

	for (int i = 0; i < std::min<int>(m, n * s.size()); i++)
	{
		std::cout << s[i % s.size()];
	}

	return 0;
}