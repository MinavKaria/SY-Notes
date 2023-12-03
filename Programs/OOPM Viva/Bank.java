import java.util.*;


class BankSystem {

    private int accountNumber;
    private String accountHolderName;
    double AccountBalance;
    
    BankSystem(int accountNumber,String accountHolderName, double AccountBalance)
    {
        this.accountNumber=accountNumber;
        this.accountHolderName=accountHolderName;
        this.AccountBalance=AccountBalance;

    }

    void deposit(double credit)
    {
        AccountBalance+=credit;

        System.out.println("The Final Balance is INR "+AccountBalance);
    }

    void withdraw(double debit)
    {
        AccountBalance-=debit;

        System.out.println("The Final Balance is INR "+AccountBalance);
    }

    void display()
    {
        System.out.println("The Account Balance is: "+AccountBalance);
    }
    
}


public class Bank 
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the Account Number: \n");
        int accNo=sc.nextInt();
        System.out.println("Enter the Name of the Account Number\n");
        String name=sc.nextLine();
        sc.nextLine();
        System.out.println("Enter the Balance of the Account");
        double bal=sc.nextDouble();
        System.out.println("\n\n");

        BankSystem holder=new BankSystem(accNo, name, bal);
        int choice=0;

        while(choice!=4)
        {
            System.out.println("Enter a choice\n");
            System.out.println("1. Deposit\n");
            System.out.println("2. Withdraw\n");
            System.out.println("3. Display Balance\n");
            System.out.println("4. Exit \n");
            choice=sc.nextInt();

            switch (choice) 
            {
                case 1:
                {
                    System.out.println("Enter the Amount to be deposited");
                    int num=sc.nextInt();

                    holder.deposit(num);
                    break;
                }  

                case 2:
                {
                    System.out.println("Enter the Amount to be withdrawn");
                    int num=sc.nextInt();

                    if(num>holder.AccountBalance)
                    {
                        System.out.println("Insufficient Balance, Try Again!");
                    }
                    else
                    {
                        holder.withdraw(num);
                    }
                    break;
                }


                case 3:
                {
                    holder.display();

                    break;
                }

                case 4:
                {
                    System.out.println("Exited........ ");
                    break;
                }


                default:
                {
                    System.out.println("Try Again\n");
                    break;
                }
                    
            }


         }




    }
}
