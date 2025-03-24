#include <iostream>

using namespace std;

int B[602][602];
int H, W, X, Y;

void input() {
	cin >> H >> W >> X >> Y;
	for (int i = 0; i < H + X; i++)
		for (int j = 0; j < W + Y; j++)
			cin >> B[i][j];
}

void solution() {
	for (int i = X; i < H; i++)
		for (int j = Y; j < W; j++)
			B[i][j] -= B[i - X][j - Y];

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cout << B[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	input();
	solution();
}
