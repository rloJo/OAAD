## 문제 조건
> <a href = "https://school.programmers.co.kr/learn/courses/30/lessons/144853#qna"> 문제 링크 </a>  

### 키 포인트
---
1. DATE 타입을 다룰줄 아는지 묻는 문제
2. DATE 타입에서 년도를 기준으로 검색을 하고싶으면
3. `YEAR(속성) = 찾는 년도` 로 찾을 수 있다.
4. 그리고 출력 형식을 지정하기 위해서는 `DATE_FORMAT(속성, "형식")`을 지정해줘야한다.
5. 위 문제는 DATE_FORMAT(PUBLISHED_DATE, "%Y-%m-%d") 형식을 사용했다.
