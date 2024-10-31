#include<iostream>
#include<queue>
#define INF 0x7f7f7f7f

using namespace std;

int N, M;
int A, B;
vector<pair<int, int>> edges[1002];
vector<int> val;

void input() {
    cin >> N >> M;
    val = vector<int>(N + 1,INF);
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[from].push_back({ cost,to });
    }
    cin >> A >> B;
}

void dijkstra() {
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    val[A] = 0;
    pq.push({ val[A], A });
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (val[cur.second] != cur.first) continue;
        for (int i = 0; i < edges[cur.second].size(); i++) {
            pair<int, int> next = edges[cur.second][i];
            if (val[next.second] <= val[cur.second] + next.first) continue;
            val[next.second] = val[cur.second] + next.first;
            pq.push({ val[next.second], next.second });
        }
    }
}

void solution() {
    dijkstra();
    cout << val[B];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}
