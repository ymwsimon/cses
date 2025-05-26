#include <iostream>

int	main(void)
{
	int			n;
	long long	res;

	std::cin >> n;
	res = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j == i)
				res += i * i - 1;
			else
				res += (i * i - 1 - j) * 2 - (i - 1);
		}
		if (i >= 2)
			res -= (i - 2) * 8;
		std::cout << res << "\n";
	}
	return (0);
}
