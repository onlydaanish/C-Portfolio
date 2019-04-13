public class Validation
{
    private double Salary;
    private String fName, lName;
    
    public Validation(String FirstName, String LastName, double StartSalary)
    {
        fName = FirstName;
        lName = LastName;
        Salary = StartSalary;
    }
    
    void GetName()
    {
        System.out.printf("Name: %s %s \n", fName, lName);
    }
    
    double GetSalary()
    {
        return Salary;
    }
    
    void GiveRaise()
    {
    	Salary = Salary + (Salary * 0.1) * 12;
    }
    
    void SetName(String First, String Last)
    {
        fName = First;
        lName = Last;
        System.out.printf("Name is now %s %s\n",fName,lName);
    }
    
  
}