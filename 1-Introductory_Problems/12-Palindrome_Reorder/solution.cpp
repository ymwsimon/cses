#include <iostream>
#include <string>

int	main(void)
{
	std::string	s;
	int			num_odd = 0;
	int			freq[26] = {0};
	int			j;

	std::cin >> s;
	for (char c : s)
		freq[c - 'A']++;
	for (int i = 0; i < 26 && num_odd <= 1; ++i)
		if (freq[i] % 2)
			++num_odd;
	if (num_odd > 1)
	{
		std::cout << "NO SOLUTION\n";
		return (0);
	}
	j = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (freq[i] % 2)
			num_odd = i;
		while (freq[i] > 1)
		{
			s[j] = 'A' + i;
			s[s.length() - 1 - j] = 'A' + i;
			++j;
			freq[i] -= 2;
		}
	}
	if (s.length() % 2)
		s[j] = 'A' + num_odd;
	std::cout << s << "\n";
	return (0);
}
