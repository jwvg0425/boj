#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include<time.h>
#include <queue>

std::string dow[] =
{
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday"
};

int days[] =
{
	0,
	0,
	31,
	59,
	90,
	120,
	151,
	181,
	212,
	243,
	273,
	304,
	334
};

int main()
{
	int m, d;
	scanf("%d %d", &d, &m);

	std::cout << dow[(days[m] + d - 1) % 7];
	return 0;
}