#include <iostream>
#include <vector>

int	main(void)
{
	long long	n;
	long long	res = 0;

	std::cin >> n;
	for (long long i = 5; i <= n; i *= 5)
		res += n / i;
	std::cout << res << "\n";
	return (0);
}
