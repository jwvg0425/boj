#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int n;
	scanf("%d", &n);

	long long int len = 0;
	int d = 1;
	int c = 1;

	while (d <= n)
	{
		if (d * 10 <= n)
		{
			len += c * d * 9;
		}
		else
		{
			len += c * (n - d + 1);
		}

		d *= 10;
		c++;
	}

	printf("%lld", len);

	return 0;
}