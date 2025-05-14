#include <iostream>
#include <vector>

int main(void)
{
	int					n;
	int					temp;
	long long			moves = 0;
	std::vector<int>	nums;

	std::cin >> n;
	while (n--)
	{
		std::cin >> temp;
		nums.push_back(temp);
	}
	for (size_t i = 1; i < nums.size(); ++i)
	{
		moves += std::max(0, nums[i - 1] - nums[i]);
		nums[i] = std::max(nums[i - 1], nums[i]);
	}
	std::cout << moves << std::endl;
	return (0);
}
