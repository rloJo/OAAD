# 이분탐색 (Binary Search)
- <span>${\textsf{\color{red}정렬된}}$</span> 리스트에서 원하는 값의 존재 여부를 찾는 알고리즘.
- 탐색시 검사 범위가 절반으로 줄어든다.
- 재귀적인 방법, 반복문, STL을 이용하여 이분 탐색을 실행한다.
- O(logN) 시간 복잡도

## 알고리즘 흐름
---
1. 찾고 싶은 인덱스의 시작점과 끝점을 각각 lcur, rcur로 선언.
```c++
  vector<int> FindHere;
  int lcur = 0; // 찾고 싶은 범위의 시작점
  int rcur = FindHere.end(); // 범위의 끝점
```
2. 중앙값인 mid를 선언 후 초기값 할당
```c++
  int mid = (lcur+rcur)/2; // 초기값은 중앙 값
```
3. 찾고자 하는 값이 FindHere[mid] 이면 return mid
4. 찾고자 하는 값이 FindHere[mid] 값보다 크면 lcur = mid+1
5. 만약 찾고자 하는 값이 FindHere[mid] 값보다 작으면 rcur = mid-1
6. 위 단계를 반복한다. (lcur이 rcur보다 작거나 같을때 까지)
```c++
// 반복문
  while(lcur <= rcur){ // 반복 범위
    mid = (lcur+rcur)/2 // 2 번단계
    if(FindHere[mid] == target) return mid; // 3 번 단계
    if(FindHere[mid] < target) lcur = mid+1; // 4 번 단계
    else rcur = mid -1; // 5 번 단계
  }

// 재귀
  int binarySearch(int lcur, int rcur, int target){
    if(lcur > rcur) return -1; // 범위 설정
    int mid= (lcur+rcur)/2;  // 2 번 단계
    if(FindHere[mid] == target) return mid; // 3 번 단계
    if(FindHere[mid] < target) binarySearch(mid+1,rcur,target); // 4 번 단계
    else binarySearch(lcur,mid-1,target); // 5 번 단계
  }
// STL
#include<algorithm>
bool hasTarget = binary_search(FindHere.begin(),FindHere.end(),target); // 인덱스 리턴이 아님에 주의
```
