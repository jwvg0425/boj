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

int primes[2000000];

bool isPalindrome(int k)
{
	std::string s = std::to_string(k);
	std::string rev = s;

	std::reverse(rev.begin(), rev.end());

	return s == rev;
}

int main()
{

	for (int i = 2; i < 2000000; i++)
	{
		if (primes[i] != 0)
		{
			continue;
		}

		for (int j = i * 2; j < 2000000; j += i)
		{
			primes[j] = 1;
		}
	}

	int n;
	scanf("%d", &n);

	for (int i = n; i < 2000000; i++)
	{
		if (primes[i] != 0)
			continue;

		if (!isPalindrome(i))
			continue;

		printf("%d", i);
		break;
	}

	return 0;
}