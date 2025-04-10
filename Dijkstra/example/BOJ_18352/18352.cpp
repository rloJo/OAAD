#include <iostream>
#include <queue>

using namespace std;

int N, M;
int K, X;
const int INF = 300100;
vector<int> cost;
vector<vector<pair<int, int>>> edges;


void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M >> K >> X;
	cost = vector<int>(N + 1,INF);
	edges = vector<vector<pair<int, int>>>(N + 1);

	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		edges[from].push_back({1,to});
	}
}

void solution() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	cost[X] = 0;
	pq.push({ cost[X],X });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		if (cost[cur] != weight) continue;
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i].second;
			int nWeight = edges[cur][i].first;
			if (cost[next] <= cost[cur] + nWeight) continue;
			cost[next] = cost[cur] + nWeight;
			pq.push({ cost[next],next });
		}
	}
	
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (cost[i] == K) {
			count++;
			cout << i << "\n";
		}
	}

	if (count == 0) cout << "-1";
}

int main() {
	setting();
	input();
	solution();
}
