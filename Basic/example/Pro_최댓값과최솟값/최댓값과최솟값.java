import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        Set<Integer> order = new TreeSet<>();
        StringTokenizer st = new StringTokenizer(s," ");
        while (st.hasMoreTokens()) {
            order.add(Integer.parseInt(st.nextToken()));
        }
        answer = Integer.toString(((TreeSet<Integer>) order).first()) + " " + Integer.toString(((TreeSet<Integer>) order).last());
        return answer;
    }
}
