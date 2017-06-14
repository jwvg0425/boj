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
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::getline(std::cin, str);

		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] = str[0] - 'a' + 'A';

		std::cout << str << std::endl;
	}

	return 0;
}