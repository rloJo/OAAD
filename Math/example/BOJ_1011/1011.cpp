#include <iostream>
#include <cmath>

using namespace std;
int T;
int x, y;

void input() {
    cin >> x >> y;
}

void solution() {
    cin >> T;
    while (T--) {
        input();
        double dist = sqrt(y - x);
        int rdist = round(dist);
        if (dist <= rdist)  cout << 2 * rdist - 1;
        else cout << 2 * rdist;
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}
