import java.util.Scanner;

public class Main {
    static int [][] B = new int [602][602];
    static int H,W,X,Y;

    public void input(){
        Scanner sc = new Scanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        X = sc.nextInt();
        Y = sc.nextInt();

        for(int i = 0 ; i < H+X ; i++){
            for(int j = 0 ; j < W+Y ; j++){
                B[i][j] = sc.nextInt();
            }
        }
    }

    public void solve(){
        for(int i = X ; i < H ; i++){
            for(int j = Y ; j < W ; j++){
                B[i][j] -= B[i-X][j-Y];
            }
        }

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                System.out.print(B[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Main m = new Main();
        m.input();
        m.solve();
    }
}
