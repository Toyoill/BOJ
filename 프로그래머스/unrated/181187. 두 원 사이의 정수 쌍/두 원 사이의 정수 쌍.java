import java.util.*;

class Solution {
    public long solution(int r1, int r2) {
        long answer = (r2 - r1 + 1L) * 4L, h;

        h = r2 - 1L;

        while (h > 0) {
            long l = 0, r = r2 + 1, mid, target = r2;
            while (l + 1L < r) {
                mid = (l + r) / 2L;

                if (h * h + mid * mid <= target * target) l = mid;
                else r = mid;
            }
            answer += l * 4;
            h--;
        }
        
        h = r1 - 1;
        while (h > 0) {
            long l = 0, r = r1 + 1, mid, target = r1;
            while (l + 1L < r) {
                mid = (l + r) / 2L;

                if (h * h + mid * mid < target * target) l = mid;
                else r = mid;
            }
            answer -= l * 4;
            h--;
        }

        return answer;
    }
}