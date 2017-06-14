#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	while (a.size() < b.size())
		a.push_back('0');

	while (b.size() < a.size())
		b.push_back('0');

	std::string c;
	int carry = 0;

	for (int i = 0; i < a.size(); i++)
	{
		int t = a[i] + b[i] - 2 * '0' + carry;

		carry = 0;

		if (t >= 2)
		{
			carry = 1;
			t -= 2;
		}

		c.push_back(t + '0');
	}

	c.push_back(carry + '0');

	while (c.size() > 1 && c.back() == '0')
		c.pop_back();

	std::reverse(c.begin(), c.end());

	std::cout << c;

	return 0;
}