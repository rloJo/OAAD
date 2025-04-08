#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000001;
int N, M, X;
int cost[1002][1002];


void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M >> X;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			cost[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		cost[from][to] = weight;
	}
}

void solution() {
	for (int mid = 1; mid <= N; mid++) {
		for (int st = 1; st <= N; st++) {
			for (int ed = 1; ed <= N; ed++) {
				cost[st][ed] = min(cost[st][ed],cost[st][mid] + cost[mid][ed]);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, cost[i][X] + cost[X][i]);
	}

	cout << answer << "\n";
} 

int main() {
	setting();
	input();
	solution();
}
