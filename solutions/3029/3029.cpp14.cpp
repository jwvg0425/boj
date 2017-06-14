#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
using namespace std;

int toSecond(const std::string& str)
{
	int h = std::stoi(str.substr(0, 2));
	int m = std::stoi(str.substr(3, 2));
	int s = std::stoi(str.substr(6, 2));

	return h * 3600 + m * 60 + s;
}

void printStr(int sec)
{
	int h = sec / 3600;
	int m = (sec - (h * 3600)) / 60;
	int s = sec % 60;

	printf("%02d:%02d:%02d", h, m, s);
}

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	int r = toSecond(b) - toSecond(a);

	if (r <= 0)
		r += 60 * 60 * 24;

	printStr(r);

	return 0;
}