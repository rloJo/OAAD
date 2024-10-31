# 너비 우선 탐색 (Breadth-First Search)
- 임의의 노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법.
- 시작 노드로부터 가까운 노드를 먼저 방문하고 떨어져 있는 정점을 나중에 방문하는 순회 방법
- 두 노드의 **최단 경로** 또는 **임의의 경로**를 찾고 싶을 때 BFS를 사용한다.
- 큐를 이용해 구현
- O($$N^2$$)의 시간 복잡도
## 알고리즘 흐름
---
1. 시작 점을 큐에 삽입하고 방문 배열에 값을 true로 갱신한다.
```c++
queue<pair<int,int>> Q;
Q.push(start)
```
2. Q에서 정점을 pop으로 bfs가 시작된다.
3. pop으로 나온 점에서 갈수있는 점을 탐색하여 조건을 맞춘다. (OutOfBound, 갈수없게 설정, 이미 방문한 배열 등)
4. 조건에 맞지 않는 점이면 넘어간다.
5. 갈 수있는 점이면 Q에 해당 정점을 삽입하고 해당 점의 방문 갱신을 해준다.
6. Q가 빌때 까지 2~5번 과정을 반복한다.
```c++
while(!Q.empty()){
  auto cur = Q.front(); Q.pop();
  for(int dir = 0; dir<4; dir++){ // for(int i=0;i<edges[cur];i++)
    int nextNode = cur + dx[dir]; // int nextNode = edges[cur][i];
    if(OOB(nextNode) || vis[nextNode]) continue;
    push(nextNode);
    vis[nextNode] = true;
  }
}
```
