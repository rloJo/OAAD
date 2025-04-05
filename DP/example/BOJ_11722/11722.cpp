#include <iostream>

using namespace std;

int N;
int A[1002];
int dp[1002];
int answer = 0;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

void solution() {
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] < A[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
} 

int main() {
	setting();
	input();
	solution();
}
