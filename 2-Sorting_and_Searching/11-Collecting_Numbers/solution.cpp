#include <iostream>
#include <set>

int	main(void)
{
	int				n;
	int				res;
	int				temp;
	std::set<int>	nums;

	res = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> temp;
		if (nums.find(temp - 1) == nums.end())
			++res;
		nums.insert(temp);
	}
	std::cout << res << "\n";
	return (0);
}
