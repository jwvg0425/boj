#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <memory.h>
#include <math.h>

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	if (a.size() < b.size())
		std::swap(a, b);

	for (int i = 0; i < a.size(); i++)
	{
		if (i < a.size() - b.size())
			printf("%c", a[i]);
		else
			printf("%d", a[i] + b[i - a.size() + b.size()] - '0' * 2);
	}

	return 0;
}