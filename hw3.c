#include <stdio.h>
#include <time.h>

int rand_func(int max_num);
int rand_num();
int rps();

int main(int argc, char* argv[]) {
	int idx;
	printf("************************\n");
	printf("       Select Game\n");
	printf("1. Rock, Paper, Scissors\n");
	printf("2. Guessing the Numbers\n");
	printf("3. Exit\n");
	printf("************************\n");
	printf("\n");
	printf("Choose game > ");
	scanf_s("%d", &idx);

	while (idx != 3) {
		if (idx == 1) rps();
		else if (idx == 2) rand_num();
		printf("************************\n");
		printf("       Select Game\n");
		printf("1. Rock, Paper, Scissors\n");
		printf("2. Guessing the Numbers\n");
		printf("3. Exit\n");
		printf("************************\n");
		printf("\n");
		printf("Choose game > ");
		scanf_s("%d", &idx);
	}
	printf("Exit program.\n");

	return 0;
}

int rand_num() {
	int num, rn, n;

	printf("Input random number's max value > ");
	scanf_s("%d", &num);

	rn = rand_func(num);

	printf("Guess random number > ");
	scanf_s("%d", &n);

	while (n != rn) {

		if (n > rn)
			printf("Input a smaller number.\n");
		else
			printf("Input a bigger number.\n");
		printf("Guess random number > ");
		scanf_s("%d", &n);
	}
	printf("BINGO !\n\n");

	return;
}

int rps() {
	int hand;
	int comHand = rand_func(3);
	printf("Choose 1.Rock  2.Paper  3.Scissors\n");
	scanf_s("%d", &hand);
	
	switch (hand) {
		case 1:
			if (comHand == 2) {
				printf("You : Rock / COM : Paper\n");
				printf("You lose..\n\n"); 
				break;
			}
			else if (comHand == 3) {
				printf("You : Rock / COM : Scissors\n");
				printf("You win !\n\n");
				break;
			}
			else {
				printf("You : Rock / COM : Rock\n");
				printf("Draw\n\n");
				break;
			}
		case 2:
			if (comHand == 3) {
				printf("You : Paper / COM : Scissors\n");
				printf("You lose..\n\n");
				break;
			}
			else if (comHand == 1) {
				printf("You : Paper / COM : Rock\n");
				printf("You win !\n\n");
				break;
			}
			else {
				printf("You : Paper / COM : Paper\n");
				printf("Draw\n\n");
				break;
			}
		case 3:
			if (comHand == 1) {
				printf("You : Scissors / COM : Rock\n");
				printf("You lose..\n\n");
				break;
			}
			else if (comHand == 2) {
				printf("You : Scissors / COM : Paper\n");
				printf("You win !\n\n");
				break;
			}
			else {
				printf("You : Scissors / COM : Scissors\n");
				printf("Draw\n\n");
				break;
			}		
	}
	return;
}

int rand_func(int max_num) {
	srand((unsigned)time(NULL));

	return rand() % max_num + 1;
}