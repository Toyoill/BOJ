class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0, painted = 0;
        for (int i = 0; i < section.length && painted < n; i++) {
            if (painted < section[i]) {
                answer++;
                painted = section[i] + m - 1;
            }
        }

        return answer;
    }
}