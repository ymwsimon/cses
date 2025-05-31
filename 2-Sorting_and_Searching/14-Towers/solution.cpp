#include <iostream>
#include <set>

int	main(void)
{
	int					n;
	int					temp;
	int					res;
	std::multiset<int>	tower;

	std::cin >> n;
	res = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> temp;
		if (tower.upper_bound(temp) != tower.end())
			tower.erase(tower.upper_bound(temp));
		else
			++res;
		tower.insert(temp);
	}
	std::cout << res << "\n";
	return (0);
}
