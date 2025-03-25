#include <iostream>

using namespace std;

const int mod = 1000000000;
int N;
long long dp[102][12];
long long answer; 

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
}

void solution() {
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1] % mod;
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%mod;
		}
	}
	
	for (int i = 1; i < 10; i++) {
		answer = (answer+dp[N][i]) %mod;
	}

	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
