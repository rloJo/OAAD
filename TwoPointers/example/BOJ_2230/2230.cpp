#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;
int answer = 0x3f3f3f3f;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M;
	A = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());
}


void solution() {
	int left = 0, right = 0;
	while (right < N) {
		int diff = A[right] - A[left];
		if (diff > M) {
			answer = min(answer, diff);
			left++;
		}
		else {
			if(diff == M) answer = min(answer, diff);
			right++;
		}
	}

	cout << answer << "\n";
} 

int main() {
	setting();
	input();
	solution();
}
