#include <iostream>

int main(void)
{
	int	i;
	int n;

	std::cin >> n;
	if (n == 2 || n == 3)
		std::cout << "NO SOLUTION" << std::endl;
	else
	{
		i = 2;
		while (i <= n)
		{
			std::cout << i << " ";
			i += 2;
		}
		i = 1;
		while (i <= n)
		{
			std::cout << i << " ";
			i += 2;
		}
		std::cout << std::endl;
	}
	return (0);
}
