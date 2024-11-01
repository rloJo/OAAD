# 백트래킹 (Back Tracking)
- 현재 상태에서 가능한 모든 후보군을 따라 들어가면서 탐색하는 알고리즘.
- 해를 찾는 도중 해가 절대 될 수 없다고 판단되면, 되돌아가서 해를 다시 찾아간다.
- 시간복잡도 : O($$2^N$$)

## 알고리즘 흐름
---
(조합을 찾는 백트래킹 가정)
1. 조합에 들어갈 수 있는 숫자가 이미 뽑힌숫자인지 판별하는 vis배열설정
2. for문을 돌며 이미 뽑힌 수면 넘어가고 안뽑힌 수이면 해당 수를 정답에 넣고 재귀호출
3. 2번 과정을 뽑아야하는 수까지 반복
```c++
void backtracking(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        answer.push_back(i);
        backtracking(answer, cnt+1);
        vis[i] = false;
        answer.pop_back();
    }
}

```  

