class Solution {
    int ans = 0;

    public int solution(int[] info, int[][] edges) {
        solve(1, 1, 0, info, edges);
        return ans;
    }

    void solve(int state, int sheep, int wolf, int[] info, int[][] edges) {
        ans = Math.max(sheep, ans);

        for (int[] edge : edges) {
            if ((state & (1 << edge[0])) != 0 && (state & (1 << edge[1])) == 0) {
                if (info[edge[1]] == 0)
                    solve(state | (1 << edge[1]), sheep + 1, wolf, info, edges);
                else if (sheep > wolf + 1)
                    solve(state | (1 << edge[1]), sheep, wolf + 1, info, edges);
            }
        }
    }
}