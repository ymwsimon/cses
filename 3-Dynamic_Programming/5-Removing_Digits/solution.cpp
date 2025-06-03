#include <iostream>
#include <vector>

int	main(void)
{
	int						n;
	std::vector<long long>	steps;

	std::cin >> n;
	steps = std::vector<long long>(n + 1, INT32_MAX);
	steps[0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; i / j; j *= 10)
			steps[i] = std::min(steps[i], 1 + steps[i - (i / j) % 10]);
	std::cout << steps[n] << "\n";
	return (0);
}
