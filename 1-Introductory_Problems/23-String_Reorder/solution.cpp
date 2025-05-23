#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int	main(void)
{
	std::vector<int>	freq(26, 0);
	std::string			s;
	size_t				j;
	size_t				k;
	size_t				m;
	size_t				n;

	std::cin >> s;
	for (char c : s)
		freq[c - 'A']++;
	for (size_t i : freq)
	{
		if (i > (s.length() + 1) / 2 )
		{
			std::cout << -1 << "\n";
			return (0);
		}
	}
	std::sort(s.begin(), s.end());
	j = 1;
	k = 1;
	while (j < s.length())
	{
		if (s[j] == s[j - 1])
		{
			if (k <= j)
				k = j + 1;
			while (k < s.length() && s[j] == s[k])
				++k;
			if (k == s.length())
			{
				m = j - 2;
				while (m > 0 && (s[m] == s[j] || s[m - 1] == s[j]))
					--m;
				s.insert(s.begin() + m, s[j]);
				s.erase(j, 1);
				++m;
				n = j - 1;
				while (n > m && s[n] >= s[m])
					--n;
				if (n > m)
					std::swap(s[n], s[m]);
			}
			else
				std::swap(s[j], s[k]);
		}
		++j;
	}
	std::cout << s << "\n";
	return (0);
}
