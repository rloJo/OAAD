#include <iostream>
#include <stack>

using namespace std;

const int MAX = 200000;
int n;
string str;
bool a[MAX + 10];

void input() {
    cin >> n;
    cin >> str;
}

void solution() {
    stack<int> isCorrect;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') isCorrect.push(i);
        else {
            if (!isCorrect.empty()) {
                a[i] = true;
                a[isCorrect.top()] = true;
                isCorrect.pop();
            }
        }
    }
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            cnt++;
            answer = max(answer, cnt);
        }
        else cnt = 0;
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

