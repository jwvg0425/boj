#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MOD 1234567

using ii = std::pair<int, int>;

int main()
{
	int n;
	scanf("%d\n", &n);

	long long int sum = 0;
	int num = 0;
	int digit = 0;

	for (int i = 0; i < n; i++)
	{
		char c;
		scanf("%c", &c);
		if (c >= '0' && c <= '9')
		{
			if (digit <= 6)
			{
				num *= 10;
				num +=c - '0';
				digit++;
			}
		}
		else
		{
			if (digit <= 6)
			{
				sum += num;
			}
			num = 0;
			digit = 0;
		}
	}

	if (digit <= 6)
		sum += num;

	printf("%lld", sum);

	return 0;
}