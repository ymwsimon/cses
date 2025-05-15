#include <iostream>

int	main(void)
{
	int			n;
	long long	col;
	long long	row;
	long long	layer;
	long long	res;

	std::cin >> n;
	while (n--)
	{
		std::cin >> row >> col;
		layer = std::max(row, col);
		res = layer * layer;
		if (layer % 2)
			res -= (layer - col) + (row - 1);
		else
			res -= (layer - row) + (col - 1);
		std::cout << res << std::endl;
	}
}
