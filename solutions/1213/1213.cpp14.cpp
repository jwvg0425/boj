#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int main()
{
	std::string s;

	std::cin >> s;

	int count[26] = { 0, };

	for (auto& c : s)
		count[c - 'A']++;

	int oddCounts = 0;
	char oddChar;

	for (int i = 0; i < 26; i++)
	{
		if (count[i] % 2 == 1)
		{
			oddCounts++;
			oddChar = i + 'A';
		}
	}

	int limitOdd = 0;

	if (s.size() % 2 == 1)
		limitOdd = 1;

	if (oddCounts > limitOdd)
	{
		printf("I'm Sorry Hansoo");
		return 0;
	}

	std::string palindrome;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < count[i] / 2; j++)
		{
			int mid = palindrome.size() / 2;
			palindrome.insert(palindrome.begin() + mid, 'A' + i);
			palindrome.insert(palindrome.begin() + mid, 'A' + i);
		}
	}

	if (s.size() % 2 == 1)
		palindrome.insert(palindrome.begin() + (palindrome.size() / 2), oddChar);

	std::cout << palindrome;

	return 0;
}