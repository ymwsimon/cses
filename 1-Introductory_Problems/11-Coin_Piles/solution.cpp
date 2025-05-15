#include <iostream>

int	main(void)
{
	long long	a;
	long long	b;
	int			t;

	std::cin >> t;
	while (t--)
	{
		std::cin >> a >> b;
		if ((a + b) % 3 || abs(a - b) > std::min(a, b))
			std::cout << "NO\n";
		else
			std::cout << "YES\n";
	}
	return (0);
}
