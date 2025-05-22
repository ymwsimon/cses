#include <iostream>
#include <vector>

bool	colourOk(int pi, int pj, int ci,
	std::vector<std::vector<char>> &og, std::vector<std::vector<char>> &try_grid)
{
	if (og[pj][pi] - 'A' != ci
		&& (pi == 0 || try_grid[pj][pi - 1] - 'A' != ci)
		&& (pj == 0 || try_grid[pj - 1][pi] - 'A' != ci))
		return (true);
	return (false);
}

bool	try_fill(int n, int m, int pi, int pj, int ci,
	std::vector<std::vector<char>> &og, std::vector<std::vector<char>> &try_grid)
{
	if (pj == n)
		return (true);
	if (pi == m)
		return (try_fill(n, m, 0, pj + 1, 0, og, try_grid));
	if (ci >= 5)
		return (false);
	if (!colourOk(pi, pj, ci, og, try_grid))
		return (try_fill(n, m, pi, pj, ci + 1, og, try_grid));
	try_grid[pj][pi] = 'A' + ci;
	return (try_fill(n, m, pi + 1, pj, 0, og, try_grid)
		|| try_fill(n, m, pi, pj, ci + 1, og, try_grid));
}

int	main(void)
{
	int	n;
	int	m;
	std::vector<std::vector<char>>	og_grid;
	std::vector<std::vector<char>>	try_grid;

	std::cin>> n >> m;
	og_grid = std::vector<std::vector<char>>(n, std::vector<char>(m, ' '));
	try_grid = std::vector<std::vector<char>>(n, std::vector<char>(m, ' '));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> og_grid[i][j];
	if (try_fill(n, m, 0, 0, 0, og_grid, try_grid))
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				std::cout << try_grid[i][j];
			std::cout << "\n";
		}
	}
	else
		std::cout << "IMPOSSIBLE\n";
}
