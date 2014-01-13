public class abc {
	public double sq (double i, int j) {
		int[] a = new int[3];
		int a = 3;					//should print error
		return i * i;
	}

	public int add () {
		double test;
		test = sq (test,3);
		test = sq (3,3.3);				//should print error
		test = sq (3,890);
		return test + 3;				//should print error
	}
}
