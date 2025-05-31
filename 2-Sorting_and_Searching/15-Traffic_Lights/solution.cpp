#include <iostream>
#include <map>
#include <set>

int	main(void)
{
	int								x;
	int								n;
	int								p;
	std::map<int, int>				seg;
	std::map<int, int>::iterator	segIt;
	std::map<int, int>				lenSet;

	std::cin >> x >> n;
	seg[x] = 0;
	lenSet[x]++;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> p;
		segIt = seg.upper_bound(p);
		if (segIt != seg.end())
		{
			lenSet[segIt->first - segIt->second]--;
			if (!lenSet[segIt->first - segIt->second])
				lenSet.erase(segIt->first - segIt->second);
			lenSet[segIt->first - p]++;
			lenSet[p - segIt->second]++;
			seg[p] = segIt->second;
			segIt->second = p;
		}
		std::cout << lenSet.rbegin()->first << " ";
	}
	std::cout << "\n";
	return (0);
}
