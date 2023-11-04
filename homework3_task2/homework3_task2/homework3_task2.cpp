
using namespace std;
#include <iostream>
#include <vector>
#define _DEPRECATE_STDEXT_HASH_UPPER_BOUND


void mergeTwoSortedArrays(vector<int>& array, int left, int middle, int right) {

    vector<int> leftArray, rightArray;

    int l = left;
    while (l <= right) {

        if (l <= middle) {
            leftArray.push_back(array[l]);
        }

        else {
            rightArray.push_back(array[l]);
        }

        l++;
    }

    int leftIndex = 0, rightIndex = 0;
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] > rightArray[rightIndex]) {
            array[left++] = rightArray[rightIndex++];
        }

        else {
            array[left++] = leftArray[leftIndex++];
        }
    }

    while (leftIndex < leftArray.size())
    {
        array[left++] = leftArray[leftIndex++];
    }

    while (rightIndex < rightArray.size())
    {
        array[left++] = rightArray[rightIndex++];
    }

}

void mergeSort(vector<int>& array, int left, int right) {

    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);

    mergeTwoSortedArrays(array, left, middle, right);

}

//int upperBound(vector<int> arr, int x, int start, int end) {
//    if (start <= end) {
//
//        int middle = (end + start) / 2;
//        
//        if (arr[middle] > x) {
//            return upperBound(arr, x, start, middle - 1);
//        }
//        else if (middle < arr.size() - 1 && arr[middle + 1] < x) {
//            return upperBound(arr, x, middle + 1, end);
//        }
//        else if (arr[middle] < x && arr[middle + 1]>x)
//            return middle + 1;
//        else
//            return middle + 2;
//    }
//}
//int lowerBound(vector<int> arr, int x, int start, int end)
//{
//    if (start <= end) {
//
//        int middle = (end + start) / 2;
//
//        if (arr[middle] > x) {
//            return lowerBound(arr, x, start, middle - 1);
//        }
//        else if (middle < arr.size() - 1 && arr[middle + 1] < x) {
//            return lowerBound(arr, x, middle + 1, end);
//        }
//        else if (x == arr[middle])
//            return middle;
//        else
//            return middle + 1;
//    }
//}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int studentCount;
    int tours;
    cin >> studentCount;
    cin >> tours;
    vector<int> students;
    vector<int> weights;
    for (int i = 0; i < studentCount; i++)
    {
        int kg;
        cin >> kg;
        students.push_back(kg);
    }
    mergeSort(students, 0, studentCount - 1);
    for (int i = 0; i < tours * 2; i++)
    {
        int kg;
        cin >> kg;
        weights.push_back(kg);
    }
    for (int i = 0; i < tours * 2; i += 2)
    {

        if (weights[i] <= weights[i + 1])
        {
            std::vector<int>::iterator low, up;
            low = std::lower_bound(students.begin(), students.end(), weights[i]);
            up = std::upper_bound(students.begin(), students.end(), weights[i + 1]);
            cout << (up - low) << "\n";
        }
        else
            cout << 0<<"\n";


    }
       
		
}




