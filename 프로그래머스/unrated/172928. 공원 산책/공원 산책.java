import java.util.*;

class Solution {
    public int[] solution(String[] park, String[] routes) {
        Dog dog = new Dog(0, 0);

        outer:
        for (int i = 0; i < park.length; i++)
            for (int j = 0; j < park[0].length(); j++)
                if (park[i].charAt(j) == 'S') {
                    dog = new Dog(i, j);
                    break outer;
                }

        for (String route : routes) dog.move(route, park);
        return dog.getPos();
    }
}

class Dog {
    int r, c;

    Dog(int r, int c) {
        this.r = r;
        this.c = c;
    }

    int[] getPos() {
        return new int[]{r, c};
    }

    void move(String route, String[] park) {
        String[] op = route.split(" ");

        int nextR, nextC;
        if (op[0].equals("E")) {
            nextR = r;
            nextC = c + Integer.parseInt(op[1]);
        } else if (op[0].equals("W")) {
            nextR = r;
            nextC = c - Integer.parseInt(op[1]);
        } else if (op[0].equals("N")) {
            nextR = r - Integer.parseInt(op[1]);
            nextC = c;
        } else {
            nextR = r + Integer.parseInt(op[1]);
            nextC = c;
        }

        if (nextR < 0 || park.length <= nextR) return;
        if (nextC < 0 || park[0].length() <= nextC) return;

        if (r != nextR) {
            for (int i = Math.min(r, nextR); i <= Math.max(r, nextR); i++) if (park[i].charAt(c) == 'X') return;
        } else {
            for (int i = Math.min(c, nextC); i <= Math.max(c, nextC); i++) if (park[r].charAt(i) == 'X') return;
        }

        r = nextR;
        c = nextC;
    }
}






