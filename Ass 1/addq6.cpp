#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

double brute(vector<Point> &p, int l, int r) {
    double d = 1e18;
    for (int i = l; i <= r; i++)
        for (int j = i + 1; j <= r; j++)
            d = min(d, dist(p[i], p[j]));
    return d;
}

double solve(vector<Point> &p, int l, int r) {
    if (r - l <= 3)
        return brute(p, l, r);

    int m = (l + r) / 2;
    double dl = solve(p, l, m);
    double dr = solve(p, m + 1, r);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = l; i <= r; i++)
        if (abs(p[i].x - p[m].x) < d)
            strip.push_back(p[i]);

    sort(strip.begin(), strip.end(),
         [](Point a, Point b) { return a.y < b.y; });

    for (int i = 0; i < strip.size(); i++)
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++)
            d = min(d, dist(strip[i], strip[j]));

    return d;
}

int main() {
    vector<Point> p = {
        {9,3},{2,6},{15,3},{5,1},{1,2},{12,4},{7,2},{4,7},
        {16,5},{3,3},{10,5},{6,4},{14,6},{8,6},{11,1},{13,2}
    };

    sort(p.begin(), p.end(),
         [](Point a, Point b) { return a.x < b.x; });

    cout << solve(p, 0, p.size() - 1);
    return 0;
}
                                      