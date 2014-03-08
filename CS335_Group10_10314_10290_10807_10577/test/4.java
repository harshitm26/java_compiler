class Test4{
	public static void main(){
		int i=0;
		if(false){
			if(false){
				i=5;
			}else{
				i=6;
			}
		}else{
			if(true){
				i=7;
			}else{
				i=8;
			}
		}
		


		while(i<10){
			i++;
			printint(i); printstring("\n");
		}
		


		do{
			i++;
			printint(i); printstring("\n");
		}while(i<20);
		
		for(i=23; i<=20;){
			printint(i); printstring(" ");
			i++;
		}

		i=0; int j=0; 
		
		while(i<20){
			j=0;
			while(j<8){
				printstring("(");
				printint(i);
				printstring(",");
				printint(j);
				printstring(") ");
				j++;
			}
			printstring("\n");
			i++;
		}
	
		printstring("\n");
	}
}
