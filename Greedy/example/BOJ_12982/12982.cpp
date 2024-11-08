#include <iostream>

using namespace std;

int RGB[3];
const int MAX = 1000000;
void input() {
    cin >> RGB[0] >> RGB[1] >> RGB[2];
}

void solution() {
    int answer = 0;
    for (int i = 0; i < 3; i++) {
        answer += RGB[i] / 3;
        RGB[i] %= 3;
    }

    if (RGB[0] > 0 && RGB[1] > 0 && RGB[2] > 0) {
        int mn = min(RGB[0], min(RGB[1], RGB[2]));
        answer += mn;
        for (int i = 0; i < 3; i++) RGB[i] -= mn;
    }

    int mn = MAX; int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (RGB[i] <= 0) continue;
        mn = min(mn, RGB[i]);
        cnt++;
    }

    if (cnt >= 2) {
        answer += mn;
        for (int i = 0; i < 3; i++) RGB[i] -= mn;
    }
    
    for (int i = 0; i < 3; i++) {
        if (RGB[i] <= 0) continue;
        answer += RGB[i] / 2;
        answer += RGB[i] % 2;
    }

    cout << answer << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
}

