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
	int n;
	std::string seats;

	scanf("%d", &n);

	std::cin >> seats;

	int s = 0, l = 0;

	for (auto& seat : seats)
	{
		if (seat == 'S')
			s++;
		else
			l++;
	}

	printf("%d", std::min(s + l / 2 + 1, n));

	return 0;
}