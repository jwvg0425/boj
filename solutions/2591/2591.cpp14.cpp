#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>


std::string password;

int table[41];

int solve(int k)
{
	if (k == password.size())
		return 1;

	if (password[k] == '0')
		return 0;

	if (table[k] != -1)
		return table[k];

	int& res = table[k];

	res = solve(k + 1);

	if (password[k] == '1' || password[k] == '2' || 
		(k < password.size() - 1 && password[k] == '3' && password[k + 1] <= '4'))
		res = (res + solve(k + 2));

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	std::cin >> password;

	printf("%d", solve(0));

	return 0;
}