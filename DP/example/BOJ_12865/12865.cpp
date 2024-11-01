#include <iostream>
#include <vector>

using namespace std;

int N,K;
int weight[102];
int value[102];
int dp[102][100002];

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> weight[i] >> value[i];
}

void solution() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - weight[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][K];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
}
