import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        int[] rank = new int[players.length], running = new int[players.length];
        HashMap<String, Integer> nameMap = new HashMap<String, Integer>();
        String[] answer = new String[players.length];

        for (int i = 0; i < players.length; i++) {
            nameMap.put(players[i], i);
            rank[i] = i;
            running[i] = i;
        }

        int tmp;
        for (String call : callings) {
            int nameVal = nameMap.get(call);
            int r = rank[nameVal]--;
            rank[running[r - 1]]++;

            running[r] = running[r - 1];
            running[r - 1] = nameVal;
        }

        for (int i = 0; i < running.length; i++)
            answer[i] = players[running[i]];

        return answer;
    }
}