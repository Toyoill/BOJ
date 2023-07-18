class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        String answer;
        char[] strArr = my_string.toCharArray();

        for (int i = 0; i < overwrite_string.length(); i++) {
            strArr[s + i] = overwrite_string.charAt(i);
        }

        answer = String.copyValueOf(strArr);

        return answer;
    }
}