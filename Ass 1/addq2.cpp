#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (abs(A[i] - A[j]) <= 10)
                cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}
