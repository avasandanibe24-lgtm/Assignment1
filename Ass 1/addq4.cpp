#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int specialty = 0;

    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int l = 0; l <= i && !ok; l++) {
            for (int r = i; r < n && !ok; r++) {
                int cnt = 0;
                for (int x = l; x <= r; x++) {
                    if (A[x] > A[i])
                        cnt++;
                }
                if (cnt == k)
                    ok = true;
            }
        }
        if (ok)
            specialty += A[i];
    }

    cout << specialty;
    return 0;
}
