## 문제 조건
> <a href = "https://www.acmicpc.net/problem/12865"> 문제 링크 </a>  
> 시간제한 : 2초  
> 메모리 제한 : 512MB  
> 정답 비율 : 36.237%

### 풀이 과정
---
1. 냅섹 알고리즘을 활용.
2. 모든 물건의 가치와 무게를 저장
3. 모든 물건을 돌면서 DP배열을 채운다. DP[현재까지온 물건 번호][남은 무게]
4. i번째를 가방에 넣을 수 있다면 DP[i][j] = MAX(DP[i-1][j],DP[i-1][j-weight[i]] + v[i])이다.
5. 넣을 수 없다면 이전 번호까지의 DP값이 넘어온다 DP[i][j] = DP[i-1][j];

