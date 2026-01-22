#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, H, W;
        cin >> N >> H >> W;

        long long side = max(H, W);

        while ((side / H) * (side / W) < N)
            side++;

        cout << side << endl;
    }
    return 0;
}
