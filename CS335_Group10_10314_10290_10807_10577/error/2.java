public class abc {
	public double sq (double i, int j) {
		int[] a = new int[3];
		a = 3;					//should print error-- a has type array	
		return i * i;
	}

	public int add () {
		double test;
		test = sq (test,3);
		test = sq (3,3.3);				//should print error--passing double to int j in function
		test = sq (3,890);				
		return test + 3;				//should print error--function add return type is int, but 'test + 3' is double type
	}
}
