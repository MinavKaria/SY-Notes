class Exception2Demo
{
   public static void main(String [] args)
 {
     try{
   method1();}

catch(ArithmeticException ae)
{
   System.out.println("Arithmetic Exception Handled:" +ae);
}
catch(Exception e)
{
   System.out.println("Exception handled");
}
  }
static void method1()
{
   System.out.println("In method 1, calling method 2");
   method2();
   System.out.println("Returned from method 2");
 }
static void method2()
{
   System.out.println("In method 2, calling method 3");
    method3();
}

static void method3()
{
   System.out.println("In method 3");
   int a = 10, b = 0;
   int c = a/b;
   System.out.println("Method 3 exits");
  }
}