#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;

int w, h, n;
std::vector<ii> vertices;

bool isCorner(ii vertex)
{
	return (vertex.first == 0 && vertex.second == 0) ||
		(vertex.first == 0 && vertex.second == h) ||
		(vertex.first == w && vertex.second == 0) ||
		(vertex.first == w && vertex.second == h);
}

//idx ~ idx + 1 edge
bool isBorderEdge(int idx)
{
	ii start = vertices[idx];
	ii end = vertices[(idx + 1) % n];

	if (start.first == end.first &&
		(start.first == 0 || start.first == w))
		return true;

	if (start.second == end.second &&
		(start.second == 0 || start.second == h))
		return true;

	return false;
}

int length(int idx)
{
	return abs(vertices[idx].first - vertices[(idx + 1) % n].first) +
		abs(vertices[idx].second - vertices[(idx + 1) % n].second);
}

int perimeter(int start, int end)
{
	int res = 0;

	for (int i = start; i != end; i = (i + 1) % n)
	{
		res += length(i);
	}

	//테두리 길이 계산
	int dx, dy;
	if (vertices[start].first == 0)
	{
		dy = -1;
		dx = 0;
	}
	else if (vertices[start].first == w)
	{
		dy = 1;
		dx = 0;
	}
	else if (vertices[start].second == 0)
	{
		dy = 0;
		dx = 1;
	}
	else
	{
		dy = 0;
		dx = -1;
	}

	ii now = vertices[start];

	while (now != vertices[end])
	{
		now.first += dx;
		now.second += dy;
		res++;

		if (isCorner(now))
		{
			dy = -dy;
			std::swap(dx, dy);
		}
	}

	return res;
}

int main()
{
	scanf("%d %d %d", &w, &h, &n);

	for (int i = 0; i < n; i++)
	{
		ii vertex;

		scanf("%d %d", &vertex.first, &vertex.second);

		vertices.push_back(vertex);
	}

	int start = -1;

	for (int i = 0; i < n; i++)
	{
		if (isBorderEdge((i + n - 1) % n) && !isBorderEdge(i))
		{
			start = i;
			break;
		}
	}

	if (start == -1)
	{
		//border가 없는 경우 - 조각 하나짜리.
		int sum = w * 2 + h * 2;

		for (int i = 0; i < n; i++)
		{
			sum += length(i);
		}

		printf("1 %d", sum);
		return 0;
	}

	//border를 기준으로 조각 나뉘는 경우
	int now = start;
	std::vector<int> perimeters;
	int polygonStart = now;

	do
	{
		if(isBorderEdge(now))
		{
			if (now != polygonStart)
			{
				perimeters.push_back(perimeter(polygonStart, now));
			}
			polygonStart = (now + 1) % n;
		}

		now++;
		now %= n;
	} while (now != start);

	printf("%d %d", perimeters.size(), *std::max_element(perimeters.begin(), perimeters.end()));

	return 0;
}