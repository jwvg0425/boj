#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	for (int i = 0; i < 3; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		int s = a + b + c + d;

		switch (s)
		{
		case 0:
			printf("D\n");
			break;
		case 1:
			printf("C\n");
			break;
		case 2:
			printf("B\n");
			break;
		case 3:
			printf("A\n");
			break;
		case 4:
			printf("E\n");
			break;
		}
	}
}