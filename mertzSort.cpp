#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp;
    int i = start, j = mid + 1;

    // Merge two sorted halves
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back to the original array
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[start + idx] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Sort left and right halves
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // Merge sorted halves
        merge(arr, start, mid, end);
    }
}

int main() {
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    mergeSort(arr, 0, arr.size() - 1);

    // Print sorted array
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}

