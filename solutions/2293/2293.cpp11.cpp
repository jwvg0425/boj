#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

int arr[2][10001];
std::vector<int> currency;

//0~n번째까지 동전 이용해서 k원 만들기
int solve(int k, int n)
{
	arr[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int c = 0; c <= k; c++)
		{
			if (i == 0 && c == 0)
			{
				arr[i][c] = 1;
				continue;
			}

			arr[i % 2][c] = 0;

			if(i >= 1)
				arr[i % 2][c] += arr[(i - 1) % 2][c];

			if (c >= currency[i])
				arr[i % 2][c] += arr[i % 2][c - currency[i]];
		}
	}

	return arr[(n - 1) % 2][k];
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		int value;

		scanf("%d", &value);

		currency.push_back(value);
	}

	std::sort(currency.begin(), currency.end());

	printf("%d", solve(k, n));

	return 0;
}