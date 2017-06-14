#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int n;
	scanf("%d", &n);

	int num[26] = { 0, };
	std::string ok;

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::cin >> str;

		num[str[0] - 'a']++;

		if (num[str[0] - 'a'] == 5)
			ok.push_back(str[0]);
	}

	std::sort(ok.begin(), ok.end());

	if (ok.empty())
		printf("PREDAJA");
	else
		std::cout << ok;

	return 0;
}