#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N;
long long x,y;
priority_queue<long long> smallQ;
priority_queue <long long, vector<long long>, greater<long long>> bigQ;
long long prev_dist = -1;
int prev_mid = -1;

void input() {
    cin >> x >> y;
}

void solution() {
    cin >> N;
    while(N--){
        input();

        int sQsize = smallQ.size();
        int bQsize = bigQ.size();

        if (bigQ.size() == smallQ.size()) smallQ.push(y);
        else bigQ.push(y);

        if (!bigQ.empty() && !smallQ.empty() && bigQ.top() < smallQ.top()) {
            long long tmp = bigQ.top(); bigQ.pop();
            bigQ.push(smallQ.top()); smallQ.pop();
            smallQ.push(tmp);
        }

        long long answer = 0;
        int mid = smallQ.top();

        if (prev_dist == -1 && prev_mid == -1)
            answer = abs(x);
        else
            answer = prev_dist + (long long)abs(prev_mid - mid) * (long long)abs(sQsize - bQsize) + abs(x) + abs(mid - y);
      
        cout << mid << " " << answer << "\n";
        prev_dist = answer; 
        prev_mid = mid;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solution();
}

