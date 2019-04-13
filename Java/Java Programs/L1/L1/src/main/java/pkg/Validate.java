public class ValidateInput
{
    public static boolean validateFirstName(string FirstName)
    {
        return FirstName.matches("[A-Z][a-zA-Z]*");
    }
    
    public static boolean validateLastName(string lName)
    {
        return lName.matches("[a-zA-z]+([ '-][a-zA-Z]+)*");
    }
    
    public static boolean validateAddress(String add)
    {
        return add.matches("\\d+\\s+([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");
    }
}