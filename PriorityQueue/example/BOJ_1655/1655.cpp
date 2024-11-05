#include <iostream>
#include <queue>

using namespace std;

int N;
int num;
priority_queue<int> smallQ;
priority_queue<int, vector<int>, greater<int>> bigQ;

void input() {
    cin >> num;
}

void solution() {
    cin >> N;
    while(N--){
        input();
        if (bigQ.size() == smallQ.size()) smallQ.push(num);
        else bigQ.push(num);

        if (!bigQ.empty() && !smallQ.empty() && bigQ.top() < smallQ.top()) {
            int tmp = bigQ.top(); bigQ.pop();
            bigQ.push(smallQ.top()); smallQ.pop();
            smallQ.push(tmp);
        }
        cout << smallQ.top() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}
