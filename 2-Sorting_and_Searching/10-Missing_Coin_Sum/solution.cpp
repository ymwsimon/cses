#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int	main(void)
{
	int						n;
	long long				sumSoFar;
	long long				temp;
	std::vector<long long>	coins;
	std::vector<long long>	perBitSum;

	std::cin >> n;
	coins = std::vector<long long>(n, 0);
	perBitSum = std::vector<long long>(64, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> coins[i];
	std::sort(coins.begin(), coins.end());
	coins.push_back(INT64_MAX);
	for (int i = 0; ; ++i)
	{
		temp = coins[i] - 1;
		if (temp > 1)
		{
			sumSoFar = 0;
			for (int j = 0; j < 64 && perBitSum[j]; ++j)
			{
				temp -= perBitSum[j] * std::pow(2, j);
				sumSoFar += perBitSum[j] * std::pow(2, j);
			}
			if (temp > 0 || i == n)
			{
				std::cout << sumSoFar + 1 << "\n";
				return (0);
			}
		}
		for (int j = 0; j < 64; ++j)
			perBitSum[j] += (coins[i] & (1 << j)) > 0;
	}
	return (0);
}
