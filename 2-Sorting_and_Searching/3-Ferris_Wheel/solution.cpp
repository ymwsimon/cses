#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int					n;
	int					x;
	int					j;
	int					k;
	int					res;
	std::vector<int>	children;

	std::cin >> n >> x;
	children = std::vector<int>(n, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> children[i];
	std::sort(children.begin(), children.end());
	j = 0;
	k = n - 1;
	res = 0;
	while (j <= k)
	{
		if (children[k] + children[j] <= x)
			++j;
		--k;
		++res;
	}
	std::cout << res << "\n";
	return (0);
}
