import java.util.*;

public class Luhn
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        long number;
        System.out.println("Enter the Credit Card number");
        number=sc.nextLong();
       
        long copy1=number;
        long copy2=number;
        int count=0;
        int correct=1;
        while(copy1!=0)
        {
            copy1=copy1/10;
            count++;
        }
        if(count!=16)
        {
            System.out.println("Enter a valid number");
        }
        else
        {
            System.out.println("The Entered number is "+number);
            int count1=16;

           outer: while(count1!=0)
            {
                if(count1%2==0)
                {
                    copy2=copy2/10;
                    count1--;
                    
                }
                else
                {
                    long add=0;
                    long num=(copy2%10)*2;
                    long num2=num;
                    if(num!=0)
                    {
                         add=(num2%10+num2/10);
                    }

                    
                    if(add==(num2-9) || add==num2 || add==0)
                    {
                        count1--;
                        copy2=copy2/10;
                    }
                    else
                    {
                        correct=0;
                        break outer;
                    }
                    
                }
            }
            if(correct==0)
            {
                System.out.println("Invalid number");
            }
            else
            {
                System.out.println("Valid Number");
            }


            


        }

    }
}