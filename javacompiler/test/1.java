class System{
		class out{
			private boolean monitor;
			public void println(int s){
				int a = 3.0;				//should print error
				double b = 3.0;
				float c = 34.56f;
			}
		}
}

public class quiz{
	public int nstudents;
	public int marks;			
	public int marks;								//should print error
}
public class test extends quiz{
	public test(int a){
		nstudents = 50;
		marks = 200;
	}
	public int average(double l, float m, double n){						
		//n=10;
		class put extends System.out{
			public int putchar(){
				return 1.3;									//should print error
			}
		}
		test P = new test(2);
		put.println(5);
		put.println(l);										//should print error
		return nstudents/marks;
	}
}
