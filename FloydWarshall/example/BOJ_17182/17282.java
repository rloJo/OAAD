import java.util.Scanner;

public class Main {
    static int N,K;
    static int[][] cost;
    static boolean []vis;
    static int answer = Integer.MAX_VALUE;

    public void input(){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        cost = new int [N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cost[i][j] = sc.nextInt();
            }
        }
    }

    public void floyd(){
        for(int mid =0; mid<N; mid++){
            for(int start =0; start<N; start++){
                for(int end=0; end<N; end++){
                    if(cost[start][end] < cost[start][mid]+cost[mid][end]) continue;
                    cost[start][end] = cost[start][mid]+cost[mid][end];
                }
            }
        }
    }

    public void backtrack(int cnt, int prev, int dist){
        if(cnt == N){
            answer = Math.min(answer,dist);
            return;
        }

        for(int i=0;i<N;i++){
            if(vis[i]) continue;
            vis[i] = true;
            backtrack(cnt+1,i,dist+cost[prev][i]);
            vis[i] = false;
        }
    }


    public void solve(){
        floyd();
        vis = new boolean [N];
        vis[K] = true;
    }

    public static void main(String[] args) {
        Main obj = new Main();
        obj.input();
        obj.solve();
        obj.backtrack(1,K,0);
        System.out.println(answer);
    }
}
