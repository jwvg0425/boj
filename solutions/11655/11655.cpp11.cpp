#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

int main()
{
	std::string str;
	std::getline(std::cin, str);

	for (auto& c : str)
	{
		if (c >= 'a' && c <= 'z')
		{
			c = (c - 'a' + 13) % 26 + 'a';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c = (c - 'A' + 13) % 26 + 'A';
		}
	}

	std::cout << str;

	return 0;
}