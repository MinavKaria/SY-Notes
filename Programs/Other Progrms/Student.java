import java.util.Scanner;

class Student 
{
    int stud_id;
    String name;
    double avg_marks;

    public Student(int stud_id, String name, double avg_marks) 
    {
        this.stud_id = stud_id;
        this.name = name;
        this.avg_marks = avg_marks;
    }
}

public class StudentManagementSystem 
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Student[] students = new Student[10]; // Assuming a maximum of 10 students
        int studentCount = 0;

        while (true) {
            System.out.println("Enter a choice");
            System.out.println("1. Add Student (Descending Order of Average Marks)");
            System.out.println("2. Delete Student by Student ID");
            System.out.println("3. Display Students (Descending Order of Average Marks)");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    if (studentCount < students.length) 
                    {
                        System.out.print("Enter Student ID: ");
                        int stud_id = sc.nextInt();
                        sc.nextLine(); // Consume newline
                        System.out.print("Enter Student Name: ");
                        String name = sc.nextLine();
                        System.out.print("Enter Average Marks: ");
                        double avg_marks = sc.nextDouble();

                        Student newStudent = new Student(stud_id, name, avg_marks);
                        int insertIndex = 0;
                        boolean inserted = false;

                        // Find the correct index to insert the student in descending order of average marks
                        for (int i = 0; i < studentCount; i++) 
                        {
                            if (avg_marks > students[i].avg_marks) 
                            {
                                insertIndex = i;
                                inserted = true;
                                break;
                            }
                            insertIndex = i + 1;
                        }

                        // Shift existing students to make space for the new student
                        for (int i = studentCount; i > insertIndex; i--) 
                        {
                            students[i] = students[i - 1];
                        }

                        students[insertIndex] = newStudent;
                        studentCount++;
                        
                        if (inserted) 
                        {
                            System.out.println("Student added successfully.");
                        } 
                        else 
                        {
                            System.out.println("Student added at the end.");
                        }
                    } else {
                        System.out.println("Maximum student limit reached.");
                    }
                    break;

                case 2:
                    System.out.print("Enter Student ID to delete: ");
                    int idToDelete = sc.nextInt();
                    boolean studentFound = false;

                    for (int i = 0; i < studentCount; i++) 
                    {
                        if (students[i].stud_id == idToDelete) 
                        {
                            // Shift remaining students to fill the gap
                            for (int j = i; j < studentCount - 1; j++) 
                            {
                                students[j] = students[j + 1];
                            }
                            studentCount--;
                            studentFound = true;
                            System.out.println("Student with ID " + idToDelete + " deleted.");
                            break;
                        }
                    }

                    if (!studentFound) {
                        System.out.println("Student with ID " + idToDelete + " not found.");
                    }
                    break;

                case 3:
                    System.out.println("Student Details (Descending Order of Average Marks):");
                    for (int i = 0; i < studentCount; i++) {
                        System.out.println("Student ID: " + students[i].stud_id);
                        System.out.println("Name: " + students[i].name);
                        System.out.println("Average Marks: " + students[i].avg_marks);
                        System.out.println();
                    }
                    break;

                case 4:
                    System.out.println("Exiting the program.");
                    sc.close();
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}
