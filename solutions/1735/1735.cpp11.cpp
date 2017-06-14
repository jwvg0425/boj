#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>


int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}


int main()
{
	int A0, B0;
	int A1, B1;

	scanf("%d %d %d %d", &A0, &B0, &A1, &B1);

	int B = lcm(B0, B1);
	A0 *= B / B0;
	A1 *= B / B1;

	int A = A0 + A1;

	int g = gcd(A, B);

	printf("%d %d", A / g, B / g);

	return 0;
}