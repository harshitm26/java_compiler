class Animal{
	public int life;
	Animal(){
		this.life=1;
	}
	public void speak(){
		printstring("Foo\n");
		
	}
}
class Dog extends Animal{
	private int age;
	Dog(int age){
		this.age = age;
		while(this.age<10){
			this.age = this.age + 2;
			printint(this.age); printstring("\n");
		}
	}

	public void speak(){
		printstring("Bau wau!\n");
		
	}
}


class Cat extends Animal{
	public int age;
	Cat(){
		this.age=2;
	}
	public void speak(){
		printstring("Meow!\n");
	}
}

class Cow extends Animal{
	public int age;
	public Cow(){
		this.age=2;
	}
	public void speak(){
		printstring("Moo Moo!\n");
	}
}

class Pomerian extends Dog{
	Pomerian(int age){
		this.age = age;
	}
	public void speak(){
		printstring("Pomerian Bau wau!\n");
	}
}

class Zoo{
	public void main(){

		Dog tommy = new Dog(12);
		tommy.speak();
		printstring("tommy.age = "); printint(tommy.age); printstring("\n");
		printstring("tommy.age changed to 23\n"); tommy.age = 23;
		printstring("tommy.age = "); printint(tommy.age); printstring("\n");

		Cat katie = new Cat();
		printstring("katie.age = "); printint(katie.age); printstring("\n");
		printstring("katie.age changed to 45\n"); katie.age=45;
		printstring("katie.age = "); printint(katie.age); printstring("\n");
		katie.speak();
		
		Pomerian bruno = new Pomerian(23);
		bruno.speak();
		
		Cow nandini = new Cow();
		nandini.speak();

		Animal alice = (Animal) nandini;
		alice.speak();
		
	}
}
	
