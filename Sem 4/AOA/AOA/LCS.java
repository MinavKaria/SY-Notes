import java.util.*;

public class LCS {
    public static int lcs(String s1, String s2) {
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
        return matNum;
    }

    public static void main(String[] args) {
        long avgtime = 0;

        String s1 = "helloiam";
        String s2 = "hello";
        long startTime = System.nanoTime();
        @SuppressWarnings("unused")
        int lcsLength = lcs(s1, s2);
        long stopTime = System.nanoTime();
        System.out.println(lcsLength);
        // avgtime += (stopTime - startTime);
        float avgF = avgtime;
        System.out.println(avgF / 100000000);
    }
}
