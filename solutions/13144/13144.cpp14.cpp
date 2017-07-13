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

using ii = std::pair<int, int>;

std::vector<int> arr;
int counts[100001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		arr.push_back(k);
	}

	int l = 0;
	int r = 0;

	long long int ans = 0;

	while (r < arr.size())
	{
		counts[arr[r]]++;

		while (counts[arr[r]] >= 2)
		{
			counts[arr[l]]--;
			l++;
		}
		ans += r - l + 1;
		r++;
	}

	printf("%lld", ans);

	return 0;
}