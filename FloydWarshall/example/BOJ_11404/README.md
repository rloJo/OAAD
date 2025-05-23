## 문제 조건
> <a href = "https://www.acmicpc.net/problem/11404"> 문제 링크 </a>  
> 시간제한 : 1초  
> 메모리 제한 : 256MB  
> 정답 비율 : 42.205%

### 풀이 과정
---
1. cost 배열의 모든 값을 INF로 초기화한다. 자기 자신은 0
2. 동일 노선이 여러개일 수도 있으므로 값을 입력할때 최솟값으로 넣는다.
3. 플로이드 와샬알고리즘을 사용하여 모든 정점의 최소 비용을 구한다.
4. mid -> start -> end순으로 for문을 돈다. 이때 [start][end]의 값이 최소가 되게 [start][end] [start][mid] + [mid][end] 값에서 최소로 갱신

###  트러블 슈팅
---
cost 배열에 쓰레기 값이 들어갔다.  
INF를 정의할 때 **0x7f7f7f7f**라고 정의했는데 이 값이 약 21억으로 int의 최댓값과 근사하다 따라서 계산시 오류가 발생할 수 있다고한다.  
해결 방법 : **0x3f3f3f3f** 로 수정하여 풀이

