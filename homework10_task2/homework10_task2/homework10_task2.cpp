
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
const int letters = 26;
int main()
{
	unordered_map<char, int> dict;
	int n;
	cin >> n;
	vector<string> words;
	string word;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		for (int j = 0; j < word.size(); j++)
		{
			if (!dict.count(word[j]))
			{
				dict.insert({ word[j], index });
				index++;
			}
		}
		words.push_back(word);
	}
	bool** matrix = new bool* [index];
	for (int i = 0; i < index; i++)
	{
		matrix[i] = new bool[index]{false};
	}
	string first;
	string second;
	for (int i = 0; i < n - 1; i++)
	{
		first = words[i];
		second = words[i + 1];
		int j = 0;
		while (first[j] == second[j] || first.size()==j)
		{
			j++;
		}
		if (j < first.size())
		{
			int x = dict.at(first[j]);
			int y = dict.at(second[j]);
			matrix[x][y] = true;
		}
	}
	int counter = 0;

	while (counter < index)
	{
		for (int i = 0; i < index; i++)
		{
			bool flag = true;
			for (int j = 0; j < index; j++)
			{
				if (matrix[j][i])
				{
					flag = false;
					break;
				}

			}
			if (flag)
			{
				for (auto& x : dict)
				{
					if (x.second == i)
					{
						std::cout << x.first << " ";
						counter++;
						break;
					}
				}
				for (int j = 0; j < index; j++)
				{
					matrix[i][j] = false;
					matrix[j][i] = true;
				}
			}
		}

	}
	
}

