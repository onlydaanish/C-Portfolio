import java.util.Scanner;


public class Test
{
	public static boolean validateName(String FirstName)
    {
        return FirstName.matches("[A-Z][a-zA-Z]*");
    }
    
	public static void main(String[] args)
	{
	    Scanner reader = new Scanner(System.in);
	    //First Name
	    System.out.printf("Enter First Name: ");
	    String firName = reader.nextLine();
	    while (!validateName(firName))
	    {
	        System.out.printf("Not Valid Input\n");
	        System.out.printf("Enter First Name: ");
            firName =reader.nextLine();   
	    }
	    //Last Name
	    System.out.printf("Enter Last Name: ");
	    String lasName = reader.nextLine();
	    while (!validateName(lasName))
	    {
	        System.out.printf("Not Valid Input\n");
	        System.out.printf("Enter Last Name: ");
            lasName =reader.nextLine();   
	    }
	    
		Validation Emp1 = new Validation(lasName, "Bhamla", 10000);
		Emp1.GetName(); 
		System.out.printf("\nSalary: %.02f\n", Emp1.GetSalary());
		Emp1.GiveRaise();
		System.out.printf("After Raise New Salary is: %.02f\n", Emp1.GetSalary());
		
		reader.close();
	}
}

