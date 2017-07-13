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
#include <time.h>
int main()
{
	int n, k;
	while (~scanf("%d %d", &n, &k))
	{
		int count = n;
		int coupon = n;

		while (coupon >= k)
		{
			int chicken = coupon / k;
			count += chicken;

			coupon %= k;
			coupon += chicken;
		}

		printf("%d\n", count);
	}

	return 0;
}