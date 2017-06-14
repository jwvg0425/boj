#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int pos;
		std::string s;

		std::cin >> pos >> s;

		pos--;

		s.erase(s.begin() + pos);

		std::cout << s << std::endl;
	}
}