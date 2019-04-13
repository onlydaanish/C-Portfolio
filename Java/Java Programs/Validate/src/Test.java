import java.io.*;


public class Test
	{
		public static boolean validateFirstName(String FirstName)
	    {
	        return FirstName.matches("[A-Z][a-zA-Z]*");
	    }

	    public static boolean validateLastName(String lName)
	    {
	        return lName.matches("[a-zA-z]+([ '-][a-zA-Z]+)*");
	    }

	    public static boolean validateAddress(String add)
	    {
	        return add.matches("\\d+\\s+([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");
	    }
	    
		public static void main(String[] args)
		{
		    Console console = System.console();
		    String firName = console.readLine("Enter First Name: ");
		    while (!validateFirstName(firName))
		    {
		        System.out.printf("Not Valid Input\n");
                firName = console.readLine("Enter Name: ");   
		    }
		    
		    
			Employee Emp1 = new Employee(firName, "Bhamla", 10000);
			Emp1.GetName(); 
			System.out.printf("Salary: %.02f\n", Emp1.GetSalary());
			Emp1.GiveRaise();
			System.out.printf("After Raise New Salary is: %.02f\n", Emp1.GetSalary());
		}
	}

