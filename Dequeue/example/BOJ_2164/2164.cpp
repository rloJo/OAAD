#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> dq;


void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);
}

void solution() {
	while (dq.size() > 1) {
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}
	cout << dq.front();
} 

int main() {
	setting();
	input();
	solution();
}
