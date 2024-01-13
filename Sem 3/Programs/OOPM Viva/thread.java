class MyThread extends Thread 
{
 public MyThread(String name) 
 {
 super(name);
 }
 public void run() 
 {
    for (int i = 1; i <= 5; i++) 
    {
        System.out.println(Thread.currentThread().getName() + ": " + i);
    try 
    {
        Thread.sleep(500);
    } 
    catch (InterruptedException e) 
    {
        e.printStackTrace();
    }
    }
    }
}
public class thread 
{
 public static void main(String[] args) 
 {
 MyThread thread1 = new MyThread("Thread 1");
 MyThread thread2 = new MyThread("Thread 2");
 thread1.setPriority(Thread.MIN_PRIORITY);
 thread2.setPriority(Thread.MAX_PRIORITY);
 System.out.println("Thread 1 Priority: " + thread1.getPriority());
 System.out.println("Thread 2 Priority: " + thread2.getPriority());
 thread1.start();
 thread2.start();
//  thread1.
//  System.out.println("Suspending Thread 1...");
// //  thread1.suspend();
 try 
 {
 Thread.sleep(2000);
 } 
 catch (InterruptedException e) 
 {
    e.printStackTrace();
 }
    System.out.println("Resuming Thread 1...");
//  thread1.resume();
 try 
 {
    thread1.join();
 } 
 catch (InterruptedException e) 
 {
    e.printStackTrace();
 }
 System.out.println("Thread 1 State: " + thread1.getState());
 System.out.println("Thread 2 State: " + thread2.getState());
 }
}