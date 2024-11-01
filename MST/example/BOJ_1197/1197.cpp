#include <iostream>
#include <queue>
#include <tuple>

#define MAX 10000

using namespace std;

int V, E;
vector<pair<int, int>> edges[MAX+10];
bool chk[MAX + 10];

void input() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edges[A].push_back({ C,B });
        edges[B].push_back({ C,A });
    }
}

void solution() {
    long long answer = 0;
    priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater <tuple<int, int, int>>> pq;
    chk[1] = true;
    for (const auto& next : edges[1]) pq.push({ next.first, 1, next.second});
    int edgeCnt = 0;
    while (edgeCnt < V - 1) {
        int cost, st, ed;
        tie(cost, st, ed) = pq.top(); pq.pop();
        if (chk[ed]) continue;
        chk[ed] = true;
        edgeCnt++;
        answer += (long long) cost;
        for (const auto& next : edges[ed]) {
            if (chk[next.second]) continue;
            pq.push({ next.first, ed , next.second });
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
