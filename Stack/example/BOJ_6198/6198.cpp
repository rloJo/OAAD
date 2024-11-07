#include <iostream>
#include <stack>

using namespace std;

int N;

void solution() {
    cin >> N;
    long long answer = 0;
    stack<int> height;
    for (int i = 1; i <= N; i++) {
        int floor;
        cin >> floor;
        if (height.empty()) {
            height.push(floor);
            continue;
        }

        while (!height.empty() && height.top() <= floor) height.pop();
        answer += (long long) height.size();
        height.push(floor);
    }

    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}

