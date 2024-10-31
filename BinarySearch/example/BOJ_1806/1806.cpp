#include <iostream>
#define MAX 100000 
using namespace std;

// 입력 값 선언
int N, S;
int sequence[MAX + 2];
int prefixSum[MAX + 2]; // 누적 합을 구할 배열

void input() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> sequence[i];
        prefixSum[i] = sequence[i] + prefixSum[i - 1];
    }
}

void solution() {
    int answer = MAX+1;
    for (int i = 1; i <= N; i++) {
        int findIdx = lower_bound(prefixSum, prefixSum + N + 1 , S + prefixSum[i-1]) - prefixSum;
        //  prefixSum[i] - prefixSum[i-1]>= S인 최소거리를 찾고있다. 따라서
        // prefixSum[i] >= S + prefixSum[i-1] 인 값을 찾기위해 이분탐색 lowerbound 사용 후 인덱스 리턴 
        if (findIdx > N) continue; 
        answer = min(answer, findIdx - i + 1);
    }

    if (answer == MAX+1) answer = 0;   
  
    cout << answer;
}

int main(int argc, char** argv)
{   
    input();
    solution();
    return 0;
}
