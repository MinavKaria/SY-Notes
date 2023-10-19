import Engineering.Marks;
import Engineering.Student;

public class Main 
{
    public static void main(String args[]) {
        Student s = new Student();
        s.getDetails();
        Marks.sort(s);
        Marks.display(s);
    }
}
