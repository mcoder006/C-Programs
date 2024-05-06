#include<stdio.h>
#include<time.h>

int main() {
    int num;

    int numToGuess, guessNum = 0;
    
    srand(time(NULL));

    printf("Please Welcome to the number guessing game : \n\n");
    
    numToGuess = rand() % 100 + 1;
    
    printf("%d\n", numToGuess);
    

    do {
    	
    	guessNum++;
        
        printf("Enter a number between (1 to 100) : ");
        scanf("%d", &num);
        
        if(num < numToGuess) {
        	printf("The number is small than guess number.\n\n");
		}
		else if(num > numToGuess) {
        	printf("The number is greater than guess number.\n\n");
		}
		else if(num < 0) {
			printf("Invalid Number!\n");
		}
		else if(num == numToGuess) {
			printf("Congratulations you guessed correct number in %d times. !!!\n\n", guessNum);
		}

    } while(num != numToGuess);
    
    
    printf("Developed By: Sushank Ghimire\n\n");
    
    return 0;

}
