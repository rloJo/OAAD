#include <iostream>
#include <queue>

using namespace std;

const int INF = 10000;
int N, M;
vector<vector<pair<int, int>>> edges;
vector<int> cost;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> M >> N;
	cost = vector<int>(N * M + 2, INF);
	edges = vector<vector<pair<int, int>>>(N * M + 2);
	string maze = "S";
	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		maze += line;
	}
	int dx[4] = { -1,1, -M, M };

	for (int i = 1; i <= N * M; i++) {
		for (int dir = 0; dir < 4; dir++) {
			if ((i - 1) % M == 0 && dir == 0) continue;
			if ((i - 1) % M == M - 1 && dir == 1) continue;
			int next = i + dx[dir];
			if (next < 1 || next > N * M) continue;
			int weight = maze[next] == '1' ? 1 : 0;
			edges[i].push_back({ weight,next });
		}
	}
}

void solution() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	cost[1] = 0;
	pq.push({ cost[1],1 });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		if (cost[cur] != weight) continue;
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i].second;
			int nextWeight = edges[cur][i].first;
			if (cost[next] <= weight + nextWeight) continue;
			cost[next] = weight + nextWeight;
			pq.push({ cost[next],next });
		}
	}
	
	cout << cost[N * M];
}

int main() {
	setting();
	input();
	solution();
}
