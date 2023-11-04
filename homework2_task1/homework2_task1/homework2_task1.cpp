#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int countOfNumbers;
    cin >> countOfNumbers;
    int* array = new int[countOfNumbers];
    int* blackNumbers = new int[countOfNumbers];
    int* redNumbers = new int[countOfNumbers];
    int redCount = 0;
    int blackCount = 0;
    for (int i = 0; i < countOfNumbers; i++)
    {
        cin >> array[i];
        if (array[i] % 2 == 0)
        {
            redNumbers[redCount++] = array[i];
        }
        else
        {
            blackNumbers[blackCount++] = array[i];
        }
    }
    for (int i = 0; i < redCount; i++)
    {
        cout << redNumbers[i] << "\n";
    }
    for (int i = 0; i < blackCount; i++)
    {
        cout << blackNumbers[i] << "\n";
    }
    delete[] redNumbers;
    delete[] blackNumbers;
    delete[] array;
}

