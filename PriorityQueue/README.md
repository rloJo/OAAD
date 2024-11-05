## 우선순위 큐 (Priority Queue)
- 우선순위가 높은 데이터가 먼저 나가는 자료구조
- 일반적으로 힙(Heap)을 이용하여 구현한다.
- 힙은 완전 이진트리 형태의 자료구조
- 최솟값, 최댓값을 찾아내는 연산이 빠르다.


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
