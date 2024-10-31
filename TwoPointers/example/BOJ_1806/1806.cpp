#include<iostream>
#define MAX 100000

using namespace std;
// 입력 변수 선언
int N, S;
int sequence[MAX + 2];

void input() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> sequence[i];
}

void solution() {
    int answer = MAX + 1;
    int lcur = 1, rcur = 1;
    int sum = sequence[lcur];
    while (lcur <= rcur && rcur <= N) {
        if (sum >= S) {
            answer = min(answer, rcur - lcur + 1);
            sum -= sequence[lcur++];
        }
        else sum += sequence[++rcur];
    }
    if (answer == MAX + 1) answer = 0; // 빠지면 안됨 중요
    cout << answer;
}

int main(int argc, char** argv)
{
    input();
    solution();
    return 0;
} 
