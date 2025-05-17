#include <iostream>
#include <set>

int main(void)
{
	int				n;
	int				temp;
	std::set<int>	s;

	std::cin >> n;
	while (n--)
	{
		std::cin >> temp;
		s.insert(temp);
	}
	std::cout << s.size() << "\n";
	return (0);
}
