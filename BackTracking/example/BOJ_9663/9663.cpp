#include <iostream>
#include <vector>

using namespace std;

int N;
bool isused1[35];
bool isused2[35];
bool isused3[35];

int answer;

void input() {
    cin >> N;
}

void backtracking(int cur) {
    if (cur == N) {
        answer++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isused1[i] || isused2[cur+i] || isused3[cur-i+N-1]) continue;
        isused1[i] = true;
        isused2[cur + i] = true;
        isused3[cur - i + N - 1] = true;
        backtracking(cur + 1);
        isused1[i] = false;
        isused2[cur + i] = false;
        isused3[cur - i + N - 1] = false;
    }
}

void solution() {
    backtracking(0);
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
}
