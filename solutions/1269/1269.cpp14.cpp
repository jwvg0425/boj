#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> a;
	std::vector<int> b;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		a.push_back(k);
	}

	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		b.push_back(k);
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	int aidx = 0;
	int bidx = 0;

	int count = 0;

	while (aidx < a.size() && bidx < b.size())
	{
		if (a[aidx] == b[bidx])
		{
			aidx++;
			bidx++;
		}
		else if (a[aidx] > b[bidx])
		{
			bidx++;
			count++;
		}
		else if (a[aidx] < b[bidx])
		{
			aidx++;
			count++;
		}
	}

	count += a.size() - aidx;
	count += b.size() - bidx;

	printf("%d", count);

	return 0;
}