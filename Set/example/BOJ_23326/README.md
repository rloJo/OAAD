## 문제 조건
> <a href = "https://www.acmicpc.net/problem/23326"> 문제 링크 </a>  
> 시간제한 : 21초  
> 메모리 제한 : 1024MB  
> 정답 비율 : 29.431%

### 풀이 과정
---
1. 입력을 받고 명소인경우 set에 추가
2. 1번 명령을 받았을 때 set에 값이 있으면 erase 없으면 insert
3. x만큼 시계방향으로 이동시키는 것은 현재 위치에서 x 만큼 더한 후, N으로 나머지 연산을 해주면 된다. 0~N-1로 입력을 받았기 때문.
4. set에서 dh 이상인 값이 처음 나오는 pos를 반환 받는다. 없으면 시작점. set이 비었으면 -1 출력

### 트러블 슈팅
---
set을 순차 탐색하여 풀었더니 시간 초과 (TLE)  
-> set에 포함되어 있는 lower_bound 메소드를 사용했다.  
-> set의 lower_bound도 algorithm의 lower_bound와 같이, 이분 탐색으로 원소를 탐색한다.  
-> algorithm의 lower_bound는 set처럼 random access가 안 되는 iterator에 대해 $O(N)$의 시간복잡도를 갖지만 set의 lower_bound는 $O(logN)$  

