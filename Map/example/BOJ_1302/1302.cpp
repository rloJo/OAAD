#include <iostream>
#include <map>
using namespace std;

int N;
map<string, int> books;

void input() {
    cin >> N;
    string name;
    while (N--) {
        cin >> name;
        books[name]++;
    }
}
void solution() {
    int maxSelling = 0;
    string answer = "";
    for (const auto& book : books) {
        if (maxSelling >= book.second) continue;
        maxSelling = book.second;
        answer = book.first;
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solution();
    return 0;
}

