import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] ans = new int[photo.length];
        HashMap<String, Integer> nameMap = new HashMap<String, Integer>();
        for (int i = 0; i < name.length; i++) nameMap.put(name[i], i);

        int idx;
        for (int i = 0; i < photo.length; i++)
            for (String p : photo[i])
                if (nameMap.get(p) != null)
                    ans[i] += yearning[nameMap.get(p)];
        return ans;
    }
}