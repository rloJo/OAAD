#include <iostream>

using namespace std;

constexpr int MOD = 1000000007;
int T, N;

long long divide(long long a, long long b) {
	if (b <= 0) return 1;
	long long ans = divide(a, b / 2) % MOD;
	ans = ans * ans % MOD;
	if (b % 2) return a * ans % MOD;
	else return ans;
}

void solution() {
	cin >> T;
	while (T--) {
		cin >> N;
		cout << divide(2, N - 2) << "\n";
	}
}

int main()
{
	solution();
	return 0;
}
