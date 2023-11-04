#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> input;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		input.push_back(number);
		if (max < number)
			max = number;
	}
	bool* masks = new bool[max+1] {false};
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i <=input[j] ; i++)
		{
			int result = input[j] & i;
			masks[result] = true;
		}
	}
	int counter = 0;
	for (int i = 0; i < max + 1; i++)
	{
		if (masks[i])
			counter++;
	}
	cout << counter;
}

