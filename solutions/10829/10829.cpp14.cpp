#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	long long int n;
	scanf("%lld", &n);

	std::string bin;

	while (n > 0)
	{
		bin.push_back('0' + n % 2);
		n /= 2;
	}

	std::reverse(bin.begin(), bin.end());

	std::cout << bin;
	return 0;
}