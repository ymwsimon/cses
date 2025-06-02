#include <iostream>
#include <vector>

int	main(void)
{
	int					n;
	const int			m = 1e9 + 7;
	std::vector<int>	ways;

	std::cin >> n;
	ways = std::vector<int>(n + 1, 0);
	ways[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			if (i - j >= 0)
				ways[i] += ways[i - j] % m;
			ways[i] %= m;
		}
	}
	std::cout << ways[n] << "\n";
	return (0);
}
