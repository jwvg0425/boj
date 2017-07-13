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
#define MAX 987654321
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		for (auto& c : str)
		{
			c = (c - 'A' + 1) % 26 + 'A';
		}
		printf("String #%d\n", i+1);
		std::cout << str << std::endl << std::endl;
	}

	return 0;
}