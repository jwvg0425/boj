#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::string bomb;

	std::cin >> str >> bomb;

	std::string stack;
	stack.reserve(str.size());

	for (char c : str)
	{
		stack.push_back(c);

		if (stack.size() >= bomb.size())
		{
			int pos = 0;
			for (pos = 0; pos < bomb.size(); pos++)
			{
				if (bomb[pos] != stack[stack.size() - bomb.size() + pos])
					break;
			}

			if (pos == bomb.size())
			{
				stack.resize(stack.size() - bomb.size());
			}
		}
	}

	std::cout << (stack.empty() ? "FRULA" : stack) << std::endl;

	return 0;
}