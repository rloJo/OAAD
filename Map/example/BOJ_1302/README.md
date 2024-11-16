## 문제 조건
> <a href = "https://www.acmicpc.net/problem/1302"> 문제 링크 </a>  
> 시간제한 : 2초  
> 메모리 제한 : 128MB  
> 정답 비율 : 54.458%

### 풀이 과정
---
1. map에 책 제목을 기준으로 value인 int값을 증가시킨다.
2. 이때 사전순으로 먼저 오는 제목을 출력해야하므로 maxSelling의 값이 크거나 같으면 continue
3. 작으면 maxSelling과 answer(제목)을 갱신을 한다.
4. 정답 책 제목을 출력한다.

