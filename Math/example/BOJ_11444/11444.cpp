#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<long long>> matrix;

constexpr long long MOD = 1000000007;
long long N;

inline void input() {
    cin >> N;
}

matrix operator *(const matrix& a, const matrix& b) {
    int Asize = a.size();
    matrix c(Asize, vector<long long>(Asize));
    for (int i = 0; i < Asize; i++) {
        for (int j = 0; j < Asize; j++) {
            for (int k = 0; k < Asize; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}

void solution() {
    if (N <= 1) {
        cout << N;
        return;
    }

    matrix a = { {1,1},{1,0} };
    matrix ans = { {1,0},{0,1} };

    while (N > 0) {
        if (N % 2) ans = ans * a;
        a = a * a;
        N /= 2;
    }

    cout << ans[0][1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

