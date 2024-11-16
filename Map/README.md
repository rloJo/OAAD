## Map
- key-value 쌍으로 데이터를 저장하는 연관 컨테이너
- 레드-블랙 트리로 구현되어 있다.
- **key 값은 unique**한 값이다.
- 중복 불가능하다.
- key 값을 기준으로 정렬되어있다.
- 검색, 삽입, 삭제 $O(logN)$의 시간 복잡도를 갖는다.

``` C++
#include <map> // 헤더 선언

map<int> m;
m.begin(); // 첫 번째 원소를 가리키는 반복자 return
m.cbegin(); // 첫 번째 원소를 가리키는 상수 반복자 return
m.end(); // 마지막 원소를 가리키는 반복자 return
m.cend(); // 마지막 원소를 가리키는 상수 반복자 return
m.rbegin(); //역 순차열의 첫 번째원소 가리키는 반복자 return
m.rend(); //역 순차열의 마지막 원소 가리키는 반복자 return

m.at(key); // key에 해당하는 value를 반환한다. key가 존재하지 않을 시 예외 발생
m[key]; //key에 대응하는 value 반환

m.find(target); // target값의 키가 있으면 해당 위치의 반복자 없으면 set.end()를 반환한다.

m.empty(); // set이 비어있으면 true, 있으면 false return
m.size(); // 원소의 개수 return
m.max_size(); // 담을 수 있는 원소의 최대 개수 반환

m.clear(); //모든 원소를 삭제한다.
m.insert(); // 새로운 원소 추가
m.erase(key); // 해당 key 삭제
m.count(key); // 해당 키를 갖는 원소의 개수 출력 * map은 중복을 허용하지 않으므로 있으면 1 없으면 0 출력
m.emplace(); // 새로운 원소 삽입하는 함수 insert보다 조금 더 빠르다. 새로운 데이터를 생성하는데 필요한 인수를 직접 전달할 수 있는 장점 
```
## unordered_map
- key와 value쌍으로 저장되는 연관 컨테이너
- **key 값은 unique**한 값이다.
- map보다 더 빠른 검색 속도를 갖는다.
- 해쉬 테이블로 구성되어 있음
- 중복 데이터 허용하지 않는다.
- 탐색 O(1)의 시간 복잡도
- 자료가 많을 때는 좋지만 자료가 적을 때는 메모리 낭비와 검색시 오버헤드가 생길 수 있다.
  - 데이터가 적을 경우 vector 사용이 유리
  - 데이터가 적을 경우 map이 유리할 수 있다. unordered_map은 큰 경우 유리
    - map의 크기가 커질때마다 캐시 미스의 영향을 받으므로 탐색을 위해 여러 노드를 방문해야 하는 이슈가 있음


### 메소드
```c++
// 헤더 선언
#include <unordered_map>

//unordered_map<keyType,valueType> name;
unordered_map <int,string> m;

m.find(key); // key를 갖는 원소 반환 없을시 m.end() 반환

m.at(idx); // idx key의 값 반환
m[idx] ; // 위와 동일 (위와 이것 모두 값도 변경가능)
m[idx]= 100; m.at(idx) = 100; //후자의 경우가 예외를 발생 시켜 안전하다.

m.count(key); // key를 가진 원소의 개수를 반환
m.clear(); // 모든 원소 제거
m.erase(key); //key 원소 제거
m.begin(); // 처음 iterator 반환
m.end(); // 마지막 iterator 반환

for(auto it = m.begin(); it!=m.end();i++){
	cout << it->first << " " << it->second <<'\n';
}
// 반복문 사용 예시

```
