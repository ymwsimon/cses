#include <iostream>
#include <vector>

int	main(void)
{
	int								n;
	int								x;
	int								res;
	std::vector<int>				prices;
	std::vector<int>				pages;
	std::vector<std::vector<int>>	best;

	std::cin >> n >> x;
	prices = std::vector<int>(n + 1);
	pages = std::vector<int>(n + 1);
	best = std::vector<std::vector<int>>(n + 1, std::vector<int>(x + 1, 0));
	res = 0;
	for (int i = 1; i <= n; ++i)
		std::cin >> prices[i];
	for (int i = 1; i <= n; ++i)
		std::cin >> pages[i];
	for (int j = 1; j <= n; ++j)
	{
		for (int i = 1; i <= x; ++i)
		{
			best[j][i] = best[j - 1][i];
			if (i >= prices[j])
				best[j][i] = std::max(best[j - 1][i], best[j - 1][i - prices[j]] + pages[j]);
			res = std::max(res, best[j][i]);
		}
	}
	std::cout << res << "\n";
	return (0);
}
