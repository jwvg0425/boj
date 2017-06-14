#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int getVal(const std::string& s)
{
	if (s == "black")
		return 0;
	if (s == "brown")
		return 1;
	if (s == "red")
		return 2;
	if (s == "orange")
		return 3;
	if (s == "yellow")
		return 4;
	if (s == "green")
		return 5;
	if (s == "blue")
		return 6;
	if (s == "violet")
		return 7;
	if (s == "grey")
		return 8;
	if (s == "white")
		return 9;
}

int main()
{
	std::string c1, c2, c3;

	std::cin >> c1 >> c2 >> c3;

	long long int v = getVal(c1) * 10 + getVal(c2);
	long long int m = 1;
	int t = getVal(c3);

	for (int i = 0; i < t; i++)
		m *= 10;

	printf("%lld", m*v);
}