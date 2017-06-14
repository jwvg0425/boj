#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	std::string str;

	std::cin >> str;

	std::string str2 = str;

	std::reverse(str2.begin(), str2.end());

	printf("%d", str == str2 ? 1 : 0);

	return 0;
}