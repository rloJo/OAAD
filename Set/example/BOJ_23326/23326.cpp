#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, Q;
set<int> section;
int dh;

void input() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int isNamed; cin >> isNamed;
        if (isNamed) section.insert(i);
    }
}

void solution() {
    int instrcution;
    while (Q--) {
        cin >> instrcution;
        if (instrcution == 1) {
            int i;
            cin >> i; --i;
            if (section.find(i) != section.end()) section.erase(i);
            else section.insert(i);
        }
        else if (instrcution == 2) {
            int x;
            cin >> x;
            dh = (dh + x) % N;
        }
        else {
            if (section.size() == 0) cout << -1 << '\n';
            else {
                auto pos = section.lower_bound(dh);
                if (pos == section.end()) {
                    pos = section.begin();
                    cout << (N - dh) + *pos << '\n';
                }
                else {
                    cout << *pos - dh << '\n';
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}
