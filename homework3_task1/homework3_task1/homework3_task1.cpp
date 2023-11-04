#include <iostream>
#include<vector>
using namespace std;

long Candy( long number, long left, long right)
{
	
		long mid1 = (2 * left + right) / 3;
		long mid2 = (left + 2 * right) / 3;
		if (mid1 < number && mid2 >= number)
			return 1;
		else if (mid1 == mid2)
			return 1;
		else if (number >mid2)
			return 1 + Candy(number, mid2 + 1, right);
		else 
			return 1 + Candy(number,left,mid1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long n; 
	long p;
	cin >> p;
	cin >> n;
	vector<long> candies;
	long fr = 1;
	for (long i = 0; i < p; i++)
	{
		fr *= 3;
	}
	for (long i = 0; i < n; i++)
	{
		long number;
		cin >> number;
		candies.push_back(Candy(number, 1, fr));	
	}
	for (long i = 0; i < n; i++)
	{
		cout << candies[i]<<"\n";
	}
}

