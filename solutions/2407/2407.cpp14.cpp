#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

struct BigInt
{
	BigInt() {}

	BigInt(long long int k)
	{
		num = std::to_string(k);
		std::reverse(num.begin(), num.end());
	}

	std::string num;

	void print()
	{
		std::string r = num;

		std::reverse(r.begin(), r.end());

		std::cout << r << std::endl;
	}

	const BigInt& operator=(const BigInt& rhs)
	{
		num = rhs.num;

		return *this;
	}

	BigInt operator+(const BigInt& rhs)
	{
		BigInt res;
		int add = 0;

		for (int i = 0; i < std::min(num.size(), rhs.num.size()); i++)
		{
			int k = num[i] + rhs.num[i] + add - '0' * 2;
			add = k / 10;
			res.num.push_back(k % 10 + '0');
		}

		for (int j = std::min(num.size(), rhs.num.size()); j < std::max(num.size(), rhs.num.size()); j++)
		{
			if (num.size() > rhs.num.size())
			{
				int k = num[j] + add - '0';
				add = k / 10;
				res.num.push_back(k % 10 + '0');
			}
			else
			{
				int k = rhs.num[j] + add - '0';
				add = k / 10;
				res.num.push_back(k % 10 + '0');
			}
		}

		if (add != 0)
			res.num.push_back(add + '0');

		return res;
	}
};

BigInt table[101][101];

BigInt c(int n, int k)
{
	if (k > n)
		return 0;

	if (n == 1)
		return 1;

	if (k == 0)
		return 1;

	if (table[n][k].num != "")
		return table[n][k];

	return table[n][k] = c(n - 1, k) + c(n - 1, k - 1);
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	c(n, k).print();

	return 0;
}