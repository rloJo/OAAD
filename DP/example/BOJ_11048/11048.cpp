#include <iostream>
#include <vector>

using namespace std;

int N, M;
int maze[1002][1002];
int dp[1002][1002];


void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> maze[i][j];
	}
}

void solution() {
	dp[1][1] = maze[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int fromUp = dp[i - 1][j];
			int fromLeft = dp[i][j - 1];
			int fromTopLeft = dp[i - 1][j - 1];
			dp[i][j] = max(fromUp, max(fromLeft, fromTopLeft)) + maze[i][j];
		}
	}

	cout << dp[N][M];
} 

int main() {
	setting();
	input();
	solution();
}
