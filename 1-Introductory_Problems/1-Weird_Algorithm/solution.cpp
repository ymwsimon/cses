#include <iostream>

int main(void)
{
	long long	n;

	std::cin >> n;
	while (n != 1)
	{
		std::cout << n << " ";
		if (n % 2)
			n = n * 3 + 1;
		else
			n /= 2;
	}
	std::cout << n << std::endl;
	return (0);
}