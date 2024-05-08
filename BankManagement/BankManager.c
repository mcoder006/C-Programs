#include<stdio.h>
#include<string.h>

typedef struct {
	char name[50];
	int account_num;
	float balance;
} Account;

const char * Account_file = "account.dat";

int createAccount() {
	Account acc;
	
	FILE *fp;
	fp = fopen("account.dat", "ab+");
	
	if(fp == NULL) {
		printf("unable to open file.");
		return;
	}
	
	char c;
	
	do {
		c = getchar();
	} while ( c != '\n' && c != EOF);
	
	printf("Enter your name : ");
	fgets(acc.name, sizeof(acc.name), stdin);
	int ind = strcspn(acc.name, "\n");
	acc.name[ind] = '\0';
	printf("Enter your account number : ");
	scanf("%d", &acc.account_num);
	acc.balance = 0;
	
	fwrite(&acc, sizeof(acc), 1, fp);
	fclose(fp);
	printf("Account Created Successfully!\n\n");
	
}

int depositAmount() {
	FILE *fp = fopen(Account_file, "rb+");
	
	if(fp == NULL) {
		printf("unable to open file.");
		return;
	}
	
	Account acc_to_read;
	
	int acc_num;
	float deposit_amount;
	
	printf("Enter your account number : ");
	scanf("%d", &acc_num);
	printf("Enter amount to deposit : ");
	scanf("%f", &deposit_amount);
	
	while(fread(&acc_to_read, sizeof(acc_to_read), 1, fp)) {
		if(acc_to_read.account_num == acc_num) {
			acc_to_read.balance += deposit_amount;
			fseek(fp, -sizeof(acc_to_read), SEEK_CUR);
			fwrite(&acc_to_read, sizeof(acc_to_read), 1, fp);
			fclose(fp);
			printf("Successfully deposited Rs.%.2f and the new balance is Rs.%.2f.\n", deposit_amount, acc_to_read.balance);
			return;
		}
	}
	fclose(fp);
	printf("Account number : %d not found.\n", acc_num);
}


void withdrawAmount() {
	FILE *fp = fopen(Account_file, "rb+");
	
	if(fp == NULL) {
		printf("unable to open file.");
		return;
	}
	
	Account acc_to_read;
	
	int acc_num;
	float withdraw_amount;
	
	printf("Enter your account number : ");
	scanf("%d", &acc_num);
	printf("Enter amount to withdraw : ");
	scanf("%f", &withdraw_amount);
	
	while(fread(&acc_to_read, sizeof(acc_to_read), 1, fp)) {
		if(acc_to_read.account_num == acc_num) {
			if (acc_to_read.balance < withdraw_amount) {
				printf("Insufficient balance!\n");
				fclose(fp);
				return;
			}
			acc_to_read.balance -= withdraw_amount;
			fseek(fp, -sizeof(acc_to_read), SEEK_CUR);
			fwrite(&acc_to_read, sizeof(acc_to_read), 1, fp);
			fclose(fp);
			printf("Successfully withdrawn Rs.%.2f and the new balance is Rs.%.2f.\n", withdraw_amount, acc_to_read.balance);
			return;
		}
	}
	fclose(fp);
	printf("Account number : %d not found.\n", acc_num);
}


void checkBalance() {
	FILE *fp;
	
	fp = fopen(Account_file, "rb");
	
	if(fp == NULL) {
		printf("Account cannot found!\n\n");
		return;
	}
	
	int acc_number;
	
	Account acc_read;
	
	printf("Enter your account number : ");
	scanf("%d", &acc_number);
	
	while(fread(&acc_read, sizeof(acc_read), 1, fp)){
		if(acc_read.account_num == acc_number) {
			printf("Your account balance is Rs.%.2f\n", acc_read.balance);
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	printf("Account No: %d cannot found!\n\n", acc_number);
}

int main() {
	
	int option;
	
	do {
		printf("\n\n*** Bank Management System *** \n");
		printf("\n1. Create Account \n2. Deposit Money \n3. Withdraw Money \n4. Check Balance \n5. Exit \n");
		printf("Enter the Choice : ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				createAccount();
				break;
			case 2:
				depositAmount();
				break;
			case 3:
				withdrawAmount();
				break;
			case 4:
				checkBalance();
				break;
			default:
				printf("Invalid Option!\n\n");
		}
		
	} while (option != 5);
	
	
	return 0;
}

