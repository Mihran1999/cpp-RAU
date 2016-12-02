#include <iostream>

int gcd(int a, int b);

int main()
{
	int a, b, count = 0;
	std::cin >> a >> b;

	for (int i = a, k = a; i < b; ++k)
	{
		if (gcd(i, k) == 1 && k >= a)
		{
			count++;
		}
		if (k == b)
		{
			k = a;
			i++;
		}
	}
	std::cout << count << "\n";
	for (int i = a, j = a; i < b; ++j)
	{
		if (gcd(i, j) == 1 && j >= a)
		{
			std::cout << "(" << i << "," << j << ")" << "\n";
		}
		if (j == b)
		{
			j = a;
			i++;
		}
	}
}

int gcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}