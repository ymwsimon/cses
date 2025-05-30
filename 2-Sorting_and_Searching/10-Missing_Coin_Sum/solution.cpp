#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int						n;
	long long				sumSoFar;
	std::vector<long long>	coins;

	std::cin >> n;
	coins = std::vector<long long>(n, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> coins[i];
	std::sort(coins.begin(), coins.end());
	sumSoFar = 1;
	for (int i = 0; i < n ; ++i)
	{
		if (coins[i] > sumSoFar)
			break ;
		sumSoFar += coins[i];
	}
	std::cout << sumSoFar << "\n";
	return (0);
}
