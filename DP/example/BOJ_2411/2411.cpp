#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 100;
int N, M, A, B;
int board[MAX + 10][MAX + 10];
int dp[MAX + 10][MAX + 10];

vector<pair<int, int>> items;


void input() {
	cin >> N >> M >> A >> B;
	for (int i = 0; i < A; i++) {
		int x, y; cin >> x >> y;
		items.push_back({ x,y });
	}

	items.push_back({ N,M });

	for (int i = 0; i < B; i++) {
		int x, y; cin >> x >> y;
		board[x][y] = -1;
	}
}

void solution() {
	dp[1][0] = 1;
	sort(items.begin(), items.end());
	int curX = 1, curY = 1;
	for (int cnt = 0; cnt < items.size(); cnt++) {
		int item_x = items[cnt].first;
		int item_y = items[cnt].second;
		for (int i = curX; i <= item_x; i++) {
			for (int j = curY; j <= item_y; j++) {
				if (board[i][j] == -1) dp[i][j] = 0;
				else if (board[i - 1][j] != -1 && board[i][j - 1] != -1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				else if (board[i - 1][j] != -1) dp[i][j] = dp[i - 1][j];
				else if (board[i][j - 1] != -1) dp[i][j] = dp[i][j - 1];
			}
		}
		curX = item_x;
		curY = item_y;
	}

	cout << dp[N][M] << "\n";
}


int main()
{
	input();
	solution();
	return 0;
}
