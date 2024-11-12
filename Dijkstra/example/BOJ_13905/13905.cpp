#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
#define cost first
#define node second

using namespace std;

constexpr int MAX = 100000;
int N, M;
int st, ed;
vector<pair<int, int>> edges[MAX + 10];


void input() {
    cin >> N >> M;
    cin >> st >> ed;
    for (int i = 0; i < M; i++) {
        int to, from, weight;
        cin >> to >> from >> weight;
        edges[to].push_back({ weight,from });
        edges[from].push_back({ weight,to });
    }
}


void solution() {
    priority_queue<pair<int, int>> pq;
    vector<int> dist(N + 1, 0);
    dist[st] = INF;
    pq.push({ dist[st],st });
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        if (dist[cur.second] > cur.cost) continue;
        for (const auto& nxt : edges[cur.node]) {
            int weight = min(nxt.cost, cur.cost);
            if (dist[nxt.node] < weight) {
                dist[nxt.node] = weight;
                pq.push({ weight, nxt.node });
            }
        }
    }
    cout << dist[ed];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

