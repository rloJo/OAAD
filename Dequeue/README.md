## Dequeue
- 양쪽에서 추가, 삭제가 가능한 선형구조의 자료구조
- 스택과 큐의 장점을 모아서 만들어졌다.
- 추가 및 삭제의 시간복잡도 $$O(1)$$
- 벡터는 연속된 메모리 블록이지만 deque는 여러개의 블록을 동적으로 관리한다.

``` C++
#include <deque> // 헤더 선언

//deque <DataType> name;
deque<int> s1;
s1.push_front(val); // 앞쪽에 값 넣기
s1.push_back(val); // 뒷쪽에 값 넣기
s1.front(); // 맨 앞쪽값 추출
s2.back(); // 맨 뒷값 추
s1.pop_front(); // 앞쪽에 값 삭제
s1.pop_back(); // 뒷쪽에 값 삭제

s1[index]; // 배열처럼 접근 가능
s1.size(); // 요소 개수 반환
```


