## Set
- Unique한 원소들을 특별한 순서에 따라 저장하는 컨테이너
- Key 값은 중복 불가능하다.
- 균형 이진 트리로 구현되어 있다.
- 원소를 삽입하면 Key를 기준으로 자동 오름차순 정렬된다.
- 탐색, 삽입, 삭제에 $O(logN)$ 의 시간복잡도. 삽입 삭제 시, 최악의 경우 $O(N)$
- 빠른 속도로 데이터 처리가 가능하다
- Set은 데이터 삽입시, 복사생성자를 사용한다. 따라서 객체가 크거나 복잡한 경우 성능 문제가 발생할 수 있다. 
``` C++
#include <set> // 헤더 선언

//set <DataType> name;
set<int> s1;
s1.begin(); // 첫 번째 원소를 가리키는 반복자 return
s1.cbegin(); // 첫 번째 원소를 가리키는 상수 반복자 return
s1.end(); // 마지막 원소를 가리키는 반복자 return
s1.cend(); // 마지막 원소를 가리키는 상수 반복자 return
s1.rbegin(); //역 순차열의 첫 번째원소 가리키는 반복자 return
s1.rend(); //역 순차열의 마지막 원소 가리키는 반복자 return


s1.find(target); // target값의 키가 있으면 해당 위치의 반복자 없으면 set.end()를 반환한다.
s1.front(); // 첫 번째 원소 return
s1.back(); // 마지막 원소 return

s1.empty(); // set이 비어있으면 true, 있으면 false return
s1.size(); // 원소의 개수 return

s1.clear(); //모든 원소를 삭제한다.
s1.insert(key); // key 추가
s1.erase(key); // 해당 key 삭제

```
## unordered_set
- 원소들이 정렬 되어있지 않다.
- 해시 테이블로 구현 되어있다.
- bucket으로 인한 메모리 사용량이 증가한다.
- 삽입, 삭제, 탐색에 $O(1)$의 시간 복잡도
- 중복값을 허용하지 않는다.
- 순서가 보장되지 않아 set보다 빠른 삽입, 검색 속도를 갖는다.
- 크기가 작을 때 유리하다
- 크기가 크면 충돌이 많이 일어나 $O(N)$의 시간 복잡도를 갖는다.


### 메소드
```c++
// 헤더 선언
#include <unordered_set>

//unordered_set<DataType> name;
unordered_set<int> s1;
s1.find(target); // target값의 키가 있으면 해당 위치의 반복자 없으면 set.end()를 반환한다.

s1.empty(); // set이 비어있으면 true, 있으면 false return
s1.size(); // 원소의 개수 return

s1.clear(); //모든 원소를 삭제한다.
s1.insert(key); // key 추가
s1.erase(key); // 해당 key 삭제
//삽입

```
