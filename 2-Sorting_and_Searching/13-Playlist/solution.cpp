#include <iostream>
#include <vector>
#include <map>
#include <cmath>

int	main(void)
{
	int					n;
	int					idx;
	int					firstIdx;
	int					res;
	std::vector<int>	playlist;
	std::map<int, int>	seenSoFar;	

	std::cin >> n;
	playlist = std::vector<int>(n, 0);
	res = 0;
	for (int i = 0; i < n; ++i)
		std::cin >> playlist[i];
	firstIdx = 0;
	for (idx = 0; idx < n; ++idx)
	{
		if (seenSoFar.find(playlist[idx]) != seenSoFar.end())
		{
			res = std::max(res, idx - firstIdx);
			firstIdx = std::max(seenSoFar[playlist[idx]] + 1, firstIdx);
		}
		seenSoFar[playlist[idx]] = std::max(seenSoFar[playlist[idx]], idx);
	}
	res = std::max(res, idx - firstIdx);
	std::cout << res << "\n";
	return (0);
}
