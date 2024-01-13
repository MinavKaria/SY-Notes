package Engineering;

import java.util.*;

public class Marks 
{
    Student s;

    public Marks(Student s) 
    {
        s = this.s;
    }

    public static void sort(Student s) 
    {
        Collections.sort(s.student_details, new sortTotal());
    }

    public static void display(Student s) 
    {
        System.out.println("\nName\t\tRoll No.\tTotal Marks\n");
        for (int i = 0; i < s.student_details.size(); i++) 
        {
            System.out.print(s.student_details.get(i).student_name + "\t\t");
            System.out.print(s.student_details.get(i).roll_no + "\t\t");
            System.out.print(s.student_details.get(i).totalMarks + "\n");
        }
    }
}

class sortTotal implements Comparator<Student> 
{
    public int compare(Student st1, Student st2) 
    {
        return st1.totalMarks - st2.totalMarks;
    }
}
