#include <iostream>
#include <cmath>
#include <string>

int	main(void)
{
	int			q;
	long long	k;
	long long	nd;
	long long	res;

	std::cin >> q;
	while (q--)
	{
		std::cin >> k;
		nd = 1;
		while (k > (long long)((std::pow(10LL, nd) - std::pow(10LL, nd - 1)) * nd))
		{
			k -= (long long)((std::pow(10LL, nd) - std::pow(10LL, nd - 1)) * nd);
			++nd;
		}
		res = (long long)std::pow(10LL, nd - 1) + (k - 1) / nd;
		std::cout << std::to_string(res)[(k - 1) % nd] << "\n";
	}
	return (0);
}
