public class test3	{
	public void main()	{
		double a=14,b=10.10;			//double not supported
		double z=6;
		double k=(a/z);
		int s=1.1;						//should print error--assigning double value to int
		double s1=1;
		double s2=z+a;
		boolean check = true;
		boolean ch = 0;					//boolean is either true/false only
		int wow = 0;
		while(a > 10.0)	{
			a--;
			z++;
		}
		int g;
		if(check)	{
			g=15;
		}else{
			g=10;
		}
		if (wow){							//should print error--wow is not boolean type
			int kac=34;						
		}else{
			int x = 12;
		}
	}
	 
	public int func(int a)	{
		int b;
		b = a * a * a;
		return b;
	}
}
