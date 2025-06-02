#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int						n;
	int						x;
	const int				m = 1e9 + 7;
	std::vector<int>		coins;
	std::vector<long long>	ways;

	std::cin >> n >> x;
	ways = std::vector<long long>(x + 1, 0);
	ways[0] = 1;
	coins = std::vector<int>(n);
	for (int i = 0; i < n; ++i)
		std::cin >> coins[i];
	std::sort(coins.begin(), coins.end());
	for (int i = 1; i <= x; ++i)
		for (int c : coins)
			if (i >= c)
				ways[i] = (ways[i] + ways[i - c]) % m;
	std::cout << ways[x] << "\n";
	return (0);
}
