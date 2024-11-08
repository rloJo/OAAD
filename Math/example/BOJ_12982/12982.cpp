#include <iostream>
#include <algorithm>
using namespace std;

int K;
const int MAX = 100000;
int remain[MAX + 10];
int X[MAX + 10];

void solution() {
    int answer = 0;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int t;
        cin >> t;
        answer += t / K;
        t %= K;
        if(t!=0) remain[t]++;
    }

    for (int i = 1; i <= K; i++) X[i] = X[i - 1] + remain[i];
    int mn = 0x7f7f7f7f;
    for (int i = 0; i <= K; i++) mn = min(mn, i+ (X[K] - X[i]));

    cout << answer + mn;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}

