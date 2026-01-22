#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(vector<int> &arr) {
    int maxSoFar = arr[0];
    int currMax = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        currMax = max(arr[i], currMax + arr[i]);
        maxSoFar = max(maxSoFar, currMax);
    }
    return maxSoFar;
}

int main() {
    vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};

    cout << maxSubArraySum(arr);

    return 0;
}
