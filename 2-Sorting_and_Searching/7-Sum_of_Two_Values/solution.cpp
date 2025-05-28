#include <iostream>
#include <vector>
#include <map>

int	main(void)
{
	int					n;
	int					x;
	int					j;
	std::vector<int>	nums;
	std::map<int, int>	lookup;

	std::cin >> n >> x;
	nums = std::vector<int>(n, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> nums[i];
	j = 0;
	while (j < n)
	{
		if (lookup[nums[j]])
		{
			std::cout << lookup[nums[j]] << " " << j + 1 << "\n";
			return (0);
		}
		lookup[x - nums[j]] = j + 1;
		++j;
	}
	std::cout << "IMPOSSIBLE\n";
	return (0);
}
