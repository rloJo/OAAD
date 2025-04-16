#include <iostream>
#include <queue>

using namespace std;

const int INF = 2000;
int n, m;
int a, b;
vector<pair<int, int>> edges[102];
vector<int> cost;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> n;
	cost = vector<int>(n + 1, INF);
	cin >> a >> b;
	cin >> m;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		edges[from].push_back({ 1,to });
		edges[to].push_back({ 1,from});
	}
}

void solution() {
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	cost[a] = 0;
	pq.push({ cost[a],a });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		if (cost[cur] != weight) continue;
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i].second;
			int nextWeight = edges[cur][i].first;
			if (cost[next] <= cost[cur] + nextWeight) continue;
			cost[next] = cost[cur] + nextWeight;
			pq.push({ cost[next] ,next });
		}
	}

	if (cost[b] == INF) cout << -1;
	else cout << cost[b];
}

int main() {
	setting();
	input();
	solution();
}
