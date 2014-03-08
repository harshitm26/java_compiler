class Array{
	public void main(){
		int [][] a = new int[20][20];
		int i=0, j=0;
		while(i<20){
			j=0;
			while(j<20){
				a[i][j] = j+i;
				//printint(a[i][j]); printstring(" ");
				j++;
				
			}
			i++;
			//printstring("\n");
		}

		
		i=0; j=0;
		while(i<20){
			j=0;
			while(j<20){
				printint(a[i][j]); printstring(" ");
				j++;
			}
			i++;
			printstring("\n");
		}
	}
}
