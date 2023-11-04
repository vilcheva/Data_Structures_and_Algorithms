#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int studentsCount;
	cin >> studentsCount;
	int* studentTickets=new int [studentsCount];
	bool* indexes = new bool[studentsCount];
	bool check = false;
	for (int i = 0; i < studentsCount; i++)
	{
		cin >> studentTickets[i];
	}
	for (int i = 0; i < studentsCount; i++)
	{
		indexes[i] = false;
	}
	for (int i = 0; i < studentsCount; i++)
	{
		if (studentTickets[i] > 0 && studentTickets[i]<=studentsCount)
		{
			indexes[studentTickets[i]-1] = true;
		}
	}
	for (int i = 0; i < studentsCount; i++)
	{
		if (!indexes[i])
		{
			check = true;
			cout << i+1;
			break;
		}
	}
	if (!check)
	{
		cout << studentsCount+1;
	}
	delete[] studentTickets;
	delete[] indexes;
}

