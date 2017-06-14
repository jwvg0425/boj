#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

int main()
{
	std::string s;

	std::cin >> s;

	std::sort(s.begin(), s.end(), [](const char& a, const char& b) { return b < a; });

	std::cout << s;
}