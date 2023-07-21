import java.util.*;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        int[] minPush = new int[26], ans = new int[targets.length];
        Arrays.fill(minPush, 10000);

        for (String keys : keymap)
            for (int i = 0; i < keys.length(); i++)
                minPush[keys.charAt(i) - 'A'] = Math.min(minPush[keys.charAt(i) - 'A'], i + 1);

        for (int i = 0; i < targets.length; i++)
            for (char c : targets[i].toCharArray()) {
                if (minPush[c - 'A'] == 10000) {
                    ans[i] = -1;
                    break;
                }
                ans[i] += minPush[c - 'A'];
            }
        
        return ans;
    }
}