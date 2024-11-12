#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 100000;
int N, M, p;
long long C[MAX + 10];
bool vis[MAX + 10];
vector<pair<int,long long>> item[MAX + 10];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> C[i];
    cin >> p;
    for (int i = 0; i < p; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        C[b] += t;
        item[a].push_back({ b,t });
    }
}

void solution() {
    long long answer = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
    for (int i = 1; i <= N; i++) pq.push({ C[i],i });
    int cnt = 0;
    while (cnt < M) {
        auto cur = pq.top(); pq.pop();
        if (vis[cur.second]) continue;
        vis[cur.second] = true;
        for (const auto& i : item[cur.second]) {
            if (vis[i.first]) continue;
            C[i.first] -= i.second;
            pq.push({ C[i.first],i.first });
        }
        answer = max(answer, cur.first);
        cnt++;
    }
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

