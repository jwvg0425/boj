#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

struct Flower;
void remove(const Flower& flower);

struct Flower
{
	Flower(int x_, int y_) : x(x_), y(y_) {}

	int x, y, idx;
	//A-D, B-C
	int A = -1;
	int B = -1;
	int C = -1;
	int D = -1;

	int jump(char dir)
	{
		int next = -1;
		switch (dir)
		{
		case 'A':
			next = A;
			break;
		case 'B':
			next = B;
			break;
		case 'C':
			next = C;
			break;
		case 'D':
			next = D;
			break;
		}

		return jump(next);
	}

private:
	int jump(int next)
	{
		if (next == -1)
			return idx;

		remove(*this);
		return next;
	}
};

std::vector<Flower> flowers;

void remove(const Flower& flower)
{
	if(flower.B != -1)
		flowers[flower.B].C = flower.C;

	if(flower.C != -1)
		flowers[flower.C].B = flower.B;

	if(flower.A != -1)
		flowers[flower.A].D = flower.D;

	if(flower.D != -1)
		flowers[flower.D].A = flower.A;

}

int main()
{
	int N, K;
	std::string jump;

	std::cin >> N >> K;

	std::cin >> jump;

	for (int i = 0; i < N;i++)
	{
		int x, y;

		std::cin >> x >> y;

		flowers.emplace_back(x, y);
	}

	int startX = flowers[0].x, startY = flowers[0].y;
	int startIndex;

	std::sort(flowers.begin(), flowers.end(), [](const Flower& lhs, const Flower& rhs)
	{
		return lhs.x < rhs.x;
	});

	for (int i = 0; i < flowers.size(); i++)
	{
		flowers[i].idx = i;

		if (flowers[i].x == startX && flowers[i].y == startY)
		{
			startIndex = i;
		}
	}

	std::map<int, int> sets;
	std::map<int, int> sets2;

	for (auto& flower : flowers)
	{
		if (sets.find(flower.y - flower.x) != sets.end())
		{
			auto& prev = flowers[sets[flower.y - flower.x]];
			flower.D = prev.idx;
			prev.A = flower.idx;
		}

		if (sets2.find(flower.y + flower.x) != sets2.end())
		{
			auto& prev = flowers[sets2[flower.y + flower.x]];
			flower.C = prev.idx;
			prev.B = flower.idx;
		}

		sets[flower.y - flower.x] = flower.idx;
		sets2[flower.y + flower.x] = flower.idx;
	}

	int idx = startIndex;

	for (auto& j : jump)
	{
		idx = flowers[idx].jump(j);
	}

	std::cout << flowers[idx].x << ' ' << flowers[idx].y;

	return 0;
}