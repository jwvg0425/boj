#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	long long int n;
	scanf("%lld", &n);
	n %= 5;

	if (n == 1 || n == 3 || n == 4)
		printf("SK");
	else
		printf("CY");

	return 0;
}