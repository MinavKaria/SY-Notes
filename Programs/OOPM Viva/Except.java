import java.util.*;

class AgeException extends Exception
{
    AgeException(String exp)
    {
        super(exp);
    }
}

public class Except 
{
    static void checkAge(int age) throws AgeException
    {
        if(age<18)
        {
            throw new AgeException("Age Exception Occured");
        }
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        int age=Integer.parseInt(args[0]);

        try
        {
            checkAge(age);
        }
        catch(AgeException e)
        {
            System.out.println(e);
        }

        // System.out.println("Hello Guys");
        
        
    }
}
