#include<stdio.h>
#include<math.h>

int choice;

int addition() {
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d %d", &a, &b);
	printf("The sum is : %d.\n", a+b);
}

int subtract() {
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d %d", &a, &b);
	printf("The subtraction is : %d.\n", a-b);
}

int multiply() {
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d %d", &a, &b);
	printf("The Multiplication is : %d.\n", a*b);
}

int divide() {
	float a, b;
	printf("Enter two numbers : ");
	scanf("%f %f", &a, &b);
	printf("The division is : %0.2f.\n", a/b);
}

int modulus() {
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d %d", &a, &b);
	printf("The Modulus is : %d.\n", a%b);
}

int power() {
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d %d", &a, &b);
	printf("The Power is is : %d.\n", pow(a, b));
}

int main() {
	
	printf("--------------------------------------------\n");
	printf("-------Welcome to the simple calculator ----\n\n");
	
	do {
		printf("choose one of the following options : \n1.Addition \n2.Subtraction \n3.Multiply \n4.Divide \n5.Modulus \n6.Power \n7.Exit \n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				addition();
				printf("\n");
				break;
			case 2: 
				subtract();
				printf("\n");
				break;
			case 3:
				multiply();
				printf("\n");
				break;
			case 4:
				divide();
				printf("\n");
				break;
			case 5:
				modulus();
				printf("\n");
				break;
			case 6:
				power();
				printf("\n");
				break;
			case 7:
				printf("Thanks for using the calculator.\n");
				break;
			default:
				printf("Enter a valid choice!\n\n");
		}
	} while (choice != 7);

    printf("Developed By: Sushank Ghimire\n\n");

    return 0;
}
