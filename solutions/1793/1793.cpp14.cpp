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

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		BigInt arr[251] = { 1, 1, 3 };

		for (int i = 3; i <= n; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 2];
		}

		arr[n].print();
	}
	return 0;
}