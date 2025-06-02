#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int						n;
	int						x;
	std::vector<int>		coins;
	std::vector<long long>	num;

	std::cin >> n >> x;
	coins = std::vector<int>(n);
	num = std::vector<long long>(x + 1, INT32_MAX);
	num[0] = 0;
	for (int i = 0; i < n; ++i)
		std::cin >> coins[i];
	std::sort(coins.begin(), coins.end());
	for (int i = 1; i <= x; ++i)
		for (int c : coins)
			if (i >= c)
				num[i] = std::min(num[i], 1 + num[i - c]);
	if (num[x] == INT32_MAX)
		num[x] = -1;
	std::cout << num[x] << "\n";
	return (0);
}
