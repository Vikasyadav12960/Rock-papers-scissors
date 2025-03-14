#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame() {
    char *choices[] = {"Rock", "Paper", "Scissors"};
    int userChoice, computerChoice;
    
    printf("Choose an option:\n1. Rock\n2. Paper\n3. Scissors\nEnter your choice (1-3): ");
    scanf("%d", &userChoice);

    if (userChoice < 1 || userChoice > 3) {
        printf("Invalid choice. Please select between 1 and 3.\n");
        return;
    }

    srand(time(0));
    computerChoice = (rand() % 3) + 1;

    printf("You chose: %s\n", choices[userChoice - 1]);
    printf("Computer chose: %s\n", choices[computerChoice - 1]);

    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 1 && computerChoice == 3) || 
               (userChoice == 2 && computerChoice == 1) || 
               (userChoice == 3 && computerChoice == 2)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
