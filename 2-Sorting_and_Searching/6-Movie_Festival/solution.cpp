#include <iostream>
#include <vector>
#include <algorithm>

bool	sortByEndTime(std::pair<int, int> a, std::pair<int, int> b)
{
	return (a.second < b.second);
}

int	main(void)
{
	int											n;
	int											a;
	int											b;
	int											res;
	std::vector<std::pair<int, int>>			movie;
	std::vector<std::pair<int, int>>::iterator	nextMoive;
	std::cin >> n;

	while (n--)
	{
		std::cin >> a >> b;
		movie.push_back({a, b});
	}
	std::sort(movie.begin(), movie.end(), sortByEndTime);
	res = 1;
	for (std::vector<std::pair<int, int>>::iterator it = movie.begin(); it != movie.end();)
	{
		nextMoive = it + 1;
		while (nextMoive != movie.end() && nextMoive->first < it->second)
			++nextMoive;
		if (nextMoive != movie.end())
			++res;
		it = nextMoive;
	}
	std::cout << res << "\n";
	return (0);
}
