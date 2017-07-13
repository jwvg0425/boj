#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <memory.h>
#include <math.h>

int main()
{
	int counts[26] = { 0, };

	std::string a, b;
	std::cin >> a >> b;

	for (auto& c : a)
		counts[c - 'a']++;

	for (auto& c : b)
		counts[c - 'a']--;

	int min = 0;

	for (int i = 0; i < 26; i++)
		min += abs(counts[i]);

	printf("%d", min);
}