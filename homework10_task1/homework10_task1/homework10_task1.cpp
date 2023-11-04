
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int from, to;
	int index = 0;
	unordered_map<int, int> dict;
	bool** matrix = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new bool[n] {false};
	}
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;


		if (!dict.count(from))
		{
			dict.insert({ from, index });
			index++;
		}
		int x = dict.at(from);
		if (!dict.count(to))
		{
			dict.insert({ to, index });
			index++;
		}
		int y = dict.at(to);


		matrix[x][y] = true;
		matrix[y][x] = true;
    }
	int k;
	cin >> k;
	queue<int> q;
	vector<bool> result;
	for (int i = 0; i < k; i++)
	{
		cin >> from>>to;
		bool* check = new bool[n] {false};
		if(from==to)
		{
			result.push_back(true);
			continue;
		}
		int x = dict.at(from);
		q.push(x);
		check[x] = true;
		while (!q.empty())
		{
			int curr = q.front();
			for (int i = 0; i < n; i++)
			{
				if (curr != i)
				{
					if (matrix[curr][i])
					{
						if (!check[i])
						{	
							
							check[i] = true;

							if (i ==dict.at(to))
							{
								result.push_back(true);
								//cout << true;
								break;
							}
							q.push(i);
						}

					}
				}
			}
			q.pop();
		}
		if (!check[dict.at(to)])
		{
			result.push_back(false);
			//cout << false;
		}
		
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<" ";
	}
}

