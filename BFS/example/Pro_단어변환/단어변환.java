class Solution {
    static boolean [] vis;
    static int answer = Integer.MAX_VALUE;


    public boolean check_alpha(String words1, String words2) {
        int cnt = 0;
        for(int i=0;i<words1.length();i++){
            if(words1.charAt(i) != words2.charAt(i)) cnt++;
            if(cnt>1) return false;
        }
        return cnt == 1;
    }

    public void DFS(String now, String target, int cnt, String[] words){
        if(now.equals(target)) {
            answer = Math.min(cnt,answer);
            return;
        }

        for(int i=0;i<words.length;i++){
            if(vis[i]) continue;
            if(!check_alpha(now, words[i])) continue;
            vis[i] = true;
            DFS(words[i],target,cnt+1,words);
            vis[i] = false;
        }
    }

    public int solution(String begin, String target, String[] words) {
        vis = new boolean[words.length];
        DFS(begin, target, 0,words);
        if(answer == Integer.MAX_VALUE) answer =0;
        return answer;
    }
}
