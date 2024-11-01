#include <iostream>
#include <queue>
#include <tuple>

#define MAX 300

using namespace std;

int N;
vector<pair<int, int>> edges[MAX + 10];
bool chk[MAX + 10];


void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int w;
        cin >> w;
        edges[N + 1].push_back({ w,i });
        edges[i].push_back({ w,N + 1 });
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int p;
            cin >> p;
            if (i == j) continue;
            edges[i].push_back({ p,j });
        }
    }
}

void solution() {
    int answer = 0;
    int nodeCnt = 0;
    priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    chk[1] = true;
    for (const auto& next : edges[1]) pq.push({ next.first,1,next.second });
    while (nodeCnt < N) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        chk[b] = true;
        nodeCnt++;
        answer += cost;
        for (const auto& next : edges[b]) {
            if (chk[next.second]) continue;
            pq.push({ next.first,b,next.second });
        }
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
}
