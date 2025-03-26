#include <iostream>
#include <vector>

using namespace std;

int N, K;
int cost[12][12];
bool vis[12];
int answer = 0x3f3f3f3f;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
}

void floyd() {
	for (int mid = 0; mid < N; mid++) {
		for (int start = 0; start < N; start++) {
			for (int end = 0; end < N; end++) {
				if (cost[start][end] <= cost[start][mid] + cost[mid][end]) continue;
				cost[start][end] = cost[start][mid] + cost[mid][end];
			}
		}
	}
}

void tracking(int cnt, int prev, int d) {
	if (cnt == N) {
		answer = min(answer, d);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		tracking(cnt + 1, i, d + cost[prev][i]);
		vis[i] = false;
	}
}

void solution() {
	floyd();
	vis[K] = true;
	tracking(1,K,0);
	cout << answer << "\n";
} 

int main() {
	setting();
	input();
	solution();
}
