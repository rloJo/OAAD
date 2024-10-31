#include<iostream>
#include<queue>

using namespace std;

int T, N, K, W;
int buildTime[1002];

vector<vector<int>> edges;
vector<int> indgree;
vector<int> dp;

void input() {
    cin >> N >> K;
    indgree = vector<int>(N, 0);
    edges = vector<vector<int>>(N);
    dp = vector<int>(N, 0);
    for (int i = 0; i < N; i++) cin >> buildTime[i];
    for (int i = 0; i < K; i++) {
        int pre, in;
        cin >> pre >> in; 
        edges[--pre].push_back(--in);
        indgree[in]++;
    }
    cin >> W; --W;
}

int find_start() {
    int start = -1;
    for (int i = 0; i < N; i++) {
        if (indgree[i] == 0) {
            start = i;
            break;
        }
    }
    return start;
}

void topology() {
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        if (indgree[i] == 0) {
            Q.push(i);
            dp[i] = buildTime[i];
        }
    }

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int i = 0; i < edges[cur].size(); i++) {
            int nextNode = edges[cur][i];
            if (nextNode < 0) continue;
            dp[nextNode] = max(dp[nextNode], dp[cur] + buildTime[nextNode]);
            if (--indgree[nextNode] == 0) Q.push(nextNode);
        }
    }
}

void solution() {
    cin >> T;
    while (T--) {
        input();
        topology();
        cout << dp[W] << "\n";
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
    return 0;
}
