#include <iostream>
#include <vector>

using namespace std;

string str1, str2;
int LCS[1002][1002];

void input() {
    cin >> str1 >> str2;
}

void solution() {
    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (str1[i] == str2[j]) LCS[i + 1][j + 1] = LCS[i][j] + 1; 
            else LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
        }
    }

    cout << LCS[str1.size()][str2.size()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
}
