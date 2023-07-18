class Solution {
    public String solution(String code) {
        boolean flag = false;
        String answer = "";

        for (int i = 0; i < code.length(); i++) {
            if (code.charAt(i) == '1') {
                flag = !flag;
            } else if (!flag && i % 2 == 0) answer += code.charAt(i);
            else if (flag && i % 2 == 1) answer += code.charAt(i);
        }

        return answer.length() == 0 ? "EMPTY" : answer;
    }
}