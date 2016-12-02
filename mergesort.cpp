#include <iostream>
#include <vector>

std::vector <int> merge(std::vector<int>& v_1, std::vector<int>& v_2)
{
	
	std::vector <int> total_vector;
	int i = 0, k = 0;
	//temp = 0;
	while (true) // or temp != 1. Vor tarberakna aveli chsiht es depqum???
	{
		if (i == v_1.size())
		{
			for (int j = 0; j < v_2.size(); ++j)
			{
				total_vector.push_back(v_2[j]);
			}
			break;
		}
		if (k == v_2.size())
		{
			for (int f = 0; f < v_2.size(); ++f)
			{
				total_vector.push_back(v_1[f]);
			}
			break;
		}

		if (v_1[i] > v_2[k])
		{
			total_vector.push_back(v_2[k]);
			k++;
		}
		else if (v_1[i] < v_2[k])
		{
			total_vector.push_back(v_1[i]);
			i++;
		}
	}
	return total_vector;
}

std::vector <int> mergesort(std::vector<int>& v)
{
	if (v.size() == 1)
	{
		return v;
	}
	std::vector <int> v_1;
	for (int i = 0; i < v.size() / 2; ++i)
	{
		v_1.push_back(v[i]);
	}

	std::vector <int> v_2;
	for (int i = v.size() / 2; i < v.size(); ++i)
	{
		v_2.push_back(v[i]);
	}

	return merge(mergesort(v_1), mergesort(v_2));
}

int main()
{
	int n;
	std::cin >> n;
	std::vector <int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	arr = mergesort(arr);

	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i];
	}
}

