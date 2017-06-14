#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int main()
{
	std::vector<int> fbis;

	for (int i = 0; i < 5; i++)
	{
		std::string str;

		std::cin >> str;

		if (str.find("FBI") != -1)
		{
			fbis.push_back(i + 1);
		}
	}

	if (fbis.empty())
		printf("HE GOT AWAY!");
	else
	{
		for (auto& i : fbis)
		{
			printf("%d ", i);
		}
	}

	return 0;
}