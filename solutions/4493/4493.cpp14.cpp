#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>
#include<set>

void solve()
{
	int n;
	scanf("%d\n", &n);
	int win1 = 0;
	int win2 = 0;

	for (int i = 0; i < n; i++)
	{
		std::string s;
		std::getline(std::cin, s);

		char p1 = s[0];
		char p2 = s[2];

		if (p1 == 'R' && p2 == 'P')
			win2++;
		else if (p1 == 'P' && p2 == 'R')
			win1++;
		else if (p1 == 'P' && p2 == 'S')
			win2++;
		else if (p1 == 'S' && p2 == 'P')
			win1++;
		else if (p1 == 'S' && p2 == 'R')
			win2++;
		else if (p1 == 'R' && p2 == 'S')
			win1++;
	}

	if (win1 == win2)
		printf("TIE\n");
	else if (win1 > win2)
		printf("Player 1\n");
	else
		printf("Player 2\n");
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;
}