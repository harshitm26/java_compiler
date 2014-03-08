class System{
		private boolean monitor;
		public void println(int s){
			int a = 3.0;				//should print error-- assigning double to int
			double b = 3.0;
			float c = 34.56f;
			float d = 100.0;			//should print error-- assigning double to float -- type narrowing conversion
			int i = 9999999999999999999;	//value too large for int 
			int ab
			int bcd;
		}
}

public class quiz{
	public int nstudents;
	public int marks;			
	public int marks;								//should print error -- already declared
}
public class test extends quiz{
	public test(int a){
		nstudents = 50;
		marks = 200;
	}
	public int average(double l, float m, double n){						
		//n=10;
		test P = new test(2);
		return nstudents/marks;
	}
}
