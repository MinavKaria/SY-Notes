import java.util.*;

public class LCSD {
    public static String longestCommonSubstring(String s1, String s2){
        return LCS(s1, s2, 0, s1.length() - 1, s2.length());
    }
    public static String LCS(String s1, String s2, int start, int end, int m){
        if (end - start + 1 <= 4) {
            return lcs(s1.substring(start, end + 1), s2);
        }
        int mid = (start + end) / 2;
        String leftLCS = LCS(s1, s2, start, mid, m);
        String rightLCS = LCS(s1, s2, mid + 1, end, m);
        return leftLCS + rightLCS;
    }
    public static String lcs(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        Queue<Integer> Q = new LinkedList<>();
        int matNum = 0;
        for (int i = 0; i <= n; i++) {
            Queue<Integer> cRow = new LinkedList<>();
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    cRow.offer(0);
                } else {
                    if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                        int diag = Q.poll();
                        int pVal = diag + 1;
                        cRow.offer(pVal);
                        if (pVal > matNum) {
                            matNum = pVal;
                        }
                    } else {
                        int diag = Q.poll();
                        int vertVal = cRow.peek();
                        int pVal = Math.max(diag, vertVal);
                        cRow.offer(pVal);
                    }
                }
            }
            Q = cRow;
        }
        return String.valueOf(matNum);
    }

    public static void main(String[] args){
        String s1 = "helloIam";
        String s2 = "helloI";
        String lcs = longestCommonSubstring(s1, s2);
        System.out.println("Longest Common Substring: " + lcs);
    }
}