import java.time.*;

class Solution {
    public int[] solution(String[] wallpaper) {
        int lux = 55, luy = 55, rdx = -1, rdy = -1;

        for (int i = 0; i < wallpaper.length; i++) {
            for (int j = 0; j < wallpaper[i].length(); j++) {
                if (wallpaper[i].charAt(j) == '#') {
                    lux = Math.min(lux, i);
                    luy = Math.min(luy, j);
                    rdx = Math.max(rdx, i + 1);
                    rdy = Math.max(rdy, j + 1);
                }
            }
        }
        return new int[]{lux, luy, rdx, rdy};
    }
}

