## 문제 조건
> <a href = "https://www.acmicpc.net/problem/16118"> 문제 링크 </a>  
> 시간제한 : 1초  
> 메모리 제한 : 512MB  
> 정답 비율 : 	19.399%

### 풀이 과정
---
1. 여우는 다익스트라를 이용해 구한다.
2. 하지만 문제는 늑대이다 늑대는 홀수번째는 빠르게 이동하고 짝수번째는 느리게 이동한다.
3. 여기서 중요한 점이 입력을 받을때 홀수가 짝수가 되게 하기 위해 가중치에 2를 곱해 입력을 받았다.
4. 따라서 다익스트라인데 두가지를 구해야한다. 해당 노드를 홀수 번째로 방문하는 경우 + 해당 노드를 짝수번째로 방문하는 경우
5. 따라서 pq (우선순위큐)에 비용,node,홀수번째(state)인지를 해당하는 값을 넣어준다.
6. 이때 중요한 점이 기존 다익스트라는 cost[start]를 0 으로 초기화한다. 하지만 다시 되돌아가서 가는 경우 더 빠를 수 있기 때문에 초기화를 하면 안된다.
7. 그리고 wolf[state][node]의 값이 cost 보다 작으면 continue를 해준다. 구할 필요가 없기 때문!
8. 그리고 이제 엣지를 순회하며 값을 구한다.
9. 여기서 state가 1이면 힘을 비축한 상태라 nxt로 가는 시간의 절반이 걸린다
10. state 가 0이면 2배 이점을 유의하자.
11. 마지막으로 min(wolf[0][node], wolf[1][node]) 와 fox[node] 의 값중 fox가 작으면 answer에 1을 증가시킨다. 
