#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::string str;
	int alphabet[27] = { 0, };

	std::cin >> str;

	for (auto& c : str)
	{
		alphabet[c - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << alphabet[i] << ' ';
	}
}