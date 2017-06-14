#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int main()
{
	int n;
	std::string s;
	std::cin >> n >> s;
	int a = 0;
	int b = 0;

	for (auto& c : s)
	{
		if (c == 'A')
			a++;
		else
			b++;
	}

	if (a > b)
		printf("A");
	else if (a == b)
		printf("Tie");
	else
		printf("B");
}