#include<iostream>
#include<queue>
using namespace std;

int N, M;
vector<vector<int>> line;
vector<int> indgree;
void input() {
    cin >> N >> M;
    indgree = vector<int>(N + 1, 0);
    line = vector<vector<int>>(N + 1);
    for (int i = 1; i <= M; i++) {
        int A, B;
        cin >> A >> B;
        line[A].push_back(B);
        indgree[B]++;
    }
}

void solution() {
    queue<int> Q;
    for (int i = 1; i <= N; i++) {
        if (indgree[i] == 0) Q.push(i);
    }

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << " ";
        for (int i = 0; i < line[cur].size(); i++) {
            int next = line[cur][i];
            if (--indgree[next] == 0)  Q.push(next);
        }
    }

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solution();
    return 0;
}
