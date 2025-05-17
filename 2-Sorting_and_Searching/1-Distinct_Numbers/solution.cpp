#include <iostream>
#include <unordered_set>

int main(void)
{
	int						n;
	int						temp;
	std::unordered_set<int>	s;

	std::cin >> n;
	while (n--)
	{
		std::cin >> temp;
		s.insert(temp);
	}
	std::cout << s.size() << "\n";
	return (0);
}
