package Engineering; 

import java.util.*; 
public class Student {   
  public String student_name;   
  public int roll_no;   
  public int[] all_marks = new int[5];   
  public String[] subjects = new String[5];   
  public int totalMarks; 
  public Vector<Student> student_details = new Vector<Student>();   
  public Student () { 

  } 
  public Student(String student_name, int roll_no, int[] all_marks, String[] subjects, int totalMarks) 
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
    Scanner sc = new Scanner(System.in); 
    System.out.print("Enter the number of subjects: ");     
    int numSubjects = sc.nextInt();     
    for (int i = 0; i < numSubjects; i++) 
    {
      subjects[i] = sc.next(); 
    } 
    System.out.print("\nEnter the number of students: ");     
    int numStudents = sc.nextInt();     
    for (int i = 0; i < numStudents; i++) 
    { 
      System.out.println("\nStudent " + (i + 1) + " Details:");       
      System.out.print("Name: ");       
      student_name = sc.next();       
      System.out.print("Roll No: ");       
      roll_no = sc.nextInt(); 
      System.out.print("Marks in each subject:\n");       
      for (int j = 0; j < numSubjects; j++) 
      { 
        System.out.print("Enter marks in " + subjects[j] + " :");         
        all_marks[j] = sc.nextInt(); 
      } 
      totalMarks = calculate_total(all_marks);
      student_details.addElement(new Student(student_name, roll_no, all_marks, subjects, totalMarks)); 
} 
     sc.close(); 
  } 
} 
