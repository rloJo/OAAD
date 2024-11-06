#include <iostream>
#define MOD 100999

using namespace std;

int T;
int N;
int dp[2002][2002];

void input() {
    cin >> N;
}

void solution() {
    dp[0][0] = 1;
    for (int i = 1; i < 2001; i++) {
        dp[i][0] = 0;
        dp[0][i] = 1;
    }

    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 2001; j++) {
            if (i < j) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = (dp[i][j - 1] + dp[i - j][j - 1]) % MOD;
        }
    }
    cin >> T;
    while (T--) {
        input();
        cout << dp[N][N] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}

