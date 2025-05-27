#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int					n;
	int					m;
	int					k;
	int					i;
	int					j;
	int					res;
	std::vector<int>	applicant;
	std::vector<int>	apartmemt;

	std::cin >> n >> m >> k;
	applicant = std::vector<int>(n, 0);
	apartmemt = std::vector<int>(m, 0);
	for (int t = 0; t < n; ++t)
		std::cin >> applicant[t];
	for (int t = 0; t < m; ++t)
		std::cin >> apartmemt[t];
	i = 0;
	j = 0;
	res = 0;
	std::sort(applicant.begin(), applicant.end());
	std::sort(apartmemt.begin(), apartmemt.end());
	while (i < n && j < m)
	{
		if (applicant[i] - k > apartmemt[j])
			++j;
		else if (applicant[i] + k < apartmemt[j])
			++i;
		else
		{
			++res;
			++i;
			++j;
		}
	}
	std::cout << res << "\n";
	return (0);
}
