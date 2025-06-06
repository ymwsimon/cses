#include <iostream>
#include <vector>
#include <string>

int	main(void)
{
	int							n;
	std::string					s;
	std::vector<std::string>	grid;
	std::vector<std::string>	best;
	std::vector<std::string>	res;

	std::cin >> n;
	grid = std::vector<std::string>(n);
	for (int i = 0; i < n; ++i)
		std::cin >> grid[i];
	s = "";
	res = std::vector<std::string>(n);
	for (int i = 0; i < n; ++i)
	{
		s.push_back(grid[0][i]);
		res[i] = s;
	}
	for (int j = 1; j < n; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i > 0 && res[i].compare(0, j + i, res[i - 1]) > 0)
				res[i] = res[i - 1];
			res[i].push_back(grid[j][i]);
		}
	}
	std::cout << res[n - 1] << "\n";
	return (0);
}
