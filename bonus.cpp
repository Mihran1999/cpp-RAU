#include <iostream>
#include <vector>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(m, std::vector<int>(n)); //matrixx
	int count = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			std::cin >> v[i][k];
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int k = 0; k < n - 1; ++k)
		{
			for (int j = k; j < n - 1; ++j)
			{
				if (v[i][k] > v[i][j + 1])
				{
					++count;
				}
			}
		}
	}
	std::cout << count << "\n";
}