#include <iostream>

using namespace std;

const int MAX = 100000;
int N;
long double percent[MAX + 10];

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> percent[i];
}

void solution() {
    long double answer = 0;
    for (int i = 1; i < N; i++) {
        answer += percent[i];
        answer += percent[i] * (1 - percent[i + 1]) + (1 - percent[i]) * percent[i+1];
    }
    answer += percent[N];
    cout << fixed;
    cout.precision(6);
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

