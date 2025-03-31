#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> box;
int dp[1002];
int answer = 0;
void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> n;
	box = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}
}

void solution() {
	for (int i = 0; i < n; i++) dp[i] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[j] < box[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		answer = max(answer, dp[i]);
	}
	
	cout << answer << "\n";
} 

int main() {
	setting();
	input();
	solution();
}
