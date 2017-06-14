#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<long long int> cand;

void make(long long int k)
{
	cand.push_back(k);

	for (int i = 0; i < k % 10; i++)
	{
		make(k * 10 + i);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i <= 9; i++)
		make(i);

	std::sort(cand.begin(), cand.end());

	if (n > cand.size())
	{
		printf("-1");
		return 0;
	}

	printf("%lld", cand[n-1]);

	return 0;
}