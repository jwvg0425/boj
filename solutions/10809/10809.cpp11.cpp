#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>

int main()
{
	int pos[26];

	memset(pos, -1, sizeof(pos));

	std::string s;

	std::cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (pos[s[i] - 'a'] == -1)
		{
			pos[s[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", pos[i]);
	}
}