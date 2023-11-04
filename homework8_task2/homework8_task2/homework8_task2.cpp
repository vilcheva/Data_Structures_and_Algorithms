#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>
#include <string_view>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    priority_queue<float, vector<float>> left;
    priority_queue<float, vector<float>, greater<float>> right;
    float medium;
    float number;
    int n;
    cin >> n;
    cin >> number;
    medium = number;
    left.push(number);
    cout << fixed << setprecision(1) << medium;
    float temp;
    for (int i = 2; i <= n; i++)
    {
        cin >> number;
        if (number < medium)
        {
            left.push(number);
        }
        else
        {
            right.push(number);
        }
        if (left.size() > right.size() + 1)
        {
            temp = left.top();
            left.pop();
            right.push(temp);
        }
        else if (left.size() + 1 < right.size())
        {
            temp = right.top();
            right.pop();
            left.push(temp);
        }
        if (i % 2 == 0)
        {
            medium = (left.top() + right.top()) / 2;
        }
        else
        {
            if (left.size() > right.size())
                medium = left.top();
            else
                medium = right.top();
        }
        cout << fixed << setprecision(1) << medium;
    }
}




