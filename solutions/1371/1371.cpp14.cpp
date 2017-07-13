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

int main()
{
	int count[26] = { 0, };
	std::string str;

	while (std::getline(std::cin, str))
	{
		for (auto& c : str)
		{
			if(c >= 'a' && c <= 'z')
				count[c - 'a']++;
		}
	}

	int max = 0;

	for (int i = 0; i < 26; i++)
	{
		max = std::max(max, count[i]);
	}

	for (int i = 0; i < 26; i++)
	{
		if(count[i] == max)
			printf("%c", i + 'a');
	}

	return 0;
}