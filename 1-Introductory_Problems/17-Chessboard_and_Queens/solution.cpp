#include <iostream>
#include <vector>

bool	validPos(std::vector<std::string> &map, std::vector<int> &pos, int j)
{
	bool	result;

	result = true;
	for (int i = j - 1; i >= 0 && result; --i)
	{
		if (pos[j] == pos[i]
			|| pos[i] + (j - i) == pos[j]
			|| pos[i] - (j - i) == pos[j])
			result = false;
	}
	return (result && map[pos[j]][j] == '.');
}

int	calWays(std::vector<std::string> &map, std::vector<int> &pos, int j)
{
	int	res;

	if (j >= 8)
		return (1);
	res = 0;
	for (int i = 0; i < 8; ++i)
	{
		pos[j] = i;
		if (validPos(map, pos, j))
			res += calWays(map, pos, j + 1);
	}
	return (res);
}

int	main(void)
{
	std::vector<std::string>	map;
	std::vector<int>			pos;
	std::string					temp;

	for (int i = 0; i < 8; ++i)
	{
		std::cin >> temp;
		map.push_back(temp);
	}
	pos = std::vector<int>(8, 0);
	std::cout << calWays(map, pos, 0);
	return (0);
}
