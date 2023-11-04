
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int win=0;
    int* days = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (days[j-1] < days[j] && j<n)
        {
            j++;
        }
        if (j != i)
        {
            win += days[j-1] - days[i-1];
            i = j-1;
        }
    }
    cout << win;
    delete[] days;
}


