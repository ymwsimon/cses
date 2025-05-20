#include <iostream>
#include <set>
#include <vector>

int	main(void)
{
	int							n;
	std::set<int>				s;
	std::set<int>				rs;
	std::vector<std::set<int>>	vcs;

	std::cin >> n;
	for (int i = 0; i < n * 10; ++i)
		s.insert(i);
	vcs = std::vector<std::set<int>>(n, s);
	for (int j = 0; j < n; ++j)
	{
		rs = s;
		for (int i = 0; i < n; ++i)
		{
			for (auto it = rs.begin(); it != rs.end(); ++it)
			{
				if (vcs[i].find(*it) != vcs[i].end())
				{
					vcs[i].erase(*it);
					rs.erase(*it);
					std::cout << *it << " ";
					break ;
				}
			}
		}
		std::cout << "\n";
	}
	return (0);
}
