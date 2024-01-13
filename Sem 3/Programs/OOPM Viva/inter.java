

class inter extends Thread
{
    public void run()
    {
        System.out.println("Hello");
    }
    public static void main(String[] args) 
    {
        inter ob=new inter();
        ob.start();
    }
    
}