abstract class Animal
{
    
    Animal()
    {
        System.out.println("Animal is created");
        
    }
    abstract void sound();
}
class Dog extends Animal
{
    void sound()
    {
        System.out.println("Dog barks");
    }
}
class Cat extends Animal
{
    void sound()
    {
        System.out.println("Cat meows");
    }
}
public class ridding 
{
 public static void main(String[] args) 
 {
    Animal a=new Dog();
    a.sound();
    a=new Cat();
    a.sound();
    

 }
}