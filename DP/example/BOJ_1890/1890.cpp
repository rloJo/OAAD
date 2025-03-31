#include <iostream>

using namespace std;

int N;
int board[102][102];
long long dp[102][102];

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
}


void solution() {
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;
			int val = board[i][j];
			int Down = val + i;
			int Right = val + j;

			if (Down < N) dp[Down][j] += dp[i][j];
			if (Right < N) dp[i][Right] += dp[i][j];
		}
	}

	cout << dp[N - 1][N - 1];

} 

int main() {
	setting();
	input();
	solution();
}
