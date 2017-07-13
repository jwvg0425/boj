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

int main()
{
	std::string str, key;

	std::getline(std::cin, str);
	std::getline(std::cin, key);

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			printf(" ");
			continue;
		}

		printf("%c", 'a' + (str[i] + 25 - key[i%key.size()]) % 26);
	}

	return 0;
}