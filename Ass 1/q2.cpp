#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
    int i = l, j = m + 1;
    vector<int> temp;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= m)
        temp.push_back(arr[i++]);

    while (j <= r)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[l + k] = temp[k];
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr1, 0, arr1.size() - 1);
    mergeSort(arr2, 0, arr2.size() - 1);

    for (int x : arr1) cout << x << " ";
    cout << endl;
    for (int x : arr2) cout << x << " ";

    return 0;
}
