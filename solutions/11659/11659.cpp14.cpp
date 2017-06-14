#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class FenwickTree
{
public:
	FenwickTree(int k)
	{
		data.resize(k);
	}

	long long int sum(int n)
	{
		long long int ans = 0;

		while (n > 0)
		{
			ans += data[n];
			n -= (n & -n);
		}

		return ans;
	}

	void add(int n, long long int num)
	{
		while (n < data.size())
		{
			data[n] += num;
			n += (n & -n);
		}
	}

private:
	std::vector<long long int> data;
};

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	FenwickTree tree(n * 4);

	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);

		tree.add(i, a);
	}

	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		printf("%lld\n", tree.sum(e) - tree.sum(s-1));
	}



	return 0;
}