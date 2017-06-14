#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	int ai = std::stoi(a);
	int bi = std::stoi(b);

	printf("%d", std::max(ai, bi));
}