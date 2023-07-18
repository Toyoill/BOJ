import java.util.*;

class Solution {
    int[][][] table = new int[1 << 17][18][18];

    public int solution(int[] info, int[][] edges) {
        return solve(1, 1, 0, info, edges);
    }

    int solve(int state, int sheep, int wolf, int[] info, int[][] edges) {
        if (table[state][sheep][wolf] > 0) return table[state][sheep][wolf];

        table[state][sheep][wolf] = sheep;

        for (int[] edge : edges) {
            if ((state & (1 << edge[0])) != 0 && (state & (1 << edge[1])) == 0) {
                if (info[edge[1]] == 0)
                    table[state][sheep][wolf] = Math.max(table[state][sheep][wolf], solve(state | (1 << edge[1]), sheep + 1, wolf, info, edges));
                else if (sheep > wolf + 1)
                    table[state][sheep][wolf] = Math.max(table[state][sheep][wolf], solve(state | (1 << edge[1]), sheep, wolf + 1, info, edges));
            }
        }

        return table[state][sheep][wolf];
    }
}