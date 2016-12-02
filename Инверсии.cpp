#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	int number_of_inversion = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			if (arr[i] > arr[k])
			{
				++number_of_inversion;
			}
		}
	}
	
	std::cout << number_of_inversion << "\n";
}




