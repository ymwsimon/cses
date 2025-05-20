#include <iostream>

int	main(void)
{
	int	t;
	int	n;
	int	a;
	int	b;

	std::cin >> t;
	while (t--)
	{
		std::cin >> n >> a >> b;
		if (a + b > n || (std::max(a, b) >= a + b && std::max(a, b) > 0))
			std::cout << "NO" << "\n";
		else
		{
			std::cout << "YES" << "\n";
			for (int i = 0; i < a + b; ++i)
				std::cout << n - i << " ";
			for (int i = 1; i <= n - (a + b); ++i)
				std::cout << i << " ";
			std::cout << "\n";
			for (int i = 0; i < a + b; ++i)
				std::cout << n - (i + b) % (a + b) << " ";
			for (int i = 1; i <= n - (a + b); ++i)
				std::cout << i << " ";
			std::cout << "\n";
		}
	}
	return (0);
}
