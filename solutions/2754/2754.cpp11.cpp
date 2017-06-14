#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	std::string str;

	std::cin >> str;

	float avr = 0.0f;

	if (str[0] == 'A')
		avr += 4.0f;
	else if (str[0] == 'B')
		avr += 3.0f;
	else if (str[0] == 'C')
		avr += 2.0f;
	else if (str[0] == 'D')
		avr += 1.0f;

	if (str.size() > 1)
	{
		if (str[1] == '+')
			avr += 0.3f;
		else if (str[1] == '-')
			avr -= 0.3f;
	}

	printf("%.1f", avr);

	return 0;
}