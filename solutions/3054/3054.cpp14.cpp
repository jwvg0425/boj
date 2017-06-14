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
	std::string str;

	std::cin >> str;

	for (int h = 0; h < 5; h++)
	{
		for (int w = 0; w < 4 * str.size() + 1; w++)
		{
			if (h == 0 || h == 4)
			{
				if ((w + 2) % 12 == 0)
					printf("*");
				else if ((w + 2) % 4 == 0)
					printf("#");
				else
					printf(".");
			}
			else if (h == 1 || h == 3)
			{
				if (w % 2 == 1)
					if ((w / 2) % 6 >= 4)
						printf("*");
					else
						printf("#");
				else
					printf(".");
			}
			else if (h == 2)
			{
				if (w % 2 == 0)
					if ((w + 2) % 4 == 0)
						printf("%c", str[w / 4]);
					else if (w == 4 * str.size() && str.size() % 3 == 2)
						printf("#");
					else if ((w / 2 - 4) % 6 == 0 || (w / 2 - 4) % 6 == 2)
						printf("*");
					else
						printf("#");
				else
					printf(".");
			}
		}
		printf("\n");
	}

	return 0;
}