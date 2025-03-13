## 문제 조건

> [문제 링크]([https://school.programmers.co.kr/learn/courses/30/lessons/42898?language=java](https://school.programmers.co.kr/learn/courses/30/lessons/43163))
> 
> 
> 정답 비율 :61%
> 

### 풀이 과정

---

1. 알파벳이 1개만 바껴야 넘어갈 수 있는 조건이 있으므로 알파벳 차이를 확인하는 메소드를 만든다.
2. words를 방문하며 탐색한다. 이때 방문 배열을 만들어 방문 표시를 해야 탈출이 가능하다.
3. 만약 1번 조건에 어긋나면 다음 words로 넘어간다.
