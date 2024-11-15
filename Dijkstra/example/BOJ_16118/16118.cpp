#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX = 4000;

int N, M;
vector<pair<int,int>> edges[MAX + 10];
int fox[MAX + 10];
int wolf[2][MAX + 10];

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        edges[a].push_back({ d*2,b });
        edges[b].push_back({ d*2,a });
    }
}

void dijkstra_fox() {
    for (int i = 1; i <= N; i++) fox[i] = INF;
    fox[1] = 0; 
    priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ fox[1],1 });
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        if (fox[cur.second] != cur.first) continue;
        for (const auto& nxt : edges[cur.second])
        {
            if (fox[nxt.second] <= fox[cur.second] + nxt.first) continue;
            fox[nxt.second] = fox[cur.second] + nxt.first;
            pq.push({ fox[nxt.second],nxt.second });
            
        }
    }
}

void dijkstra_wolf() {
    // 거리 , 다음 노드, 홀수번째 
    priority_queue <tuple<int,int,int>, vector<tuple<int,int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0,1,1});
    while (!pq.empty()) {
        int cost, node, state;
        tie(cost,node, state) = pq.top(); pq.pop();
        if (wolf[state][node] < cost) continue;
        for (const auto& nxt : edges[node])
        {
            if (state == 1) { // 이전 노드에 힘을 비축한 경우
                int next = nxt.second;
                int next_cost = cost + nxt.first / 2;
                if (wolf[0][next] > next_cost) {
                    wolf[0][next] = next_cost;
                    pq.push({ next_cost,next,0 });
                }
            }
            else if(state ==0) { // 속도를 내어 이전 노드를 방문한 경우
                int next = nxt.second;
                int next_cost = cost + nxt.first * 2;
                if (wolf[1][next] > next_cost) {
                    wolf[1][next] = next_cost;
                    pq.push({ next_cost,next,1 });
                }
            }
        }
    }
}


void solution() {
    for (int i = 1; i <= N; i++) {
        fox[i] = INF;
        wolf[0][i] = INF;
        wolf[1][i] = INF;
    }

    int answer = 0;
    dijkstra_fox();
    dijkstra_wolf();

    for (int i = 2; i <= N; i++)
        if (fox[i] < min(wolf[0][i], wolf[1][i])) answer++;

    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

