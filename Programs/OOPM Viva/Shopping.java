import java.util.*;

class Items 
{
    String name;
    int price;
    int quantity;

    Items(String name, int price, int quantity)
    {
        this.name=name;
        this.price=price;
        this.quantity=quantity;
    }

    public String getName() 
    {
        return name;
    }

    public int getPrice() 
    {
        return price;
    }

    public int getQuantity() 
    {
        return quantity;
    }

}

public class Shopping 
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        Vector<Items> list= new Vector<>();
        int choice=0;
        while(choice!=4)
        {
            System.out.println("1. Add a Product");
            System.out.println("2. Remove a Product ");
            System.out.println("3. Display All the products");
            System.out.println("4. Exit");
            choice=sc.nextInt();

            switch (choice) 
            {
                case 1:
                {
                    System.out.println("Enter the Name of the Product");
                    String name=sc.next();
                    sc.nextLine();
                    System.out.println("Enter the price of the product");
                    int price=sc.nextInt();
                    System.err.println("Enter the quantity of the same");
                    int quantity=sc.nextInt();

                    Items ob=new Items(name, price, quantity);

                    list.add(ob);

                    break;
                }
                case 2:
                {
                    System.out.println("Enter the name of the product to be removed");
                    String name=sc.next();
                    sc.nextLine();

                    int j=0;
                    for(Items i: list)
                    {
                        if(i.getName().equals(name))
                        {
                            break;
                        }
                        j++;
                    }

                    if(j==list.size())
                    {
                        System.out.println("Product Not Found");
                    }
                    else
                    {
                        list.removeElementAt(j);
                    }
                    break;
                }

                case 3:
                {   
                    int j=0;
                    Collections.sort(list, new Comparator<Items>() 
                    {
                        @Override
                        public int compare(Items item1, Items item2)
                        {
                            return Integer.compare(item1.getPrice(), item2.getPrice());
                        }
                    });
                    for(Items i: list)
                    {
                        System.out.println("Product No. "+(j+1));
                        System.out.println("Product: "+i.getName());
                        System.out.println("Price: "+i.getPrice());
                        System.out.println("Quantity: "+i.getQuantity());
                        j++;
                    }

                    break;
                }

            
                default:
                    break;
            }
        }
    }
    
}