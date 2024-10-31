#include<iostream>
#include<queue>
#include<set>
#include<map>
#define X first
#define Y second

using namespace std;

int N, K, R;

set<pair<int, int>>cows;
map <pair<int, int>, set<pair<int, int>>> road;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int farm[102][102];
bool vis[102][102];

void input() {
    cin >> N >> K >> R;
    for (int i = 1; i <= R; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        road[{x1-1,y1-1}].insert({x2-1,y2-1});
        road[{x2-1,y2-1}].insert({x1-1,y1-1});
    }
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        cows.insert({ x - 1,y - 1 });
    }
}

void init_vis() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            vis[i][j] = false;
}

bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= N || y >= N;
}

int bfs(pair<int, int> cow) {
    int missingCow = K - 1;
    init_vis();
    queue<pair<int, int>> Q;
    Q.push({ cow.X,cow.Y });
    vis[cow.X][cow.Y] = true;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || vis[nx][ny]) continue;
            if (road[{cur.X,cur.Y}].find({nx,ny}) != road[{cur.X, cur.Y}].end()) continue;
            if (cows.find({ nx,ny }) != cows.end()) missingCow--;
            Q.push({ nx,ny });
            vis[nx][ny] = true;
        }
    }
    return missingCow;
}

void solution() {
    int answer = 0;
    for (const auto& cow : cows) answer += bfs(cow);
  
    answer /= 2;
    cout << answer;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}
