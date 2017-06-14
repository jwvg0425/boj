#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string s;
		std::cin >> s;
		printf("%s\n", (s.back() - '0') % 2 == 0 ? "even" : "odd");
	}
	return 0;
}