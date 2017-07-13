#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		std::string a, b;

		std::cin >> a >> b;

		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());

		std::string s;

		int j = 0;
		int carry = 0;

		for (; j < std::min(a.size(), b.size()); j++)
		{
			int t = a[j] + b[j] - 2 * '0' + carry;

			if (t >= 2)
			{
				carry = 1;
				t -= 2;
			}
			else
			{
				carry = 0;
			}

			s.push_back(t + '0');
		}

		while (j < a.size())
		{
			int t = a[j] + carry;

			if (t >= '2')
			{
				carry = 1;
				t -= 2;
			}
			else
			{
				carry = 0;
			}

			s.push_back(t);
			j++;
		}

		while (j < b.size())
		{
			int t = b[j] + carry;
			if (t >= '2')
			{
				carry = 1;
				t -= 2;
			}
			else
			{
				carry = 0;
			}

			s.push_back(t);
			j++;
		}

		if (carry == 1)
			s.push_back('1');

		while (s.size() > 1 && s.back() == '0')
			s.pop_back();

		std::reverse(s.begin(), s.end());

		std::cout << s << std::endl;
	}

	return 0;
}