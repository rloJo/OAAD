## 문제 조건
> <a href = "https://www.acmicpc.net/problem/24041"> 문제 링크 </a>  
> 시간제한 : 2초  
> 메모리 제한 : 1024MB  
> 정답 비율 : 21.947%

### 풀이 과정
---
1. 부패 속도가 $S*max(1,x-L)$ 이기 때문에 10억 >= 1(x-10억) x의 값이 최대 약 20억 까지 가능하다.
2. 이때 재료를 빼는 것은 세균수가 많이 든것을 빼야한다. 따라서 우선순위 큐를 작은 것이 top이 되게 선언 후 해당 큐에 빼야하는 (세균이 많은)것이 pq에 있어야함
3. 따라서 20억개를 다 돌기에는 TLE가 난다. 따라서 이분 탐색을 통해 x의 값이 최대가 될 때를 구해야한다.
4. 각 날짜를 이분탐색으로 구한다. totalgerm은 총 세균 수를 의미한다.
5. 만약 중요 재료이면 넘기고 안좋은 재료인 경우 pq의 top 과 비교해서 세균의 수가 더 많이 들었으면 pq를 갱신한다.
6. 비교 후 마지막에 pq에있는 값을 모두 totalgerm에서 빼준다.
7. 마지막으로 totalgerm이 G보다 이하이면 조건에 충족하므로 정답을 갱신하고 left, right를 갱신하고 다시 탐색한다.
