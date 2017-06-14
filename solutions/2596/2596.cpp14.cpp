#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	std::string arr[] =
	{
		"000000",
		"001111",
		"010011",
		"011100",
		"100110",
		"101001",
		"110101",
		"111010"
	};

	int n;
	scanf("%d", &n);

	std::string str;

	std::cin >> str;

	std::string out;

	for (int i = 0; i < n * 6; i += 6)
	{
		int c = 8;

		for (int j = 0; j < 8; j++)
		{
			int t = 0;
			for (int k = 0; k < 6; k++)
			{
				if (arr[j][k] != str[i + k])
					t++;
			}

			if (t < 2)
				c = j;
		}

		if (c >= 8)
		{
			printf("%d", (i + 6)/ 6);
			return 0;
		}

		out.push_back('A' + c);
	}

	std::cout << out;

	return 0;
}