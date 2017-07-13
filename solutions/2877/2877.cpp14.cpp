#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int main()
{
	int k;
	scanf("%d", &k);

	std::string res;

	while (k > 0)
	{
		if ((k-1) % 2 == 0)
			res.push_back('4');
		else
			res.push_back('7');
		
		k = (k-1) / 2;
	}

	std::reverse(res.begin(), res.end());

	std::cout << res;

	return 0;
}