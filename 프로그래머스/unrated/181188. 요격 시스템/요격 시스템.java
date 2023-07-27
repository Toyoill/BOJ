import java.util.*;

class Solution {


    public int solution(int[][] targets) {
        int count = 0, minEnd = 1000000007;

        Arrays.sort(targets, (target1, target2) -> {
            if (target1[0] == target2[0]) return target1[1] - target2[1];
            return target1[0] - target2[0];
        });

        for (int[] target : targets) {
            if(minEnd <= target[0]) {
                count++;
                minEnd = target[1];
            } else{
                minEnd = Math.min(minEnd, target[1]);
            }
        }
        count++;

        return count;
    }
}