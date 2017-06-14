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

char left[26];
char right[26];

void preorder(char r)
{
	printf("%c", r);

	if (left[r-'A'] != '.')
		preorder(left[r-'A']);

	if (right[r - 'A'] != '.')
		preorder(right[r-'A']);
}

void postorder(char r)
{
	if (left[r - 'A'] != '.')
		postorder(left[r-'A']);

	if (right[r - 'A'] != '.')
		postorder(right[r-'A']);

	printf("%c", r);
}

void inorder(char r)
{
	if (left[r - 'A'] != '.')
		inorder(left[r-'A']);
	
	printf("%c", r);

	if (right[r - 'A'] != '.')
		inorder(right[r-'A']);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string a, b, c;

		std::cin >> a >> b >> c;
		left[a[0] - 'A'] = b[0];
		right[a[0] - 'A'] = c[0];
	}

	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');

	return 0;
}