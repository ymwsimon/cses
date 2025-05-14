#include <iostream>

int main(void)
{
	std::string		s;
	size_t			i = 0;
	size_t			j;
	int				steak;
	int				max_length = 0;

	std::cin >> s;
	while (i < s.length())
	{
		steak = 0;
		j = 0;
		while (i + j < s.length() && s[i] == s[i + j])
		{
			++steak;
			++j;
		}
		max_length = std::max(max_length, steak);
		i += j;
	}
	std::cout << max_length << std::endl;
	return (0);
}