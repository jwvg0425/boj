#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

int rev(int k)
{
	std::string str = std::to_string(k);
	std::reverse(str.begin(), str.end());

	return std::stoi(str);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		k += rev(k);

		printf("%s\n", k == rev(k) ? "YES" : "NO");
	}

	return 0;
}