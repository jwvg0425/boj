#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <memory.h>
#define MAX 987654321

std::vector<int> child[51];
int parent[51];

int getLeafCount(int idx)
{
	if (child[idx].empty())
		return 1;

	int count = 0;
	for (auto& c : child[idx])
	{
		count += getLeafCount(c);
	}

	return count;
}

void remove(int idx)
{
	int p = parent[idx];
	for (int i = 0; i < child[p].size();i++)
	{
		if (child[p][i] == idx)
		{
			child[p].erase(child[p].begin() + i);
			break;
		}
	}

	parent[idx] = -1;
}

int main()
{
	int n;
	scanf("%d", &n);

	int root = 0;

	for (int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);

		parent[i] = p;

		if (p == -1)
		{
			root = i;
		}
		else
		{
			child[p].push_back(i);
		}
	}

	int removed;
	scanf("%d", &removed);

	remove(removed);

	if (removed == root)
	{
		printf("0");
		return 0;
	}


	printf("%d", getLeafCount(root));

	return 0;
}