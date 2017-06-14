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
	std::string str;

	std::cin >> str;
	
	int ioi = 0;
	int joi = 0;

	for (int i = 0; i < str.size() - 2; i++)
	{
		std::string sub(str.begin() + i, str.begin() + i + 3);

		if (sub == "JOI")
			joi++;
		if (sub == "IOI")
			ioi++;
	}

	printf("%d\n%d", joi, ioi);
}