
public class Test 
{
	public static void main(String[] args)
	{
		Stack X = new Stack(6);
		//EMPTY DISPLAY
		X.Display();
		
		System.out.print("\nAfter Push: \n");
		for (int i=1; i<=5; i++)
		{
			X.Push(i);
			X.Display();
			System.out.print("\t");
		}
		
		System.out.print("\n\n");
		System.out.print("Pop Values: \n");
		
		for (int i=0; i<5; i++)
		{
			int PopVal = X.pop();
			if(PopVal != -1 )
			{
				System.out.print(PopVal);
				System.out.printf("\t");
			}
			else
			{
				System.out.println("Stack is Empty!");
			}
		}
	}
}
