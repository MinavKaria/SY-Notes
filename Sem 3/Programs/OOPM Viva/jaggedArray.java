import java.util.*;

public class jaggedArray 
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.err.println("Enter the number of rows");
        int rows=sc.nextInt();

        int[][] arr=new int[rows][];
        for(int i=0;i<arr.length;i++)
        {
            System.out.println("Enter the number of columns in "+(i+1));
            int col=sc.nextInt();
            arr[i]=new int[col];

            for(int j=0;j<col;j++)
            {
                System.out.print("Enter Number: ");
                arr[i][j]=sc.nextInt();
            }
        }

        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[i].length;j++)
                System.out.print(arr[i][j]+" ");
            System.out.println();
        }


        
    }
    
}