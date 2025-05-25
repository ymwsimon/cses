#include <iostream>
#include <string>
#include <set>
#include <algorithm>

void genStr(std::set<std::string> &list, std::string &s, size_t i)
{
	size_t	j;

	while (i < s.length())
	{
		j = i + 1;
		while (j < s.length())
		{
			while (j < s.length() && s[i] == s[j])
				++j;
			if (j < s.length())
			{
				std::swap(s[i], s[j]);
				list.insert(s);
				genStr(list, s, i + 1);
				std::swap(s[i], s[j]);
			}
			++j;
		}
		++i;
	}
}

int	main(void)
{
	std::string				s;
	std::set<std::string>	list;

	std::cin >> s;
	std::sort(s.begin(), s.end());
	list.insert(s);
	genStr(list, s, 0);
	std::cout << list.size() << "\n";
	for (std::string str : list)
		std::cout << str << "\n";
	return (0);
}
