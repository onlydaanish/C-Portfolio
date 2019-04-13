public class Stack 
{
 	private int dSize; 
	private int dIndex = 0;
	private int[] Array;
	
	public Stack(int Sz)
	{
		dSize = Sz;
		Array = new int[dSize];
	}
	
	public int pop()
	{
		if (dIndex>0)
		{
			 int PopVal =  Array[dIndex];  
			 dIndex--; 
			 return PopVal;
		}
		else
			return -1;
	}
	
	public void Push(int X)
	{
		if (dIndex < dSize)
		{
			
			Array[++dIndex] = X;
		}
	}
	
	public boolean isEmpty()
	{
		
		return false;
	}
	
	public int Top()
	{
		return Array[0];
	}
	
	public void Display()
	{
		if (dIndex ==0)
		{
			System.out.println("Stack is Empty");
		}
		else if (dIndex == dSize-1)
		{
			System.out.print(Array[dIndex]);
			System.out.printf("\nStack is Full");
		}
		else
		{
			System.out.print(Array[dIndex]);
		}
	}
}
