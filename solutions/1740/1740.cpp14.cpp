#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	long long int n;

	scanf("%lld", &n);

	long long int k = 0;
	long long int d = 1;

	while (n > 0)
	{
		k += (n % 2) * d;

		n /= 2;
		d *= 3;
	}

	printf("%lld", k);


	return 0;
}