#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	std::string a, op, b;

	std::cin >> a >> op >> b;

	std::string res;

	if (a.size() > b.size())
		res = a;
	else
		res = b;

	if (op[0] == '+')
	{
		int index = std::max(a.size(), b.size()) - std::min(a.size(), b.size());
		res[index]++;
	}
	else
	{
		for (int i = 0; i < std::min(a.size(), b.size()) - 1; i++)
			res.push_back('0');
	}

	std::cout << res;

	return 0;
}