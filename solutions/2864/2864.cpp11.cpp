#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	std::string af, bf, as, bs;

	for (auto& ai : a)
	{
		if (ai == '5')
		{
			af.push_back(ai);
			as.push_back('6');
		}
		else if (ai == '6')
		{
			af.push_back('5');
			as.push_back(ai);
		}
		else
		{
			af.push_back(ai);
			as.push_back(ai);
		}
	}

	for (auto& bi : b)
	{
		if (bi == '5')
		{
			bf.push_back(bi);
			bs.push_back('6');
		}
		else if (bi == '6')
		{
			bf.push_back('5');
			bs.push_back(bi);
		}
		else
		{
			bf.push_back(bi);
			bs.push_back(bi);
		}
	}

	printf("%d %d", std::stoi(af) + std::stoi(bf), std::stoi(as) + std::stoi(bs));
}