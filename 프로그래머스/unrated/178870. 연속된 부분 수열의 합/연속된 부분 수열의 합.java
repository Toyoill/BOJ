import java.util.*;

class Solution {
    public int[] solution(int[] sequence, int k) {
        int res;
        int[] ans = {0, 1000001};

        if (sequence[0] == k) return new int[]{0, 0};
        for (int i = 1; i < sequence.length; i++) {
            if (sequence[i] == k) return new int[]{i, i};
            sequence[i] += sequence[i - 1];
        }

        res = Arrays.binarySearch(sequence, 0, sequence.length, k);
        if (0 <= res) ans[1] = res;


        for (int i = 1; i < sequence.length; i++) {
            res = Arrays.binarySearch(sequence, i, sequence.length, sequence[i - 1] + k);

            if (0 <= res && res - i < ans[1] - ans[0]) {
                ans[0] = i;
                ans[1] = res;
            }
        }

        return ans;
    }
}