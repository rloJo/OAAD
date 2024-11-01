## 문제 조건
> <a href = "https://www.acmicpc.net/problem/9663"> 문제 링크 </a>  
> 시간제한 : 10초  
> 메모리 제한 : 128MB  
> 정답 비율 : 46.667%

### 풀이 과정
---
1. 우선 N개의 퀸을 놓기 위해서는 한줄에 하나의 퀸만 들어갈 수 있다.
2. 따라서 isused1 배열을 선언하여 각 x,y행에 퀸이 있는지 확인한다.
3. 또한 퀸은 대각선으로 이동이 가능하기 때문에 오른쪽 대각선 왼쪽 대각선 또한 확인해야한다.
4. 오른쪽으로 올라가는(/) 형식의 대각선은 x+y의 값이 같다. 따라서 isused2[x+y]
5. 왼쪽으로 올라가는 (\) 형식의 대각선은 x-y의 값이 같다. 하지만 음수가 나오므로 해결하기 위해 N-1을 더해준다.
6. 여기서 중요한 점은 15개의 퀸이 있기 때문에 퀸은 한줄에 한개씩들어간다는 점이다.
7. 이때 cnt로 현재까지온 x의 좌표를 확인하고 i인덱스로 y좌표를 확인하면 된다. 

###  트러블 슈팅
---
1. isused 배열 크기에서 문제 발생
2. isused2, isuesd3의 인덱스에서 문제
<p>
해결 방법 : x+y의 최대는 30 -> 35 로 인덱스 변경. 인덱스를 수학적으로 생각    

</p>