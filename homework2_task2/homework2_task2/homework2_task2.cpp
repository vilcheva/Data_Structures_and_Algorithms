
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool strCompare(string str1, string str2)
{
    int length = 0;
    if (str1.size() <= str2.size())
    {
        length = str1.size();
    }
    else
    {
        length = str2.size();
    }
    for (int i = 0; i < length; i++)
    {
        if (str1[i] < str2[i])
        {
            return true;
        }
        else if (str1[i] > str2[i])
        {
            return false;
        }
    }
    return false;
}
void mergeTwoSortedArrays(vector<int>& array,vector<string>& name, int left, int middle, int right) {

    vector<int> leftArray, rightArray;
    vector<string> leftNameArray, rightNameArray;

    int l = left;
    while (l <= right) {

        if (l <= middle) {
            leftArray.push_back(array[l]);
            leftNameArray.push_back(name[l]);
        }

        else { // l > middle
            rightArray.push_back(array[l]);
            rightNameArray.push_back(name[l]);
        }

        l++;
    }

    int leftIndex = 0, rightIndex = 0;
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] < rightArray[rightIndex]) {
            array[left] = rightArray[rightIndex];
            name[left] = rightNameArray[rightIndex];
            left++;
            rightIndex++;
        }
        else if (leftArray[leftIndex] == rightArray[rightIndex])
        {
            if (!strCompare(leftNameArray[leftIndex],rightNameArray[rightIndex]))
            {
                array[left] = rightArray[rightIndex];
                name[left] = rightNameArray[rightIndex];
                left++;
                rightIndex++;
            }
            else
            {
                array[left] = leftArray[leftIndex];
                name[left++] = leftNameArray[leftIndex++];
            }
        }
        else {
            array[left] = leftArray[leftIndex];
            name[left] = leftNameArray[leftIndex];
            left++;
            leftIndex++;
        }
    }

    while (leftIndex < leftArray.size())
    {
        array[left] = leftArray[leftIndex];
        name[left] = leftNameArray[leftIndex];
        left++;
        leftIndex++;
    }

    while (rightIndex < rightArray.size())
    {
        array[left] = rightArray[rightIndex];
        name[left] = rightNameArray[rightIndex];
        left++;
        rightIndex++;
    }

}

void mergeSort(vector<int>& array,vector<string>& name, int left, int right) {

    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSort(array,name, left, middle);
    mergeSort(array,name, middle + 1, right);

    mergeTwoSortedArrays(array,name, left, middle, right);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> points;
    vector<string> names;
    string name;
    int point;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        names.push_back(name);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> point;
        points.push_back(point);
    }

    mergeSort(points,names, 0, points.size() - 1);

    for (int i = 0; i <points.size(); i++) {
        cout << names[i] << " "<<points[i]<<"\n";
    }
   
    return 0;
  
}


