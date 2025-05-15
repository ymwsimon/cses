#include <iostream>

const long long m = 1000000007;

int main(void)
{
	int n;
	int	res;

	std::cin >> n;
	res = 2;
	while (--n)
	{
		res *= 2;
		res %= m;
	}
	std::cout << res << "\n";
	return (0);
}
