#include <iostream>

using namespace std;

int N;
string word;
int dp[1002];

void input() {
	cin >> N;
	cin >> word;
	for (int i = 0; i < N; i++) dp[i] = 0x3f3f3f3f;
	dp[0] = 0;
}

void solution() {
	for (int i = 0; i < N; i++) {
		if (word[i] == 'B') {
			for (int j = i + 1; j < N; j++) {
				if (word[j] == 'O')	dp[j] = min(dp[j], dp[i] + (j-i) * (j - i));
			}
		}
		else if (word[i] == 'O') {
			for (int j = i + 1; j < N; j++) {
				if (word[j] == 'J') dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
			}
		}

		else {
			for (int j = i + 1; j < N; j++) {
				if (word[j] == 'B') dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
			}
		}
	}

	if (dp[N-1] == 0x3f3f3f3f) cout << "-1";
	else cout << dp[N - 1];
}

int main() {
	input();
	solution();
}
