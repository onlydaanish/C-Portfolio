public class HelloWorld 
{
	public static void main(String[] args)
	{
		System.out.printf("Welcome! i Will do the Factorial(x!) of Numbers 1-20!\n");
		System.out.printf("Number\t\tFactorial\n");
		for (long i=1;i<=20;i++)
		{
			System.out.printf("%d\t\t", i);
			if (i > 1)
			{
			    long Res = i;
			    for (long z=i; z>1;z--)
			    {
					Res *= z-1;
				}
				System.out.printf("%d\n",Res);
			}
			else
			{
				System.out.printf("1\n");
			}
		}
	}
}

