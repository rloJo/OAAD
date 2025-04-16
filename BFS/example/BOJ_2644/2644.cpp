#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a, b;
vector<int> vis;
vector<int> edges[102];


void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> n;
	vis = vector<int>(n + 2, -1);
	cin >> a >> b;
	cin >> m;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}
}

void bfs(int st) {
	queue<int> q;
	q.push(st);
	vis[st] = 0;
	while (!q.empty()) {
		int cur = q.front(); 
		q.pop();
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i];
			if (vis[next] >= 0) continue;
			q.push(next);
			vis[next] = vis[cur] + 1;
		}
	}
}


void solution() {
	bfs(a);
	cout << vis[b];

}

int main() {
	setting();
	input();
	solution();
}
