## 문제 조건
> <a href = "https://www.acmicpc.net/problem/18291"> 문제 링크 </a>  
> 시간제한 : 1초  
> 메모리 제한 : 256MB  
> 정답 비율 : 	33.755%

### 풀이 과정
---
1. 경우의 수를 구해보면 2일 때는 1, 3일 때는 2까지 가는 경우의수 + 1, 4는 2까지가는 경우의 수 + 3까지 가는 경우의 수 + 1.
  이다.
2. 여기서 $2^{N-2}$를 규칙을 알 수 있다.
3. 따라서 분할 정복을 이용해 $2^{N-2}$을 구한다.



