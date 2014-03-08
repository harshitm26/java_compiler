class Fibonacci{

	public int factorial(int n){
		if(n==1){
			return 1;
		}else{
			return n*factorial(n-1);
		}
		
	}
	
	public void main(){

		int i=0, j=1;
		while(j<500){
			int k = i+j;
			i=j;
			j=k;
			printint(j); printstring(" ");
		}
		printstring("\n");
		int l=1;
		while(l<10){
			printint(factorial(l)); printstring(" ");
			l++;
		}		
		printstring("\nPrinting a float: ");
		printfloat(23.45f);
	}
}
