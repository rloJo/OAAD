#include <iostream>

using namespace std;

long long N,K;

void input() {
	cin >> N >> K;
}

void solution() {
	long long left = 1, right = N*N;
	long long mid;

	while (left < right) {
		mid = (left + right) / 2;
		long long count = 0;
		for (int i = 1; i <= N; i++) {
			count += min(mid / i, N);
		}

		if (count < K) left = mid + 1;
		else right = mid;
	}

	cout << right;
}

int main() {
	input();
	solution();
	return 0;
}
