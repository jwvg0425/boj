#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

std::string pokemon[100001];
std::map<std::string, int> numbering;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		char buffer[21];

		scanf("%s", buffer);

		pokemon[i + 1] = buffer;
		numbering.emplace(buffer, i + 1);
	}

	for (int i = 0; i < m; i++)
	{
		char buffer[21];

		scanf("%s", buffer);

		std::string str(buffer);

		if (str[0] >= '0' && str[0] <= '9') //number
			printf("%s\n", pokemon[std::stoi(str)].c_str());
		else
			printf("%d\n", numbering[str]);
	}

	return 0;
}