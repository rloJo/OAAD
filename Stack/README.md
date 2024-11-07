## 스택 (Stack)
- 후입선출(Last In First Out) 자료구조
- top을 이용해 데이터를 추가하거나 pop한다.
  - top 을 증가시켜 데이터 삽입
  - top 을 감소시켜 데이터 삭제
- 삽입 및 삭제 O(1), 탐색 및 접근 O($$N$$) 

### 메소드
```c++
#include<stack> // 헤더 선언

//stack<DataType> name;
stack<int> st;

st.push(element); //요소 삽입
st.top(element); // 마지막 원소(마지막에 삽입한) 반환
st.pop();// 요소 삭제
st.size(); // 스택 크기 반환
st.empty(); // 스택이 비어있는지 검사
swap(st1,st2); // 스택끼리 swap
```
