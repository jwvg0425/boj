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
	std::string str;
	std::cin >> str;

	int original = std::stoi(str);

	std::string next = str;
	std::sort(next.begin(), next.end());

	int min = 0;

	do
	{
		int n = std::stoi(next);

		if (n > original && (min == 0 || n < min))
			min = n;

	} while (std::next_permutation(next.begin(), next.end()));

	printf("%d", min);
}