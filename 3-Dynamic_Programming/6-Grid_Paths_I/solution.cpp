#include <iostream>
#include <vector>

int	main(void)
{
	int							n;
	const int					m = 1e9 + 7;
	std::vector<int>			paths;
	std::vector<std::string>	grid;

	std::cin >> n;
	grid = std::vector<std::string>(n);
	for (int i = 0; i < n; ++i)
		std::cin >> grid[i];
	paths = std::vector<int>(n, 0);
	paths[0] = grid[0][0] == '.';
	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (grid[j][i] == '*')
				paths[i] = 0;
			else if (i > 0)
				paths[i] = (paths[i] + paths[i - 1]) % m;
		}
	}
	std::cout << paths[n - 1] << "\n";
	return (0);
}
