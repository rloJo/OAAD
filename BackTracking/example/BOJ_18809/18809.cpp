#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

struct info {
	int color;
	int time;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, M, G, R;
int garden[52][52];
vector<pair<int,int>> canSeed;
vector<int> RedSeed;
vector<int> GreenSeed;
bool seed[12];
int answer = 0;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> garden[i][j];
			if (garden[i][j] == 2) canSeed.push_back({ i,j });
		}
	}
}

int difussion() {
	info vis[52][52];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			vis[i][j].color = -1;
			vis[i][j].time = -1;
		}
	
	int flower = 0;

	queue<pair<int, int>> Q;
	for (auto& idx : RedSeed)
	{		
		vis[canSeed[idx].X][canSeed[idx].Y] = { 0,0 };
		Q.push(canSeed[idx]);
	}
	for (auto& idx : GreenSeed) {
		vis[canSeed[idx].X][canSeed[idx].Y] = { 1,0 };
		Q.push(canSeed[idx]);
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int t = vis[cur.X][cur.Y].time;
		int col = vis[cur.X][cur.Y].color;
		if (col == 3) continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (garden[nx][ny] == 0) continue;
			if (vis[nx][ny].color == -1) {
				vis[nx][ny] = { col , t + 1 };
				Q.push({ nx,ny });
			}
			else if (vis[nx][ny].color != 3) {
				if (vis[nx][ny].color!= col && vis[nx][ny].time == t + 1) {
					vis[nx][ny].color = 3;
					flower++;
				}
			}

		}
	}

	return flower;
}

void dfs(int idx, int Rcnt, int Gcnt) {
	if (Rcnt < 0 || Gcnt < 0) return;
	if (Rcnt == 0 && Gcnt == 0) {
		answer = max(answer, difussion());
		return;
	}

	for (int i = idx; i < canSeed.size(); i++) {
		if (seed[i]) continue;
		seed[i] = true;
		RedSeed.push_back(i);
		dfs(i, Rcnt - 1, Gcnt);
		RedSeed.pop_back();
		GreenSeed.push_back(i);
		dfs(i, Rcnt, Gcnt -1);
		GreenSeed.pop_back();
		seed[i] = false;
	}
}

void solution() {
	dfs(0, R, G);
	cout << answer << "\n";
} 

int main() {
	setting();
	input();
	solution();
}
