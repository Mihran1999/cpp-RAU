#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string S;
	std::string k;
	bool check = false;
	bool check_1 = false;

	std::cin >> S >> k;

	for (int i = 0; i < k.length(); i++)
	{
		if (k[i] == S[i])
		{
			check = true;
		}
		else
		{
			check = false;
			break;
		}
	}

	for (int i = 0; i < k.length()/2; i++)
	{
		std::swap(k[i], k[k.length() - i - 1]);
	}

	for (int i = 0; i < S.length()/2; i++)
	{
		std::swap(S[i], S[S.length() - i - 1]);
	}

	for (int i = 0; i < k.length(); ++i)
	{
		if (k[i] == S[i])
		{
			check_1 = true;
		}
		else
		{
			check_1 = false;
			break;
		}
	}

	if (!check && !check_1)
	{
		std::cout << "Neither";
		return 0;
	}
	if (check && check_1)
	{
		std::cout << "Both";
		return 0;
	}
	if (check)
	{
		std::cout << "Prefix";
	}
	if (check_1)
	{
		std::cout << "Suffix";
	}
	
	
}