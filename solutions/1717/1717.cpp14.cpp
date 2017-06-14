#include<stdio.h>
#include<queue>

std::vector<int> set;
std::vector<int> index[1000001];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
	{
		set.push_back(i);
		index[i].push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int c, a, b;

		scanf("%d %d %d", &c, &a, &b);

		if (c == 0)
		{
			int sa = set[a];
			int sb = set[b];

			if (sa == sb)
				continue;

			if (index[sa].size() < index[sb].size())
			{
				for (int i = 0; i < index[sa].size(); i++)
				{
					set[index[sa][i]] = sb;
					index[sb].push_back(index[sa][i]);
				}

				index[sa].clear();
			}
			else
			{
				for (int i = 0; i < index[sb].size(); i++)
				{
					set[index[sb][i]] = sa;
					index[sa].push_back(index[sb][i]);
				}

				index[sb].clear();
			}
		}
		else
		{
			if (set[a] == set[b])
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}