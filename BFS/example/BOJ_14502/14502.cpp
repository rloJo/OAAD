#include <iostream>
#include <queue>
#include <vector>
#define X first 
#define Y second

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int lab[10][10];
vector<pair<int, int>> virusSpot;
bool vis[10][10];
int answer = 0;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) virusSpot.push_back({ i,j });
		}
	}
}

inline bool OOB(int nx, int ny) {
	return nx < 0 || nx >= N || ny < 0 || ny >= M;
}

int countSafeZone() {
	int safe = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (vis[i][j] == false && lab[i][j] == 0) safe++;
	
	return safe;
}


void virusInfection() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			vis[i][j] = false;
	}

	queue<pair<int, int>> Q;

	for (auto spot : virusSpot) Q.push(spot);
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		vis[cur.X][cur.Y] = true;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (vis[nx][ny]) continue;
			if (lab[nx][ny] != 0) continue;
			Q.push({ nx,ny });
			vis[nx][ny] = true;
		}
	}
}

void buildWall(int buildCount, int idx) {
	if (buildCount == 3) {
		virusInfection(); 
		answer = max(answer, countSafeZone());
		return;
	}

	for (int i = idx; i < N * M; i++) {
		int nx = i / M;
		int ny = i % M;
		if (lab[nx][ny] != 0) continue;
		lab[nx][ny] = 1;
		buildWall(buildCount + 1, i);
		lab[nx][ny] = 0;
	}
}

void solution() {
	buildWall(0,0);
	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
