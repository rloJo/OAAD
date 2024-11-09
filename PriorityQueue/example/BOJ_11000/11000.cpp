#include <iostream>
#include <queue>
#include <algorithm>
#define st first
#define ed second

using namespace std;

const int MAX = 200000;
int N;
vector<pair<int, int>> lecture;

void input() {
    cin >> N;
    lecture = vector<pair<int, int>>(N);
    for (int i = 0; i < N; i++) cin >> lecture[i].st >> lecture[i].ed;
}

void solution() {
    sort(lecture.begin(), lecture.end());
    priority_queue<int,vector<int>,greater<int>> pq;

    int answer = 0;
    for (const auto& lec : lecture) {
        if (!pq.empty()) while (!pq.empty() && pq.top() <= lec.st) pq.pop();
        pq.push(lec.ed);
        answer = max(answer, (int)pq.size());
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

