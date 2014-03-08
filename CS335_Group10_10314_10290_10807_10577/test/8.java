class BubbleSort{
	public void main(){
		int[] a = new int[20];
		int i=0;
		while(i<20){
			a[i] = i*i;
			printint(a[i]); printstring(" ");
			i++;
		}
		printstring("\n");
		int j=0;
		int temp;
		i=0;
		while(i<20){
			j=i+1;
			while(j<20){
				if(a[i] < a[j]){
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					j++;
				}else{
					j++;
				}
				
			}
			i++;
		}
		i=0;
		while(i<20){
			printint(a[i]); printstring(" ");
			i++;
		}		
	}
}
