
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string arr;
	cin >> arr;
	vector<int> films;
	int countingArray[75] = {0};
	for (int i = 0; i < arr.size(); i++)
	{
		countingArray[int(arr[i]) - 48]++;
	}
	for (int i = 0; i < 75; i++)
	{
		if (countingArray[i] == 1)
		{
			for (int j = 0; j < arr.size(); j++)
			{
				if (int(arr[j]) == i + 48)
				{
					films.push_back(j);				
				}
			}
		}
	}

	for (int i = 0; i < films.size(); i++)
	{
		for (int j = 0; j < films.size() - 1; j++)
		{
			if (films[j] > films[i])
			{
				int temp = films[i];
				films[i] = films[j];
				films[j] = temp;
			}
		}
	 }
	for (int i = 0; i < films.size(); i++)
	{
		cout << films[i] << " ";
	}

}

 