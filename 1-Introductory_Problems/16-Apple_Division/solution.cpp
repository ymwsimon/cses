#include <iostream>
#include <vector>
#include <climits>

void	genCombination(std::vector<int> &nums, std::vector<bool> &added, int n, int i, long long &result)
{
	long long total;

	if (i < 0)
	{
		total = 0;
		for (size_t j = 0; j < nums.size(); ++j)
		{
			if (added[j])
				total += nums[j];
			else
				total -= nums[j];
		}
		result = std::min(result, llabs(total));
	}
	else
	{
		genCombination(nums, added, n, i - 1, result);
		added[i] = !added[i];
		genCombination(nums, added, n, i - 1, result);
	}
}

int	main(void)
{
	int					n;
	int					temp;
	std::vector<int>	nums;
	std::vector<bool>	added;
	long long			result = LLONG_MAX;

	std::cin >> n;
	while (n--)
	{
		std::cin >> temp;
		nums.push_back(temp);
	}
	added = std::vector<bool>(nums.size(), false); 
	genCombination(nums, added, nums.size(), nums.size() - 1, result);
	std::cout << result << "\n";
	return (0);
}
