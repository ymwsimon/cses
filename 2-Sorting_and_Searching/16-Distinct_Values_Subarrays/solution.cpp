#include <iostream>
#include <map>

int	main(void)
{
	int					n;
	int					num;
	int					left;
	long long			res;
	std::map<int, int>	last;

	std::cin >> n;
	left = 0;
	res = 0;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> num;
		left = std::max(left, last[num]);
		res += i - left;
		last[num] = i;
	}
	std::cout << res << "\n";
	return (0);
}
