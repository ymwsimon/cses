#include <iostream>
#include <vector>

int main(void)
{
	long long			n;
	long long			target;
	std::vector<int>	first;
	std::vector<int>	second;

	std::cin >> n;
	target = n * (n + 1) / 2;
	if (target % 2)
		std::cout << "NO" << "\n";
	else
	{
		std::cout << "YES" << "\n";
		target /= 2;
		while (target)
		{
			if (n <= target)
			{
				first.push_back(n);
				target -= n;
			}
			else
				second.push_back(n);
			--n;
		}
		while (n)
			second.push_back(n--);
		std::cout << first.size() << "\n";
		for (int num : first)
			std::cout << num << " ";
		std::cout << "\n";
		std::cout << second.size() << "\n";
		for (int num : second)
			std::cout << num << " ";
		std::cout << "\n";
	}
	return (0);
}
