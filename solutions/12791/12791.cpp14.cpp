#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

std::vector<std::pair<int, std::string>> list =
{
	{1967, "DavidBowie"										 },
	{1969, "SpaceOddity"										 },
	{1970, "TheManWhoSoldTheWorld"							 },
	{1971, "HunkyDory"										 },
	{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
	{1973, "AladdinSane"										 },
	{1973, "PinUps"											 },
	{1974, "DiamondDogs"										 },
	{1975, "YoungAmericans"									 },
	{1976, "StationToStation"									 },
	{1977, "Low"												 },
	{1977, "Heroes"											 },
	{1979, "Lodger"											 },
	{1980, "ScaryMonstersAndSuperCreeps"						 },
	{1983, "LetsDance"										 },
	{1984, "Tonight"											 },
	{1987, "NeverLetMeDown"									 },
	{1993, "BlackTieWhiteNoise"								 },
	{1995, "1.Outside"										 },
	{1997, "Earthling"										 },
	{1999, "Hours"											 },
	{2002, "Heathen"											 },
	{2003, "Reality"											 },
	{2013, "TheNextDay"										 },
	{2016, "BlackStar"										 },
};

int main()
{
	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		int l= -1, r = list.size();

		for (int i = 0; i < list.size(); i ++)
		{
			if (list[i].first >= s && l == -1)
				l = i;

			if (list[i].first > e && r == list.size())
				r = i;
		}

		printf("%d\n", r - l);

		for (int i = l; i < r; i++)
		{
			printf("%d %s\n", list[i].first, list[i].second.c_str());
		}
	}
	return 0;
}