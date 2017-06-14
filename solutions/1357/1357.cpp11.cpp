#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int rev(int n)
{
	std::string s = std::to_string(n);

	std::reverse(s.begin(), s.end());

	return std::stoi(s);
}

int main()
{
	int x, y;
	
	scanf("%d %d", &x, &y);

	printf("%d", rev(rev(x) + rev(y)));

	return 0;
}