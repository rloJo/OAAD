## 문제 조건
> <a href = "https://www.acmicpc.net/problem/1368"> 문제 링크 </a>  
> 시간제한 : 2초  
> 메모리 제한 : 128MB  
> 정답 비율 : 43.333%

### 풀이 과정
---
1. 자기 자신의 우물을 기르는 경우는 N+1의 노드를 임의로 추가하여 해당 노드의 간선으로 생각하고 풀이
2. 프림 알고리즘을 사용해 우선순위 큐에서 pop하고 방문 안한점이면 answer 값 증가
3. 우선 간선 입력을 받아 edges에 삽입해준다. [시작점]{비용,도착점}
4. 임의의 한점을 택하고 해당 점이 연결되어있는 모든 간선을 우선순위 큐에 넣는다.
5. 만약 방문하지 않은점이면 해당 점의 모든 간선을 다시 넣는다.
6. 간선의 수가 N-1개일때 까지 반복 여기서는 N (임의의 정점을 1개 추가했기 때문)

### 트러블 슈팅
---
1. 임의의 간선을 추가하고 간선을 입력받았지만 양방향이라는 것을 생각안했다.
2. answer의 값 증가를 우선순위 큐에서 pop했을 때만 수행했어야 했는데 for문에서 해버렸다.

<p> 해결 방법 : 입력을 받을 때 양방향으로 넣어주고 우선순위 큐에서 pop하고 방문 안한 점이였을 떄 간선의 가중치를 answer에 더해줌</p>