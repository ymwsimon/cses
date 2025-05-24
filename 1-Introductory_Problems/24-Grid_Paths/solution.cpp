#include <iostream>
#include <string>

bool	vis[9][9];

int	dfs(std::string &s, int idx, int x, int y)
{
	int	res;

	if (idx == 48 && x == 1 && y == 7)
		return (1);
	if (idx == 48 || (x == 1 && y == 7))
		return (0);
	if (vis[y][x + 1] && vis[y][x - 1] && !vis[y + 1][x] && !vis[y - 1][x])
		return (0);
	if (vis[y + 1][x] && vis[y - 1][x] && !vis[y][x + 1] && !vis[y][x - 1])
		return (0);
	vis[y][x] = true;
	res = 0;
	if ((s[idx] == '?' || s[idx] == 'U') && !vis[y - 1][x])
		res += dfs(s, idx + 1, x, y - 1);
	if ((s[idx] == '?' || s[idx] == 'D') && !vis[y + 1][x])
		res += dfs(s, idx + 1, x, y + 1);
	if ((s[idx] == '?' || s[idx] == 'L') && !vis[y][x - 1])
		res += dfs(s, idx + 1, x - 1, y);
	if ((s[idx] == '?' || s[idx] == 'R') && !vis[y][x + 1])
		res += dfs(s, idx + 1, x + 1, y);
	vis[y][x] = false;
	return (res);
}

int	main(void)
{
	std::string	s;

	std::cin >> s;
	for (int i = 0; i < 9; ++i)
	{
		vis[0][i] = true;
		vis[8][i] = true;
		vis[i][0] = true;
		vis[i][8] = true;
	}
	for (int i = 1; i <= 7; ++i)
		for (int j = 1; j <= 7; ++j)
			vis[i][j] = false;
	std::cout << dfs(s, 0, 1, 1) << "\n";
	return (0);
}
