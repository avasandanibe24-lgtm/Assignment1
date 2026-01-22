#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (a.size() > 2) {
        vector<int> medians;

        for (int len = 3; len <= a.size(); len += 2) {
            for (int i = 0; i + len <= a.size(); i++) {
                vector<int> temp;
                for (int j = i; j < i + len; j++)
                    temp.push_back(a[j]);
                sort(temp.begin(), temp.end());
                medians.push_back(temp[len / 2]);
            }
        }

        int mn = *min_element(medians.begin(), medians.end());
        for (auto it = a.begin(); it != a.end(); it++) {
            if (*it == mn) {
                a.erase(it);
                break;
            }
        }
    }

    int sum = 0;
    for (int x : a)
        sum += x;

    cout << sum;
    return 0;
}
