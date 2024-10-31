# 플로이드 와샬 (Floyd Warshall)
- 모든 정점에서 모든 정점으로 최단 경로를 한번에 구하는 알고리즘
- DP 방식으로 각각의 원소들을 업데이트한다.
- i->j 로 가는데 해당 정점을 경유해서 가는 것이 더 빠르다면 그 정점을 거쳐서 가는 것으로 업데이트
- O($$N^3$$)의 시간복잡도
  
## 알고리즘 흐름
---
1. cost[v][v]의 모든 원소를 INF로 초기화
2. 간선 및 가중치를 입력받고 cost[start][end] 값 갱신한다. 자기자신과는 0
3. DP방식을 이용해 최단 거리를 구한다. dist[i][j] = min(dist[i][j],dist[i][n]+dist[n][j]) 
4. 거쳐갈 정점을 처음부터 차례로 검사를 시작한다.

```c++
int dp[4][4] = {
  {0,5,INF,8},
  {7,0,9,INF},
  {1,1,0,1},
  {INF,INF,3,0}
};


for(int mid = 0;i<N;i++) {
  for(int start=0;start<N;start++){
    for(int end =0; end<N;end++){
      if(dp[start][end] <= dp[start][mid] + dp[mid][end]) continue;
      dp[start][end] =  dp[start][mid] + dp[mid][end];
    }
  }
}
```
