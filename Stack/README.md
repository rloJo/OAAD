## 스택 (Stack)
- 후입선출(Last In First Out) 자료구조
- top을 이용해 데이터를 추가하거나 pop한다.
  - top 을 증가시켜 데이터 삽입
  - top 을 감소시켜 데이터 삭제
- 삽입 및 삭제 O(1), 탐색 및 접근 O($$N$$) 





### 메소드
```c++
#include <queue> // 헤더 선언

//priority_queue<DataType> name;
priority_queue<int> Q;

//삽입
Q.push(data); //데이터 추가
Q.top(); //first 데이터 반환
Q.pop(); // 데이터 삭제
Q.size(); // 큐 현재 크기 반환
Q.empty(); // 큐가 비어있는지 확인
```
