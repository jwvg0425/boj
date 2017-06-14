#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int main()
{
	int n;
	scanf("%d", &n);

	std::string answer;
	std::stack<int> s;
	int nowVal = 1;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		while (nowVal <= a)
		{
			s.push(nowVal);
			nowVal++;
			answer.push_back('+');
		}

		if (s.empty() || s.top() != a)
		{
			printf("NO");
			return 0;
		}

		s.pop();
		answer.push_back('-');
	}

	for (auto& c : answer)
		printf("%c\n", c);

	return 0;
}