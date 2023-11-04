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
	int last = 2;
	int prelast = 2;
	int current=2;
	for (int i = 2; i < n; i++)
	{
		current = (last + prelast)%1000000007;
		prelast = last;
		last = current;
	}
	cout << current;

}

