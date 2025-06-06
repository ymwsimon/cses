#include <iostream>
#include <vector>

int	main(void)
{
	int					n;
	int					sum;
	std::vector<int>	coins;
	std::vector<bool>	poss;

	std::cin >> n;
	coins = std::vector<int>(n);
	for (int i = 0; i < n; ++i)
		std::cin >> coins[i];
	sum = 0;
	for (int i : coins)
		sum += i;
	poss = std::vector<bool>(sum + 1, false);
	poss[0] = true;
	for (int i = 0; i < n; ++i)
		for (int j = sum - coins[i]; j >= 0; --j)
			poss[j + coins[i]] = poss[j + coins[i]] || poss[j];
	n = -1;
	for (bool b : poss)
		if (b)
			++n;
	std::cout << n << "\n";
	for (int i = 1; i <= sum; ++i)
		if (poss[i])
			std::cout << i << " \n"[i == sum];
	return (0);	
}
