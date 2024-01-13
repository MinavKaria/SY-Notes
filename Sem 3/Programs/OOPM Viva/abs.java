class Apple
{
    Apple()
    {
        System.out.println("Hello Apple");
    }
    void eat()
    {
        System.out.println("Eat it");
    }
}

class Banana extends Apple
{
    Banana()
    {
        System.out.println("Hello Banana");
    }
}

public class abs
{
    public static void main(String[] args) 
    {
       Apple ob= new Banana();
        ob.eat();
    }
}

