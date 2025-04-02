#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<pair<int,int>> st;
vector<pair<int,int>> nums;
vector<int> answer;

void setting() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	nums = vector<pair<int,int>>(N);
	answer = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i].first;
		nums[i].second = i;
	}
}

void solution() {
	st.push(nums[0]);
	for (int i = 1; i < N; i++) {
		while (!st.empty() && st.top().first < nums[i].first) {
			answer[st.top().second] = nums[i].first;
			st.pop();
		}
		st.push(nums[i]);
	}

	while (!st.empty()) {
		answer[st.top().second] = -1;
		st.pop();
	}

	for (const auto& num : answer) cout << num << " ";
} 

int main() {
	setting();
	input();
	solution();
}
