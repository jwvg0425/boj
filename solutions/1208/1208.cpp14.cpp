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

int s, n;
long long int count;

int arr[41];

std::map<int, int> m;

void combSum(int index, int sum)
{
	if (index == n / 2)
	{
		m[sum]++;
		return;
	}

	combSum(index + 1, sum + arr[index]);
	combSum(index + 1, sum);
}

void calc(int index, int sum)
{
	if (index == n)
	{
		count += m[s - sum];
		return;
	}

	calc(index + 1, sum + arr[index]);
	calc(index + 1, sum);
}

int main()
{
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	combSum(0, 0);
	calc(n / 2, 0);

	if (s == 0)
		count--;

	printf("%lld", count);

	return 0;
}