## 문제 조건
> <a href = "https://school.programmers.co.kr/learn/courses/30/lessons/132201"> 문제 링크 </a>  

### 키 포인트
---
1. SELECT로 결과를 추출하면 NULL 값은 빈 값으로 출력이 된다.
2. 이떄 `COALESCE` 명령어로 NULL 값에 해당하는 값을 지정해줄 수 있다.
3. COALESCE(속성값, 표현할값) 으로 구성된다
4. COALESCE(TLNO,'NONE') 문제에서는 이렇게 표현했다.
