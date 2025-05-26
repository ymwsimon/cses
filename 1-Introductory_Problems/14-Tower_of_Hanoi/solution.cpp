#include <iostream>
#include <cmath>

void	hanoi(int n, int from, int via, int to)
{
	if (n == 1)
	{
		std::cout << from << " " << to << "\n";
		return ;
	}
	hanoi(n - 1, from, to, via);
	std::cout << from << " " << to << "\n";
	hanoi(n - 1, via, from, to);
}

int	main(void)
{
	int	n;

	std::cin >> n;
	std::cout << std::pow(2, n) - 1 << "\n";
	hanoi(n, 1, 2, 3);
	return (0);
}
