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
	std::string str;

	std::cin >> str;

	for (int length = str.size(); length < str.size() * 2; length++)
	{
		bool isPalindrome = true;

		for (int i = length / 2; i < length; i++)
		{
			if (i < str.size() && str[i] != str[length - i - 1])
			{
				isPalindrome = false;
				break;
			}
		}

		if (isPalindrome)
		{
			printf("%d", length);
			return 0;
		}
	}

	return 0;
}