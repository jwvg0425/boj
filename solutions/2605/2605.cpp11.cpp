#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	int n;
	std::vector<int> students;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);

		int offset = i - 1 - k;

		students.insert(students.begin() + offset, i);
	}

	for (auto& s : students)
	{
		printf("%d ", s);
	}

	return 0;
}