#include <stdio.h>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

int H, W;
char data[11][11];

struct Board
{
	Board() = default;

	std::string route;
	std::vector<std::pair<int, int>> pos;

	unsigned long long index()
	{
		unsigned long long res = 0;

		for (auto& p : pos)
		{
			res |= 1ULL << (p.second*(W - 2) + p.first - 1);
		}

		return res;
	}

	bool complete()
	{
		return pos.empty();
	}

	Board left()
	{
		Board res;

		res.route = route + 'L';

		for (auto& p : pos)
		{
			for (int x = p.first; x >= 0; x--)
			{
				if (data[p.second][x] == '.' && data[p.second][x - 1] == '#')
				{
					res.pos.push_back(std::make_pair(x, p.second));
					break;
				}
			}
		}

		return res;
	}

	Board right()
	{
		Board res;

		res.route = route + 'R';

		for (auto& p : pos)
		{
			for (int x = p.first; x < W; x++)
			{
				if (data[p.second][x] == '.' && data[p.second][x + 1] == '#')
				{
					res.pos.push_back(std::make_pair(x, p.second));
					break;
				}
			}
		}

		return res;
	}

	Board up()
	{
		Board res;

		res.route = route + 'U';

		for (auto& p : pos)
		{
			for (int y = p.second; y >= 0; y--)
			{
				if (data[y][p.first] == '.' && data[y-1][p.first] == '#')
				{
					res.pos.push_back(std::make_pair(p.first, y));
					break;
				}
			}
		}

		return res;
	}

	Board down()
	{
		Board res;

		res.route = route + 'D';

		for (auto& p : pos)
		{
			for (int y = p.second; y < H; y++)
			{
				if (data[y][p.first] == '.' && data[y + 1][p.first] == '#')
				{
					res.pos.push_back(std::make_pair(p.first, y));
					break;
				}
			}
		}

		return res;
	}
};

void solve()
{
	Board start;
	std::set<unsigned long long> visited;

	scanf("%d %d", &H, &W);

	for (int y = 0; y < H; y++)
	{
		scanf("%s", data[y]);
		for (int x = 0; x < W; x++)
		{
			if (data[y][x] == '.')
				start.pos.push_back(std::make_pair(x, y));
		}
	}

	std::queue<Board> boards;

	boards.push(start);
	visited.insert(start.index());

	while (!boards.empty())
	{
		auto top = boards.front();

		boards.pop();

		if (top.route.size() > 10)
		{
			break;
		}

		if (top.complete())
		{
			printf("%s\n", top.route.c_str());
			return;
		}

		Board adjs[] = { top.left(), top.up(), top.right(), top.down() };

		for (int i = 0; i < 4; i++)
		{
			unsigned long long index = adjs[i].index();

			if (visited.find(index) != visited.end())
				continue;

			visited.insert(index);

			boards.push(adjs[i]);
		}
	}

	printf("XHAE\n");

}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		solve();
	}

	return 0;
}