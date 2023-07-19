class Solution {
    public int solution(int[] num_list) {
        int squareSum = 0, product = 1;
        for (int num : num_list) {
            product *= num;
            squareSum += num;
        }
        if (product < squareSum * squareSum) return 1;
        else return 0;
    }
}