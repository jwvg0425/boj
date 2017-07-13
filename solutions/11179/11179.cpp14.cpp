#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

bool isPalindrome[2501][2501];

int main()
{
	int n;
	int rev = 0;
	scanf("%d", &n);

	while (n > 0)
	{
		rev *= 2;
		rev += n % 2;
		n /= 2;
	}

	printf("%d", rev);

	return 0;
}