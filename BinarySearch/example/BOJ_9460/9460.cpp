#include <iostream>
#include <algorithm>

#define MAX 10000
#define X first
#define Y second

using namespace std;

int T, n, k;
pair<int,int> p[MAX + 10];

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> p[i].X >> p[i].Y;
}

void binary_search() {
    int s = 0;
    int e = 200000000;
    while (s <= e) {
        int mid = (s + e) / 2;
        int check = 1;
        int mx = -100000000;
        int mn = 100000000;
        for (int i = 0; i < n; i++) {
            mx = max(mx, p[i].Y);
            mn = min(mn, p[i].Y);
            if (mx - mn > mid) {
                check++;
                mx = p[i].second;
                mn = p[i].second;
            }
        }
        if (check <= k) e = mid - 1;
        else s = mid + 1;
    }
    cout << (double)s / 2 << '\n';
}

void solution() {
    cout << fixed;
    cout.precision(1);
    cin >> T;
    while (T--) {
        input();
        sort(p, p + n);
        binary_search();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}

