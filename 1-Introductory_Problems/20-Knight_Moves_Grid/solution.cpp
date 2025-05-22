#include <iostream>
#include <vector>
#include <queue>

int	main(void)
{
	int									n;
	std::pair<int, int>					top;
	std::pair<int, int>					new_coord;
	std::vector<std::vector<int>>		res;
	std::queue<std::pair<int, int>>		q;
	std::vector<std::pair<int, int>>	dir;
	
	std::cin >> n;
	res = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));
	res[0][0] = 0;
	dir = {{1,2},{2,1},{-1,-2},{-2,-1},{1,-2},{-1,2},{2,-1},{-2,1}};
	q.push(std::make_pair(0, 0));
	while (!q.empty())
	{
		top = q.front();
		q.pop();
		for (std::pair<int, int> p : dir)
		{
			new_coord = std::make_pair(top.first + p.first, top.second + p.second);
			if (new_coord.first >= 0 && new_coord.first < n
				&& new_coord.second >= 0 && new_coord.second < n
				&& res[new_coord.first][new_coord.second] == -1)
			{
				res[new_coord.first][new_coord.second] = 1 + res[top.first][top.second];
				q.push(new_coord);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			std::cout << res[i][j] << " ";
		std::cout << "\n";
	}
	return (0);
}
