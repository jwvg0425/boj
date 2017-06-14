#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include<time.h>
#include <queue>

int main()
{
	std::string aeiou = "aeiou";
	std::string str;

	std::getline(std::cin, str);

	int i = 0;

	for (int i = 0; i < str.size(); i++)
	{
		std::cout << str[i];

		if (std::find(aeiou.begin(), aeiou.end(), str[i]) != aeiou.end())
		{
			//모음 - 건너뛰기
			i += 2;
		}
	}

	return 0;
}