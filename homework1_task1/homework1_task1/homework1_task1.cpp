

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int listsCount;
    cin >> listsCount;
    int lettersCount;
    int* counters = new int[listsCount];
    for (int i = 0; i < listsCount; i++)
    {
        cin >> lettersCount;
        char* list = new char[lettersCount+1];
        cin >> list;

        int counter = 0;
        for (int j = 1; j < lettersCount; j++)
        {
            if (list[j - 1] == list[j])
            {
                counter++;
            }

        }
        counters[i] = counter;
        delete[] list;
    }
    for (int i = 0; i < listsCount; i++)
    {
        cout << counters[i] << "\n";
    }
    delete[] counters;
}

