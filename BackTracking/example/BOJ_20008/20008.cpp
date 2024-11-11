#include <iostream>
#include <queue>
#include <algorithm>
#define C second
#define D first

using namespace std;

int N, HP, answer = 0x7f7f7f7f;
vector<pair<int,int>> skills;
int remain[7];

void input() {
    cin >> N >> HP;
    skills = vector<pair<int,int>>(N);
    for (int i = 0; i < N; i++) cin >> skills[i].C >> skills[i].D;
}

void dfs(int Time, int hp, vector<int>& cool) {
    if (hp <= 0) {
        answer = min(answer, Time);
        return;
    }

    bool flag = false;

    for (int i = 0; i < N; i++) {
        if (cool[i] + skills[i].C <= Time) { // 사용한 시점 ~ 흐른시간이 현재시간 보다 작거나 같으면 사용가능하다.
            vector<int> tmp = cool; tmp[i] = Time;
            dfs(Time + 1, hp - skills[i].D, tmp);
            flag = true;
        }
    }
    if (!flag) dfs(Time+1, hp, cool); // 사용한 스킬이 없으면 1초 증가하고 다음 작업 진행
}


void solution() {
    vector<int> cool(N, -1000000000);
    dfs(0,HP,cool);
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

