#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::string a, b;
	std::vector<int> A;
	std::vector<int> B;

	std::cin >> a >> b;

	for (int i = a.length() - 1; i >= 0; --i)
	{
		A.push_back(a[i] - '0');
	}
	for (int i = b.length() - 1; i >= 0; --i)
	{
		B.push_back(b[i] - '0');
	}
	A.resize(std::max(a.length(), b.length() + 1));
	B.resize(A.size());
	for (int i = 0; i < B.size(); i++)
	{
		A[i] += B[i];
		if (A[i] > 9)
		{
		A[i] -= 10;
		++A[i + 1];
		}
	}
	if (A[A.size() - 1] == 0)
	{
		A.pop_back();
	}
	for (int i = A.size() - 1; i >= 0; --i)
	{
		std::cout << A[i];
	}
}