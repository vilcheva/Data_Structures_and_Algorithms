#include <iostream>
#include <vector>

using namespace std;
const int N = 1000001;
int components = 1;
int visited[N]{ 0 };
vector<int> adjacencyList[N];

void dfs(int v)
{
    visited[v] = components;

    for (auto neighbour : adjacencyList[v])
    {
        if (neighbour < 1000000)
        {
            if (!visited[neighbour]) dfs(neighbour);
        }
    }

}
int findNumberOfComponents(int numberOfVertices)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            components++;
        }
    }
    return components;
}


int main()
{
    int n, m;
    cin >> n >> m;
    int from, to;
    vector<bool> isTherePath;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
    }

    int comp = findNumberOfComponents(n);
    int q;
    cin >> q;
    int command;
    for (int i = 0; i < q; i++)
    {
        cin >> command;
        cin >> from >> to;
        if (command == 1)
        {
            if (visited[from] == visited[to])
            {
                isTherePath.push_back(true);
            }
            else
            {
                isTherePath.push_back(false);
            }
        }
        else if (command == 2)
        {
            int numberFrom = visited[from];
            int numberTo = visited[to];
            for (int i = 0; i < n; i++)
            {
                if (visited[i] == numberTo)
                {
                    visited[i] = numberFrom;
                }
            }
        }
    }
    for (int i = 0; i < isTherePath.size(); i++)
    {
        cout << isTherePath[i];
    }
}