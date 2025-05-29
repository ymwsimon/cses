#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int	main(void)
{
	int						n;
	long long				res;
	long long				cost;
	long long				prevLength;
	long long				prevCostSum;
	long long				lengthSum;
	std::vector<long long>	sticks;

	std::cin >> n;
	sticks = std::vector<long long>(n, 0);
	lengthSum = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> sticks[i];
		lengthSum += sticks[i];
	}
	std::sort(sticks.begin(), sticks.end());
	res = LONG_LONG_MAX;
	prevLength = sticks[sticks.size() - 1];
	prevCostSum = 0;
	for (int i = sticks.size() - 1; i >= 0; --i)
	{
		lengthSum -= sticks[i];
		cost = sticks[i] * i - lengthSum;
		prevCostSum += (prevLength - sticks[i]) * (n - i - 1);
		cost += prevCostSum;
		prevLength = sticks[i];
		res = std::min(res, cost);
	}
	std::cout << res << "\n";
	return (0);
}
