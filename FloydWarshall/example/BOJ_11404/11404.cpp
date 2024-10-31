#include<iostream>
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int cost[102][102];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cost[i][j] = INF;
        cost[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        cost[from][to] = min(cost[from][to],val);
    }
}

void solution() {
    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start <= n; start++) {
            for (int ed = 1; ed <= n; ed++) {   
                cost[start][ed] = min(cost[start][ed],cost[start][mid] + cost[mid][ed]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost[i][j] == INF) cout << "0 ";
            else cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}
