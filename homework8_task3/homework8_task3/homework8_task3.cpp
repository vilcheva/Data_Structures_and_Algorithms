#include <queue>
#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> queue;
    vector<int> result;
    int k;
    int t;
    int b;
    cin >> k;
    cin >> t;
    cin >> b;
    int n;
    cin >> n;
    int index = 0;
    int number;

        for (int j = 0; j < b; j++)
        {

            for (int p = 0; p < t; p++)
            {
                if (index < n)
                {
                    cin >> number;
                    queue.push(number);
                    index++;
                }
                else
                    break;
            }
            for (int q = 0; q < k; q++)
            {
                if (!queue.empty())
                {
                    result.push_back(queue.top());
                    queue.pop();
                }
                else 
                    break;
            }
        }

        for(int i=0;i<result.size();i++)
        {
            cout << result[i]<<' ';
        }
}

