import java.util.*;

class Solution {
    public int solution(int m, int n, int[][] puddles) {
        final int MOD = 1000000007;
        int answer = 0;
        int [][] dp = new int [n+1][m+1];
        for(int i=0;i<puddles.length;i++){
            dp[puddles[i][1]][puddles[i][0]] = -1;
        }
        dp[1][1] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1&&j==1 || dp[i][j] == -1) continue;
                int fromTop = dp[i-1][j] < 0 ? 0 : dp[i-1][j] ;
                int fromLeft = dp[i][j-1] < 0 ? 0 : dp[i][j-1];
                dp[i][j] = (fromTop+fromLeft) % MOD;
            }
        }

        answer = dp[n][m];
        return answer;
    }
}
