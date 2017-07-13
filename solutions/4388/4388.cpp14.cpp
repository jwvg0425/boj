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
	while (true)
	{
		std::string a, b;

		std::cin >> a >> b;

		if (a == "0" && b == "0")
			break;

		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());

		while (a.size() < b.size())
			a.push_back('0');

		while (b.size() < a.size())
			b.push_back('0');

		int count = 0;
		int carry = 0;

		for (int i = 0; i < a.size(); i++)
		{
			int s = a[i] + b[i] - '0' * 2 + carry;
			if (s >= 10)
			{
				carry = 1;
				count++;
			}
			else
			{
				carry = 0;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}