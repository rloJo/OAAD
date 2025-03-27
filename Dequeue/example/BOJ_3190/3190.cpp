#include <iostream>
#include <set>
#include <deque>
#include <queue>

#define X first
#define Y second

using namespace std;

int N, K, L;
set<pair<int, int>> apples;
deque<pair<int, int>> snake;
queue<pair<int, char>> ins;

int snakeDir = 1;
int curTime = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int ax, ay;
		cin >> ax >> ay;
		apples.insert({ ax,ay });
	}
	cin >> L;
	snake.push_back({ 1,1 });
}

bool isBody(int nx, int ny) {
	for (auto c : snake) {
		if (c.X == nx && c.Y == ny) return true;
	}
	return false;
}

bool snakeMove() {
	pair<int, int> head = snake.front();
	int nx = head.X + dx[snakeDir];
	int ny = head.Y + dy[snakeDir];
	if (nx < 1 || ny < 1 || nx > N || ny > N || isBody(nx, ny)) return true;

	snake.push_front({ nx,ny });
	if (apples.find({ nx,ny }) == apples.end()) snake.pop_back();
	else apples.erase({ nx,ny });
	return false;
}

void solution() {
	for (int i = 0; i < L; i++) {
		int t; char instruction;
		cin >> t >> instruction;
		ins.push({ t,instruction });
	}

	while (1) {
		if (!ins.empty() && ins.front().first == curTime) {
			if (ins.front().second == 'L') snakeDir = (snakeDir + 1) % 4;
			else snakeDir = (snakeDir + 3) % 4;
			ins.pop();
		}
		curTime++;
		if(snakeMove()) break;
	}
	cout << curTime;
} 

int main() {
	setting();
	input();
	solution();
}
