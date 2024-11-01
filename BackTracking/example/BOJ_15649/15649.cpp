#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool vis[9];

void input() {
    cin >> N  >> M;
}

void backtracking(vector<int>&answer, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        answer.push_back(i);
        backtracking(answer, cnt+1);
        vis[i] = false;
        answer.pop_back();
    }
}

void solution() {
    vector<int> answer;
    backtracking(answer, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
}
