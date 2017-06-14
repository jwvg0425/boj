#include<stdio.h>
#include<queue>

class FenwickTree
{
public:
	FenwickTree(int k)
	{
		data.resize(k);
	}

	long long int sum(int n)
	{
		if (n >= data.size())
			data.resize(n + 1);

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
		if (n >= data.size())
			data.resize(n + 1);

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
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	FenwickTree fenwick(n * 4);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		fenwick.add(i + 1, a);
	}

	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1)
		{
			long long int original = fenwick.sum(b) - fenwick.sum(b - 1);
			fenwick.add(b, c - original);
		}
		else
		{
			printf("%lld\n", fenwick.sum(c) - fenwick.sum(b - 1));
		}
	}
}