#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

int		dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char	dir_letter[] = {'R', 'L', 'D', 'U'};
char	opp_dir_letter[] = {'L', 'R', 'U', 'D'};
using	vii = std::vector<std::pair<int, int>>;
using	pii = std::pair<int,int>;
using	vull = std::vector<unsigned long long>;
using	vc = std::vector<char>;
using	ull = unsigned long long;

bool	visited(pii coord, ull vis, int dir[2])
{
	pii	new_coord;

	new_coord.first = coord.first + dir[0];
	new_coord.second = coord.second + dir[1];
	return (vis & (1ULL << (new_coord.second * 7 + new_coord.first)));
}

bool	within_range(pii coord, int lower, int upper)
{
	return (coord.first >= lower
			&& coord.second >= lower
			&& coord.first < upper
			&& coord.second < upper);
}

bool	no_forward_but_left_right(pii coord, ull vis, char last)
{
	if (last != 'D' && (coord.second == 0 || visited(coord, vis, dir[3]))
		&& (coord.first > 0
			&& coord.first < 6
			&& !visited(coord, vis, dir[0])
			&& !visited(coord, vis, dir[1])))
		return (true);
	if (last != 'U' &&(coord.second == 6 || visited(coord, vis, dir[2]))
		&& (coord.first > 0
			&& coord.first < 6
			&& !visited(coord, vis, dir[0])
			&& !visited(coord, vis, dir[1])))
		return (true);
	if (last != 'R' && (coord.first == 0 || visited (coord, vis, dir[1]))
		&& (coord.second > 0
			&& coord.second < 6
			&& !visited(coord, vis, dir[2])
			&& !visited(coord, vis, dir[3])))
		return (true);
	if (last != 'L' && (coord.first == 6 || visited (coord, vis, dir[0]))
		&& (coord.second > 0
			&& coord.second < 6
			&& !visited(coord, vis, dir[2])
			&& !visited(coord, vis, dir[3])))
		return (true);
	return (false);
}

int	bfs(std::string &s)
{
	vii		q;
	pii		front;
	pii		new_front;
	int		res;
	ull		qSize;
	int		t;
	size_t	j;
	vull	qVis;
	vc		qc;
	ull		vis;
	char	c;

	t = 48;
	q.push_back({0, 0});
	qVis.push_back(0);
	qc.push_back(' ');
	j = 0;
	while (t--)
	{
		qSize = q.size();
		// std::cout <<"t:"<<t<<" qsize:" <<qSize <<" " <<qVis.size()<<" \n";
		while (j < qSize)
		{
			front = q[j];
			vis = qVis[j];
			c = qc[j];
			++j;
			vis |= (1ULL << (front.second * 7 + front.first));
			if (no_forward_but_left_right(front, vis, c))
				continue ;
			for (int i = 0; i < 4; ++i)
			{
				new_front.first = front.first + dir[i][0];
				new_front.second = front.second + dir[i][1];
				if ((s[48 - t - 1] == '?' || s[48 - t - 1] == dir_letter[i])
					&& c != opp_dir_letter[i]
					&& within_range(new_front, 0, 7)
					&& !(vis & (1ULL << 6 * 7))
					&& !visited(front, vis, dir[i]))
				{
					q.push_back(new_front);
					qVis.push_back(vis);
					qc.push_back(dir_letter[i]);
				}
			}
		}
	}
	qSize = q.size();
	res = 0;
	while (j < qSize)
	{
		front = q[j];
		if (front.first == 0 && front.second == 6)
			++res;
		++j;
	}
	return (res);
}

int	main(void)
{
	std::string	s;

	std::cin >> s;
	std::cout << bfs(s) << "\n";
	return (0);
}
