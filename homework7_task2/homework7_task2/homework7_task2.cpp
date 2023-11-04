#include <iostream>
#include<set>
#include<vector>
#include <queue>

using namespace std;

//int isContained(vector<int> array, int number)
//{
//	for (int i = 0; i < array.size(); i++)
//	{
//		if (number == array[i]);
//		return i;
//	}
//	return -1;
//}
int main()
{
	int n;
	cin >> n;
	vector <int> result;
	int request;
	for (int i = 0; i < n; i++)
	{	set<int> tree;
		queue<int> queue;
		int max = 0;
		int cookie=0;
		int counter = 0;
		cin >> request;
		for (int i = 0; i < request; i++)
		{
			cin >> cookie;
			if (tree.count(cookie))
			{
				while (queue.front() != cookie)
				{
					tree.erase(queue.front());
					queue.pop();
					counter--;
					
				}
				queue.pop();
				counter--;
				/*auto iter=tree.lower_bound(cookie);
				while (iter != tree.begin())
				{
					tree.erase(iter);
					iter--;
					counter--;
				}
				counter--;*/

			}
			tree.insert(cookie);
			counter++;
			queue.push(cookie);
			if (counter > max)
			{
				max = counter;
			}
		}
		result.push_back(max);
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << '\n';
	}
	/*int q;
	cin >> q;
	vector<int> result;
	int n;
	for (int i = 0; i < q; i++)
	{
		cin >> n;
		int counter = 0;
		int cookie=0;
		vector<int> cookies;
		for (int j = 0; j < n; j++)
		{
			cin >> cookie;
			int iter = isContained(cookies, cookie);
			if (iter!=-1)
			{
				for (int p = 0; p <= iter; i++)
				{
					counter--;
					cookies.erase()
				}
			}

		}*/
	}
	




