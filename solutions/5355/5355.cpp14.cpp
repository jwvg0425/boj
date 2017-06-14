#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>




int main()
{
	int t;
	scanf("%d\n", &t);

	for (int i = 0; i < t; i++)
	{
		std::string str;

		std::getline(std::cin, str);

		bool start = true;
		float k;

		for (int j = 0; j < str.size(); j++)
		{
			if (start)
			{
				if (str[j] == ' ')
				{
					std::string c = std::string(str.begin(), str.begin() + j);
					k = std::stof(c);
					start = false;
				}
			}
			else if(str[j]!= ' ')
			{
				if (str[j] == '@')
					k *= 3;
				else if (str[j] == '%')
					k += 5;
				else if (str[j] == '#')
					k -= 7;
			}
		}

		printf("%.2f\n", k);
	}
	return 0;
}