#include <iostream>
#include <stack>

using namespace std;

int N;

void solution() {
    stack<pair<int,int>> top;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;
        if (top.empty()) {
            top.push({ height,i });
            cout << "0 ";
            continue;
        }

        while (!top.empty() && top.top().first <= height) top.pop();
        if (top.empty()) cout << "0 ";
        else cout << top.top().second << " ";
        top.push({ height, i });
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}

