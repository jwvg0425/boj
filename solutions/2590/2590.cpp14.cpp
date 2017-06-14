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
	int papers[6];
	int count = 0;

	for (int i = 0; i < 6; i++)
		scanf("%d", &papers[i]);

	//6x6
	count += papers[5];

	//5x5
	for (int i = 0; i < papers[4]; i++)
	{
		count++;
		papers[0] = std::max(0, papers[0] - 11);
	}

	//4x4
	for (int i = 0; i < papers[3]; i++)
	{
		count++;

		if (papers[1] >= 5)
		{
			papers[1] -= 5;
		}
		else
		{
			papers[1] = 0;
			papers[0] = std::max(0, papers[0] - 20);
		}
	}

	//3x3
	count += (papers[2] + 3) / 4;
	papers[2] %= 4;

	int x2num = 0;
	int x1num = 0;

	switch (papers[2])
	{
	case 0:
		//이경우는 2x2, 1x1에서 처리하면 됨
		break;
	case 1:
		x2num = 5;
		x1num = 7;
		break;
	case 2:
		x2num = 3;
		x1num = 6;
		break;
	case 3:
		x2num = 1;
		x1num = 5;
		break;
	}
	if (x2num > papers[1])
	{
		x1num += (x2num - papers[1]) * 4;
	}

	papers[1] = std::max(0, papers[1] - x2num);
	papers[0] = std::max(0, papers[0] - x1num);

	count += (papers[1] + 8) / 9;
	papers[1] %= 9;

	if(papers[1] != 0)
		papers[0] = std::max(0, papers[0] - 36 + 4 * papers[1]);

	count += (papers[0] + 35) / 36;

	printf("%d", count);

	return 0;
}