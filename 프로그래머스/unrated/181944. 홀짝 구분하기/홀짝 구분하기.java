import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        System.out.printf("%d is ", n);
        if(n % 2 == 1) System.out.print("odd");
        else System.out.print("even");
    }
}