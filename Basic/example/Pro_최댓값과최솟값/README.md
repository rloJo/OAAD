## 문제 조건
> <a href = "https://www.acmicpc.net/problem/14466"> 문제 링크 </a>  
> 정답 비율 : 80%

### 풀이 과정
---
1. Stringtokenizer 또는 split을 이용하여 문자열을 구분하여 숫자를 입력 받고
2. 정렬 혹은 Set을 통해 최댓값과 최솟값을 알아내어 문자열 변환 후 return 한다.다.  

### 트러블 슈팅
Java 와 C++의 Set에 차이점이 있어 혼란이 있었다.

- Java 의 set을 사용할 때 C++ STL set과 같이 사용하려면 TreeSet을 사용해야한다.
- 또한 set의 원소를 반환하는 방법이 다르다.  Java는 정답 코드와 같이 작동하지만 C++에서는 iterator로 동작해 포인터로 접근해야한다.
