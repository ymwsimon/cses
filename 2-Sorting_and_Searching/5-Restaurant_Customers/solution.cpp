#include <iostream>
#include <map>

int	main(void)
{
	int					n;
	int					a;
	int					b;
	int					res;
	int					curNCustomer;
	std::map<int, int>	timeline;

	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a >> b;
		timeline[a] = 1;
		timeline[b] = -1;
	}
	res = 0;
	curNCustomer = 0;
	for (std::map<int, int>::iterator it = timeline.begin(); it != timeline.end(); ++it)
	{
		curNCustomer += it->second;
		res = std::max(res, curNCustomer);
	}
	std::cout << res << "\n";
	return (0);
}
