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
	int in[5] = { 0, };

	in[1] = 1;
	in[4] = 2;
	
	std::string swap;

	std::cin >> swap;

	for (auto& s : swap)
	{
		switch (s)
		{
		case 'A':
			std::swap(in[1], in[2]);
			break;
		case 'B':
			std::swap(in[1], in[3]);
			break;
		case 'C':
			std::swap(in[1], in[4]);
			break;
		case 'D':
			std::swap(in[2], in[3]);
			break;
		case 'E':
			std::swap(in[2], in[4]);
			break;
		case 'F':
			std::swap(in[3], in[4]);
			break;
		}
	}

	for (int i = 1; i <= 4; i++)
		if (in[i] == 1)
			printf("%d\n", i);

	for (int i = 1; i <= 4; i++)
		if (in[i] == 2)
			printf("%d\n", i);

	return 0;
}