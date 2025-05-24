#include <iostream>
#include <string>

int		dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
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
	if (s[idx] != '?')
	{
		if (!vis[y + dir[s[idx] - '0'][1]][x + dir[s[idx] - '0'][0]])
			res = dfs(s, idx + 1, x + dir[s[idx] - '0'][0], y + dir[s[idx] - '0'][1]);
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (!vis[y + dir[i][1]][x + dir[i][0]])
				res += dfs(s, idx + 1, x + dir[i][0], y + dir[i][1]);
		}
	}
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
	for (size_t idx = 0; idx < s.length(); ++idx)
	{
		if (s[idx] == 'U')
			s[idx] = '3';
		else if (s[idx] == 'D')
			s[idx] = '2';
		else if (s[idx] == 'L')
			s[idx] = '1';
		else if (s[idx] == 'R')
			s[idx] = '0';
	}
	for (int i = 1; i <= 7; ++i)
		for (int j = 1; j <= 7; ++j)
			vis[i][j] = false;
	std::cout << dfs(s, 0, 1, 1) << "\n";
	return (0);
}
