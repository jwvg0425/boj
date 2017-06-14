#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

bool similar(const std::string& a, const std::string& b)
{
	int count[26] = { 0, };

	for (auto& c : a)
	{
		count[c - 'A']++;
	}

	for (auto& c : b)
	{
		count[c - 'A']--;
	}

	int plus = 0;
	int minus = 0;

	for (int i = 0; i < 26; i++)
	{
		if (count[i] > 0)
			plus += count[i];
		else if (count[i] < 0)
			minus -= count[i];
	}

	return plus <= 1 && minus <= 1;
}

int main()
{
	int n;
	scanf("%d", &n);

	std::string original;
	int count = 0;

	std::cin >> original;

	for (int i = 0; i < n - 1; i++)
	{
		std::string other;

		std::cin >> other;

		if (similar(original, other))
			count++;
	}

	printf("%d", count);

	return 0;
}