#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 200000
#define X first 
#define Y second

using namespace std;

int N;
pair<int, int> home[MAX + 10];
int R1maxDist[MAX+10];
int R2maxDist[MAX+10];
int ax, ay, bx, by, q;
int R1[20010];
int R2[20010];

void input() {
    for (int i = 0; i < N; i++) cin >> home[i].X >> home[i].Y;
    cin >> ax >> ay >> bx >> by >> q;
    for (int i = 0; i < q; i++) cin >> R1[i] >> R2[i];
}

void calc_maxDist() {
    for (int i = 0; i < N; i++) {
        double dist = ceil(sqrt((home[i].X - ax) * (home[i].X - ax) + (home[i].Y - ay) * (home[i].Y - ay)));
        R1maxDist[i] = (int)dist;
        dist = ceil(sqrt((home[i].X - bx)* (home[i].X - bx) + (home[i].Y - by) * (home[i].Y - by)));
        R2maxDist[i] = (int)dist;
    }

    sort(R1maxDist, R1maxDist + N);
    sort(R2maxDist, R2maxDist + N);
}

void solution() {
    int order = 1;
    while (1) {
        cin >> N;
        if (N == 0) return;
        input();
        calc_maxDist();
        cout << "Case " << order++ << ":\n";
        for (int i = 0; i < q; i++) {
            int answer = N - (upper_bound(R1maxDist, R1maxDist + N, R1[i]) - R1maxDist) - (upper_bound(R2maxDist, R2maxDist + N, R2[i]) - R2maxDist);
            if (answer < 0) answer = 0;
            cout << answer << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}
