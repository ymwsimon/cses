#include <iostream>

int main(void)
{
	long long	n;
	long long	i = 1;
	long long	sum = 0;
	int			temp;

	std::cin >> n;
	while (i < n)
	{
		std::cin >> temp;
		sum += temp;
		++i;
	}
	std::cout << n * (n + 1) / 2 - sum << std::endl;
	return (0);
}