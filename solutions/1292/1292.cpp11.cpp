#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>

int main()
{
	int a, b;

	scanf("%d %d", &a,&b);

	int number = 1;
	int sum = 0;


	for (int i = a; i <= b; i++)
	{
		while ((number)*(number + 1) / 2 < i)
			number++;

		sum += number;
	}

	printf("%d", sum);
}