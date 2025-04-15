#include <iostream>

using namespace std;

int dp[1002][1002];
int ground[1002][1002];
int N, M;
int answer;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> ground[i][j];
}

void solution() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if(ground[i][j] == 0)
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
			answer = max(answer, dp[i][j]);
		}
	}

	cout << answer;
}

int main() {
	setting();
	input();
	solution();
}
