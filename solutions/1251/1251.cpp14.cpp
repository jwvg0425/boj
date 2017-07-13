#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	std::string word;
	std::cin >> word;

	std::string min;

	for (int i = 1; i < word.size(); i++)
	{
		for (int k = i + 1; k < word.size(); k++)
		{
			std::string f = word.substr(0, i);
			std::string m = word.substr(i, k - i);
			std::string b = word.substr(k);

			std::reverse(f.begin(), f.end());
			std::reverse(m.begin(), m.end());
			std::reverse(b.begin(), b.end());

			if (min.empty() || f + m + b < min)
				min = f + m + b;
		}
	}

	std::cout << min;
}