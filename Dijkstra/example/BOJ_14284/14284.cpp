#include <iostream>
#include <queue>

using namespace std;

const int INF = 500100;
int n, m, s, t;
vector<int> cost;
vector<vector<pair<int,int>>> edges;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> n >> m;
	cost = vector<int>(n + 1,INF);
	edges = vector<vector<pair<int, int>>>(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		edges[from].push_back({ weight,to });
		edges[to].push_back({ weight,from });
	}
	cin >> s >> t;
}

void solution() {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	cost[s] = 0;
	pq.push({ cost[s],s });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		if (cost[cur] != weight) continue;
		for (int i = 0; i < edges[cur].size(); i++) {
			pair<int,int> next = edges[cur][i];
			if (cost[next.second] <= cost[cur] + next.first) continue;
			cost[next.second] = cost[cur] + next.first;
			pq.push({ cost[next.second],next.second });
		}
	}
	
	cout << cost[t];
}

int main() {
	setting();
	input();
	solution();
}
