#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int	main(void)
{
	int								n;
	int								m;
	int								tmp;
	std::vector<int>				customer;
	std::map<int, int>				ticket;
	std::map<int, int>::iterator	it;

	std::cin >> n >> m;
	customer = std::vector<int>(m, 0);
	for (int t = 0; t < n; ++t)
	{
		std::cin >> tmp;
		ticket[tmp]++;
	}
	for (int t = 0; t < m; ++t)
		std::cin >> customer[t];
	for (int cPrice : customer)
	{
		it = ticket.upper_bound(cPrice);
		if (ticket.empty() || it == ticket.begin())
			std::cout << -1 << "\n";
		else
		{
			--it;
			tmp = it->first;
			it->second--;
			if (it->second == 0)
				ticket.erase(it);
			std::cout << tmp << "\n";
		}
	}
	return (0);
}
