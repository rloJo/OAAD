#include <iostream>
#include <queue>
#include <tuple>

using namespace std;


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, M;
int board[52][52];
bool vis[52][52];
vector<vector<int>> dp;

void input() {
    cin >> N >> M;
    dp = vector<vector<int>>(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < line.size(); j++) {
            if (line[j] == 'H') board[i][j] = 0;
            else board[i][j] = line[j] - '0';
        }
    }

}

inline bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

int dfs(int x, int y) {
    if (OOB(x, y) || board[x][y] == 0) return 0;
    if (vis[x][y]) {
        cout << -1 << '\n';
        exit(0);
    }
    if (dp[x][y] != -1) return dp[x][y];
    vis[x][y] = true;
    dp[x][y] = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + board[x][y] * dx[dir];
        int ny = y + board[x][y] * dy[dir];
        dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
    }

    vis[x][y] = false;
    return dp[x][y];
}

void solution() {
    int answer = 0;
    answer = dfs(0, 0);
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

