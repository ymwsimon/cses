#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int					n;
	int					x;
	const int			m = 1e9 + 7;
	std::vector<int>	coins;
	std::vector<int>	ways;

	std::cin >> n >> x;
	coins = std::vector<int>(n);
	ways = std::vector<int>(x + 1, 0);
	ways[0] = 1;
	for (int i = 0; i < n; ++i)
		std::cin >> coins[i];
	std::sort(coins.begin(), coins.end());
	for (int i = 0; i < n; ++i)
		for (int j = coins[i]; j <= x; ++j)
			ways[j] = (ways[j] + ways[j - coins[i]]) % m;
	std::cout << ways[x] << "\n";
	return (0);
}
