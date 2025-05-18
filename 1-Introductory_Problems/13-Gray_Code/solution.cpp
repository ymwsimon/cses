#include <iostream>
#include <bitset>

void	change_bit(std::bitset<16> &b, int n, int i)
{
	if (i < 0)
		std::cout << b.to_string().substr(b.size() - n) << "\n";
	else
	{
		change_bit(b, n, i - 1);
		b[i] = !b[i];
		change_bit(b, n, i - 1);
	}
}

int	main(void)
{
	int				n;
	std::bitset<16> b;

	std::cin >> n;
	change_bit(b, n, n - 1);
	return (0);
}
