#include <iostream>

using namespace std;

int T, n;
int dp[12];

void input() {
    cin >> n;
}

void solution() {
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i = 4; i <= 11; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    cin >> T;
    while (T--) {
        input();
        cout << dp[n];
    }
}

int main() {
    solution();
}
