#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int n, n2;
	scanf("%d %d", &n, &n2);

	std::string a, b;

	std::cin >> a >> b;

	int t;
	scanf("%d", &t);

	std::reverse(a.begin(), a.end());

	int pos = a.size() - t;

	for (int i = 0; i < b.size(); i++)
	{
		a.insert(a.begin() + std::max(i, pos), b[i]);
		pos = std::min<int>(pos + 2, a.size());
	}

	std::cout << a;


	return 0;
}