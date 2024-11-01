# 다익스트라 (Dijkstra)
- 하나의 시작점으로 부터 다른 모든 정점까지의 최단거리를 구하는 알고리즘.
- 우선순위 큐를 사용한다.(우선순위 큐에는 가중치, 번호 순으로 들어가며 가중치가 작은거 부터 pop())
- 방향 그래프, 무방향 그래프 모두 사용 가능하다.
- 간선 비용에 음수가 있으면 사용이 불가능 하다.
- 시간 복잡도 O(ElogV)

## 알고리즘 흐름
---
1. 간선을 입력 받을때 가중치, 다음노드 순으로 입력받는다.
  ```c++
  cin >> weight >> next;
  edges[i].push_back({weigt,next});
  ```
2. 시작점에서 부터 다른 노드까지의 거리를 저장하는 배열 cost를 선언하고 모든 정점에 INF(무한대) 값으로 갱신
3. 우선 순위에 시작점 (편의상 0)을 추가한다. 이때 자기 자신으로 가는 비용을 0으로 초기화 
3. 우선순위 큐에서 가중치가 가장 작은 원소를 선택한다. 이때, 해당 거리가 최단 거리 테이블에 있는 값과 다를 경우 넘어간다.
4. 원소가 가리키는 정점을 v라고 할 때, v와 이웃한 정점들에 대해 최단 거리 테이블 값보다 v를 거쳐가는 경구가 더 작은 값을
  가질 경우 최단 거리 테이블의 값을 갱신하고 우선순위 큐에 (거리,이웃한 정점의 번호)를추 가한다.
```c++
#define INF 0x7f7f7f7f
vector<int> cost(N);
vector<pair<int,int>> edges[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
cost[start] = 0;
pq.push({cost[start],start});
  while(!Q.empty()){
    auto cur = pq.top(); pq.pop();
    if(cost[cur.second]!=cur.first) continue;
    for(int i=0;i<edges[cur.second].size();i++){
      pari<int,int> next = edges[cur.second][i];
      if(cost[next.second] <= cost[cur.second] + next.first) continue;
      cost[next.second] = cost[cur.second] + next.first;
      pq.push({cost[next.second],next.second});
    }
}
```
