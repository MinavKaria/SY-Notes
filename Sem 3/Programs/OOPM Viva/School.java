
public class Student 
{
    String name;
    int id;
    int JavaMarks;
    int DSAmarks;
    int DBMSmarks;
    int totalMarks;

    Student(String name,int id, int JavaMarks, int DSAmarks, int DBMSmarks)
    {
        this.name=name;
        this.id=id;
        this.JavaMarks=JavaMarks;
        this.DSAmarks=DSAmarks;
        this.DBMSmarks=DBMSmarks;
        totalMarks=JavaMarks+DSAmarks+DBMSmarks;
    }
}

public class School
{
    public static void main(String[] args) 
    {
        System.out.println("Hello");
    }
}

