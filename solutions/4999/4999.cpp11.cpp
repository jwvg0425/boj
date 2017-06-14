#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	std::string s1, s2;

	std::cin >> s1 >> s2;

	std::cout << ((s1.size() >= s2.size()) ? "go" : "no");
}