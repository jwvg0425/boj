#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
int main()
{
	std::vector<int> cards[2];
	int wins[2] = { 0, };

	for (int p = 0; p < 2; p++)
	{
		for (int i = 0; i < 10; i++)
		{
			int card;
			scanf("%d", &card);
			cards[p].push_back(card);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (cards[0][i] > cards[1][i])
			wins[0]++;
		else if (cards[1][i] > cards[0][i])
			wins[1]++;
	}

	if (wins[0] == wins[1])
		printf("D");
	else if (wins[0] > wins[1])
		printf("A");
	else
		printf("B");

	return 0;
}