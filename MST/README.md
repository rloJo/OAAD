# 최소 신장 트리 (MST)
- 주어진 방향성이 없는 그래프의 부분 그래프 중에서 모든 정점을 포함하는 트리를 의미한다.
- 단, 사이클이 없어야한다.
- 신장 트리 중에서 간선의 합이 최소인 트리를 의미한다.
- 크루스칼(Kruskal) 알고리즘 과 프림 알고리즘 두가지가 있다
- 시간 복잡도 크루스칼 : O(ElogE) 프림 : O(ElogE)

## 크루스칼 알고리즘 흐름
---
1. 간선을 간선 비용의 오름차순으로 정렬하고 제일 낮은 비용의 간선을 선택한다.
2. 현재 선택한 간선이 정점 u,v를 연결하는 간선이라고 할 때, 만약 u와 v가 같은 그룹이라면 아무것도 하지 않는다.
3.  다른 그룹이라면 같은 그룹으로 만들고 현재 선택한 간선을 최소 신장 트리에 추가한다.
4.  최소 신장 트리에 V-1개의 간선을 추가시켰다면 과정을 종료, 그렇지 않다면 그 다음 비용이 작은 간선을 선택한 후 2,3번을 반복한다.


## 프림 알고리즘 흐름
---
1. 임의의 정점을 선택해 최소 신장 트리에 추가, 해당 정점과 연결된 모든 간선을 우선순위 큐에 추가
2. 우선순위 큐에서 비용이 가장 작은 간선을 선택
3. 만약에 해당 간선이 최소 신장 트리에 포함된 두 정점을 연결한다면 아무것도 하지 않고 넘어감, 해당 간선이 최소 신장트리에 포함된 정점 u와 포함되지 않은 정점 v를 연결한다면  해당 간선과 정점v를 신장 트리에 추가 후 정점 v와 최소 신장트리에 포함되지 않은 정점을 연결하는 모든 간선을 우선순위 큐에 추가.
4. 최소 신장 트리에 V-1 개의 간선이 추가될 때 까지 2,3번 과정을 반복.
```c++
int v,e;
// 비용, 도착 정점 번호
vector<pair<int,int>> adj[MAXNODE];
bool chk[MAXNODE]; // i번째 정점이 최소 신장트리에 있는가?
int cnt = 0; // 몇개의 노드가 포함되어 있는지 확인
//tuple <int,int,int> 비용,정점 1, 정점2
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
chk[1] = true; // 시작점 임의로 1로 설정
for(int i=0; i<adj[1].size();i++) pq.push({adj[1][i].first,1,adj[1][i].second);
while(cnt<v-1){
  int cost, a, b;
  tie(cost,a,b) = pq.top(); pq.pop();
  if(chk[b]) continue;
  chk[b] = true;
  cnt++;
  for(int i=0;i<adj[b].size();i++) {
    if(chk[adj[b].second]) continue;
    pq.push({adj[b].first,b,adj[b].second});
  }
}




```
   
