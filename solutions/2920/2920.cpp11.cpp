#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int asc[] = { 1,2,3,4,5,6,7,8 };
int desc[] = { 8,7,6,5,4,3,2,1 };

int main()
{
	bool isAsc = true;
	bool isDesc = true;

	for (int i = 0; i < 8; i++)
	{
		int a;
		scanf("%d", &a);
		isAsc &= (a == asc[i]);
		isDesc &= (a == desc[i]);
	}

	if (isAsc)
		printf("ascending");
	else if (isDesc)
		printf("descending");
	else
		printf("mixed");

	return 0;
}