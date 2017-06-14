#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>

int tosec(const std::string& str)
{
	int h = std::stoi(std::string(str.begin(), str.begin() + 2));
	int m = std::stoi(std::string(str.begin() + 3, str.begin() + 5));
	int s = std::stoi(std::string(str.begin() + 6, str.end()));

	return h * 3600 + m * 60 + s;
}

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	int atime = tosec(a);
	int btime = tosec(b);
	int diff = btime - atime;

	if (diff < 0)
		diff += 24 * 60 * 60;

	printf("%02d:%02d:%02d", diff / 3600, (diff % 3600) / 60, diff % 60);

	return 0;
}