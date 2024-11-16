#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 200000;
int N, G, K;
long long S[MAX + 10];
long long L[MAX + 10];
bool O[MAX + 10];
priority_queue<long long, vector<long long>, greater<long long> > pq;


void input() {
    cin >> N >> G >> K;
    for (int i = 1; i <= N; i++) {
        int isImportant;
        cin >> S[i] >> L[i] >> isImportant;
        if (!isImportant) O[i] = true;
    }
}

void solution() {
    int answer = 0;
    long long left = 0, right = 2000000000;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long totalgerm = 0;
        for (int i = 1; i <= N; i++) {
            long long germ = S[i] * max((long long)1, mid - L[i]);
            totalgerm += germ;
            if (O[i]) continue;
            if (pq.size() < K) pq.push(germ);
            else if (!pq.empty() && pq.top() < germ) {
                pq.pop();
                pq.push(germ);
            }
        }

        while (!pq.empty()) {
            totalgerm -= pq.top();
            pq.pop();
        }

        if (totalgerm <= G) {
            answer = (int) mid;
            left = mid + 1;
        }
        else right = mid - 1;
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

