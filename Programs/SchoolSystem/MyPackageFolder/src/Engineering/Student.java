package Engineering;

import java.util.*;

public class Student 
{
    public String student_name;
    public int roll_no;
    public int[] all_marks;
    public String[] subjects;
    public int totalMarks;
    public Vector<Student> student_details=new Vector<Student>();

    public void SetNumberOfSubjects(int numSubjects)
    {
           subjects= new String[numSubjects];
           all_marks=new int[numSubjects];
    }

    public Student()
    {

    }

    public Student(String student_name, int roll_no,int[] all_marks, String[] subjects, int totalMarks)
    {
        this.student_name = student_name;
        this.roll_no = roll_no;
        this.all_marks = all_marks;
        this.subjects = subjects;
        this.totalMarks = totalMarks;
    }


    public int calculate_total(int[] all_marks)
    {
        totalMarks = 0;
        for (int i = 0; i < all_marks.length; i++) 
        {
            totalMarks += all_marks[i];
        }
        return totalMarks;
    }

    public void getDetails()
    {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the number of subjects");
        int numSubjects=sc.nextInt();

        SetNumberOfSubjects(numSubjects);

        System.out.println("Enter "+numSubjects+" names of the Subjects Below:");

        for(int i=0;i<numSubjects;i++)
        {
            subjects[i] = sc.next();
        }


    }
}
