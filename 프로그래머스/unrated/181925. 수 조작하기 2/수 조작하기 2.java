class Solution {
     public String solution(int[] numLog) {
        char[] ansArr = new char[numLog.length - 1];

        for (int i = 0; i < numLog.length - 1; i++) {
            if (numLog[i + 1] - numLog[i] == 1) {
                ansArr[i] = 'w';
            } else if (numLog[i + 1] - numLog[i] == -1) {
                ansArr[i] = 's';
            } else if (numLog[i + 1] - numLog[i] == 10) {
                ansArr[i] = 'd';
            } else {
                ansArr[i] = 'a';
            }
        }
        return new String(ansArr);
    }
}