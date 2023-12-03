import java.util.*;

class Students
{
    String name;
    int id;
    Vector<Integer> attendance=new Vector<>();
    int totalAttendance;

    Students(String name, int id, Vector<Integer> attendance)
    {
        this.name=name;
        this.id=id;
        this.attendance=attendance;

        for(int i:attendance)
        {
            totalAttendance+=i;
        }

        totalAttendance=totalAttendance/6;
    }
}

class Departments
{
    String name;
    int numberOfStudents;
    Vector<Students> students=new Vector<>();
    
    Departments(String name, int numberOfStudents)
    {
        this.name=name;
        this.numberOfStudents=numberOfStudents;
    }

    void addStudent(Students ob)
    {
        students.add(ob);
    }
}

public class CollegeAttendance 
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter the Number of Departments: ");
        int dep=sc.nextInt();

        Departments departments[]=new Departments[dep];
        
        for(int i=0;i<dep;i++)
        {
            System.out.println("Enter the name of "+(i+1)+" Branch");
            String name=sc.next();
            System.out.println("Enter the number of Students for this branch");
            int numberOfStudents=sc.nextInt();

            Departments ob=new Departments(name, numberOfStudents);
            departments[i]=ob;
        }
        int choice=0;
        while(choice!=3)
        {
            System.out.println("1. Enter the Student Details for Particular Branch");
            System.out.println("2. Display All the Branchs");
            System.out.println("3. Exit");  
            choice=sc.nextInt();

            switch (choice) 
            {
                case 1:
                {
                    int n=0;
                    System.out.println("Branchs");
                    for(Departments i:departments)
                    {
                        System.out.println((n+1)+". "+i.name);
                        n++;
                    }
                    System.out.println("Enter the branch to be Selected");
                    String branch=sc.next();

                    int j=0;

                    for(Departments i:departments)
                    {
                        if(i.name.equals(branch))
                        {
                            break;
                        }
                        j++;
                    }

                    if(j==departments.length)
                    {
                        System.out.println("Department Not Found");
                    }
                    else
                    {
                        int choice1=0;
                        while(choice1!=4)
                        {
                            System.out.println("1. Enter the Student Details");
                            System.out.println("2. Display the Student Details");
                            System.out.println("3. Print All the Eligible Student");
                            System.out.println("4. Exit");
                            choice1=sc.nextInt();

                            switch (choice1) 
                            {
                                case 1:
                                {
                                    if(departments[j].numberOfStudents>departments[j].students.size())
                                    {
                                        Vector<Integer> attendance=new Vector<>();

                                        System.out.println("Enter the name of the Student");
                                        String name=sc.next();
                                        System.out.println("Enter the id");
                                        int id=sc.nextInt();
                                        System.out.println("Enter the Attendance of 6 Months in Percentage");
                                        for(int i=0;i<6;i++)
                                        {
                                            int num=sc.nextInt();
                                            attendance.add(num);
                                        }


                                        Students ob=new Students(name, id, attendance);

                                        departments[j].students.add(ob);
                                    }
                                    else
                                    {
                                        System.out.println("Number of Students Exceeded");
                                    }
                                    break;

                                }
                                
                                case 2:
                                {
                                    Departments temp=departments[j];
                                    Vector<Students> vec=temp.students;
                                    if(vec.size()!=0)
                                    {
                                        System.out.println("Name     ID     Attendance");
                                    }
                                    
                                    else
                                    {
                                        System.out.println("No Student Entered");
                                    }
                                    for(Students i:vec)
                                    {
                                        System.out.println(i.name+"     "+i.id+"     "+i.totalAttendance);
                                    }

                                    break;
                                }

                                case 3:
                                {
                                    Departments temp=departments[j];
                                    Vector<Students> vec=temp.students;
                                    System.out.println("Eligible Students");
                                    for(Students i:vec)
                                    {
                                        if(i.totalAttendance>=75)
                                        System.out.println(i.name+"     "+i.id+"     "+i.totalAttendance);
                                    }

                                    break;
                                }

                            
                                default:
                                {
                                    System.out.println("Thank you, Please Try Again");
                                }
                                    break;
                            }
                        }
                }

                }

                case 2:
                {
                    int j=0;
                    System.out.println("Branches: ");
                    for(Departments ob:departments)
                    {
                        System.out.println(j+1+" "+ob.name);
                        j++;
                    }
                }
                
            
                default:
                    break;
            }
        }
        

    }
}
