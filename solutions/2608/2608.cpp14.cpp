#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

std::string rome(int k)
{
	std::string digit = "IXCM";
	std::string fiveDigit = "VLD";

	int d = 0;
	std::string res;

	while (k > 0)
	{
		int n = k % 10;

		if (n == 4)
		{
			res.push_back(fiveDigit[d]);
			res.push_back(digit[d]);
		}
		else if (n == 9)
		{
			res.push_back(digit[d + 1]);
			res.push_back(digit[d]);
		}
		else
		{
			for (int i = 0; i < n % 5; i++)
			{
				res.push_back(digit[d]);
			}

			if (n >= 5)
				res.push_back(fiveDigit[d]);
		}

		k /= 10;
		d++;
	}

	std::reverse(res.begin(), res.end());

	return res;
}

int arabia(const std::string& r)
{
	std::string digit = "IVXLCDM__";
	int arabDigit[] = { 1,5,10,50,100,500,1000 };

	int res = 0;

	for (int i = 0; i < digit.size() - 2; i++)
	{
		for (int j = 0; j < r.size(); j++)
		{
			if (digit[i] != r[j])
				continue;

			if (j < r.size() - 1 && (r[j + 1] == digit[i + 1] || r[j + 1] == digit[i + 2]))
			{
				res -= arabDigit[i];
			}
			else
			{
				res += arabDigit[i];
			}
		}
	}

	return res;
}

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	int sum = arabia(a) + arabia(b);

	std::cout << sum << std::endl << rome(sum);

	return 0;
}