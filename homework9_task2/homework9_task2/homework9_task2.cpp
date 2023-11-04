#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    queue<int> queue;
    bool isContained[1000001] = {false};
    int n;
    cin >> n;
    int number;
    int counter=0;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        if (isContained[number])
        {
            while (queue.front() != number)
            {
                isContained[queue.front()] = false;
                queue.pop();
                counter--;
            }
            queue.pop();
            queue.push(number);
        }
        else
        {
            isContained[number] = true;
            queue.push(number);
            counter++;
        }
        if (maxCount < counter)
        {
            maxCount = counter;
        }
    }
    cout << maxCount;
}

