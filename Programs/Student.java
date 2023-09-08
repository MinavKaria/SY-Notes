import java.util.*;

class School
{
    int id;
    String name;
    int marks;

    School(int id,String name,int marks)
    {
        this.id=id;
        this.name=name;
        this.marks=marks;
    }


}

public class Student
{
   public static void main(String[] args) 
   {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a choice");
        System.out.println("1. Store a value of Student");
        System.out.println("2. Delete a student from the list");
        System.out.println("3. Print the value of the Students");
        System.out.println("4. Exit");
        int choice=sc.nextInt();


        switch(choice)
        {
            case 1:
            {
                
                break;
            }
        }

   }

}