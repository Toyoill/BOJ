class Solution {
    public int solution(int n) {
        if (n % 2 == 1) return (n + 1) / 2 * (n + 1) / 2;

        int sum = 0;
        for (int i = 1; (i << 1) <= n; i++) sum += ((i * i) << 2);
        return sum;
    }
}