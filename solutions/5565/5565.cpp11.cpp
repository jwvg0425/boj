#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>

int main()
{
	int total;

	scanf("%d", &total);

	for (int i = 0; i < 9; i++)
	{
		int price;

		scanf("%d", &price);

		total -= price;
	}

	printf("%d", total);
}