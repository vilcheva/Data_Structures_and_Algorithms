
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> people;
	vector<int> result;
	queue<int> negative;
	stack<int> positive;
	stack<int> positiveReversed;
	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		people.push_back(p);
	}
	int count = 0;
	while (count < n)
	{
		while (people[count] > 0 && count < n)
		{
			positive.push(people[count]);
			count++;
		}
		while (people[count] < 0 && count < n)
		{
			negative.push(people[count]);
			count++;
		}
		while (!negative.empty() && !positive.empty())
		{
			if ((negative.front() * (-1)) > positive.top())
			{
				positive.pop();
			}
			else if ((negative.front()) * (-1) < positive.top())
			{
				negative.pop();
			}
			else
			{
				negative.pop();
				positive.pop();
			}
		}
		while (!negative.empty())
		{
			result.push_back(negative.front());
			negative.pop();
		}
		
	}
	while (!positive.empty())
	{
		positiveReversed.push(positive.top());
		positive.pop();
	}
	while (!positiveReversed.empty())
	{
		result.push_back(positiveReversed.top());
		positiveReversed.pop();
	}
	if (result.size() == 0)
	{
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i]<<' ';
		}
	}
}
