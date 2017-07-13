#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

std::vector<int> pre;
std::vector<int> in;
std::vector<int> post;

void makePost(int pl, int pr, int il, int ir)
{
	if (pl > pr)
		return;

	if (pl == pr)
	{
		post.push_back(pre[pl]);
		return;
	}

	int root = pre[pl];

	int rootIdx = il;

	while (in[rootIdx] != root)rootIdx++;

	int leftSize = rootIdx - il;
	int rightSize = ir - il - leftSize;

	makePost(pl + 1, pl + leftSize, il, rootIdx - 1);
	makePost(pl + leftSize + 1, pr, rootIdx + 1, ir);

	post.push_back(root);
}

void solve()
{
	pre.clear();
	in.clear();
	post.clear();

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);
		pre.push_back(p);
	}

	for (int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);
		in.push_back(p);
	}

	makePost(0, n - 1, 0, n - 1);

	for (auto& p : post)
		printf("%d ", p);

	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}