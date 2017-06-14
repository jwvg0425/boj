#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <memory.h>
#include <queue>
#define MAX 987654321

void solve()
{
	std::string a, b;

	std::cin >> a >> b;

	std::string oa = a, ob = b;

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	std::cout << oa << " & " << ob << " are" << (a == b ? "" : " NOT") << " anagrams." << std::endl;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}