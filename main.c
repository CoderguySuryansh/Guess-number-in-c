#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, attempts = 0;
    char playAgain;

    // Generate a random number between 1 and 100
    srand(time(0));
    number = rand() % 100 + 1;

    printf("Welcome to the Guess the Number game!\n");
    printf("I have chosen a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess == number) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);

            // Ask if the player wants to play again
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &playAgain);

            if (playAgain == 'y' || playAgain == 'Y') {
                // Generate a new random number for the next game
                number = rand() % 100 + 1;
                attempts = 0;
            } else {
                printf("Thanks for playing. Goodbye!\n");
                break;
            }
        } else if (guess < number) {
            printf("Try again. The number is higher than %d.\n", guess);
        } else {
            printf("Try again. The number is lower than %d.\n", guess);
        }

    } while (1); // Infinite loop for continuous play

    return 0;
}
