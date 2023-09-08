import java.util.*;

public class Subsequences {
    public static void main(String args[]) 
    {
        String a = "gfg";
        ArrayList<String> list = new ArrayList<>();

        generateSubsequences(a, 0, "", list);

        // Print all subsequences
       
            System.out.println(list);
        
    }

    public static void generateSubsequences(String original, int index, String current, ArrayList<String> list) 
    {
        if (index == original.length()) 
        {
            // When we have processed all characters in the original string, add the current subsequence to the list
            list.add(current);
            return;
        }

       
        generateSubsequences(original, index + 1, current + original.charAt(index), list);
        generateSubsequences(original, index + 1, current, list);
    }
}
