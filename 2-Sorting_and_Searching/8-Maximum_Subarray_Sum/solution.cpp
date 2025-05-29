#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

int	main(void)
{
	int						n;
	long long				curSum;
	long long				maxSumRes;
	std::vector<long long>	nums;

	std::cin >> n;
	nums = std::vector<long long>(n, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> nums[i];
	maxSumRes = INT_MIN;
	curSum = 0;
	for (long long num : nums)
	{
		curSum += num;
		maxSumRes = std::max(maxSumRes, curSum);
		if (curSum < 0)
			curSum = 0;
	}
	std::cout << maxSumRes << "\n";
	return (0);
}
