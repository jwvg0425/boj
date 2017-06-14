#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int main()
{
	std::string a, b, c, d;
	std::cin >> a >> b >> c >> d;

	printf("%lld", std::stoll(a + b) + std::stoll(c + d));

	return 0;
}