#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>

std::string octToBin(char c)
{
	switch (c)
	{
	case '0':
		return "000";
	case '1':
		return "001";
	case '2':
		return "010";
	case '3':
		return "011";
	case '4':
		return "100";
	case '5':
		return "101";
	case '6':
		return "110";
	case '7':
		return "111";
	}
}

int main()
{
	std::string oct;

	std::cin >> oct;

	if (oct == "0")
	{
		printf("0");
		return 0;
	}

	std::string bin;

	for (auto& c : oct)
	{
		auto o = octToBin(c);

		if (bin.empty())
		{
			while (o[0] == '0')
			{
				o.erase(o.begin());
			}
		}

		bin.insert(bin.end(), o.begin(), o.end());
	}

	std::cout << bin;


}