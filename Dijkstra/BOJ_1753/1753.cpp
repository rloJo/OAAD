#include<iostream>
#include<queue>
#define INF 0x7f7f7f7f
using namespace std;

int V, E, K;
vector<pair<int, int>> edges[20002];
vector<int> cost;

void input() {
    cin >> V >> E >> K;
    cost = vector<int>(V+1,INF);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >>w;
        edges[u].push_back({ w,v });
    }
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cost[K] = 0;
    pq.push({ cost[K],K });
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        for (int i = 0; i < edges[cur.second].size(); i++) {
            pair<int, int> next = edges[cur.second][i];
            if (cost[next.second] <= cost[cur.second] + next.first) continue;
            cost[next.second] = cost[cur.second] + next.first;
            pq.push({ cost[next.second],next.second });
        }
    }
}

void solution() {
    dijkstra();
    for (int i = 1; i <= V; i++) {
        if (cost[i] == INF) cout << "INF\n";
        else cout << cost[i] << "\n";
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solution();
    return 0;
}
