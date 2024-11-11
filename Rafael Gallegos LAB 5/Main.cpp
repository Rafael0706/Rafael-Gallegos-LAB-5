/*
Rafael Gallegos Cespedes
Computer Science Fall 2024
Due: Nov. 12, 2024
Lab 5 Number Guessing Game
This lab is a basic demo of the C++ language.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// NumberGuessingGame class definition
class NumberGuessingGame {
private:
    int wins;
    int losses;
    int randomNum;
    int maxAttempts;

    // Messages for winning, losing, and replay prompts
    string winMessages[10] = {
        "Fantastic! You guessed it!",
        "Impressive! That's the right number!",
        "You're a genius! Correct guess!",
        "Amazing! You've found the number!",
        "Spot on! Well done!",
        "Bullseye! You nailed it!",
        "You did it! That's correct!",
        "Hooray! You got it right!",
        "Incredible! That's the number!",
        "Bravo! You guessed correctly!"
    };

    string loseMessages[10] = {
        "Better luck next time!",
        "Oh no! The number was hidden well.",
        "Close, but no cigar!",
        "Don't worry, keep trying!",
        "That was tough luck!",
        "Ouch! You'll get it next time!",
        "Almost! Try again soon.",
        "So close, yet so far!",
        "Not quite there. Try again!",
        "You'll get it next time!"
    };

    string playAgainMessages[10] = {
        "Do you want another go?",
        "How about a rematch?",
        "Fancy another round?",
        "Ready to try again?",
        "Think you can guess it this time?",
        "Care for another game?",
        "Shall we play again?",
        "One more try?",
        "Want to give it another shot?",
        "Do you dare to try again?"
    };

public:
    // Constructor to initialize wins and losses
    NumberGuessingGame() : wins(0), losses(0), maxAttempts(20) {
        srand(static_cast<unsigned int>(time(0))); // Initialize random seed
    }

    // Method to play a single game
    void playGame() {
        randomNum = rand() % 101; // Generate a number between 0 and 100
        int guess;
        bool won = false;

        cout << "Guess the number between 0 and 100. You have " << maxAttempts << " attempts." << endl;

        for (int attempt = 1; attempt <= maxAttempts; ++attempt) {
            cout << "Attempt " << attempt << ": ";
            cin >> guess;

            if (guess == randomNum) {
                displayRandomMessage(winMessages, 10);
                wins++;
                won = true;
                break;
            } else if (guess < randomNum) {
                cout << "The number is higher." << endl;
            } else {
                cout << "The number is lower." << endl;
            }
        }

        if (!won) {
            displayRandomMessage(loseMessages, 10);
            losses++;
            cout << "The correct number was: " << randomNum << endl;
        }
    }

    // Method to ask the user if they want to play again
    bool askPlayAgain() {
        char choice;
        displayRandomMessage(playAgainMessages, 10);
        cout << " (y/n): ";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }

    // Method to display total wins and losses
    void displayResults() {
        cout << "Total Wins: " << wins << ", Total Losses: " << losses << endl;
    }

private:
    // Helper method to display a random message from an array
    void displayRandomMessage(string messages[], int size) {
        int index = rand() % size;
        switch (index) {
            case 0: cout << messages[0] << endl; break;
            case 1: cout << messages[1] << endl; break;
            case 2: cout << messages[2] << endl; break;
            case 3: cout << messages[3] << endl; break;
            case 4: cout << messages[4] << endl; break;
            case 5: cout << messages[5] << endl; break;
            case 6: cout << messages[6] << endl; break;
            case 7: cout << messages[7] << endl; break;
            case 8: cout << messages[8] << endl; break;
            case 9: cout << messages[9] << endl; break;
        }
    }
};

// Main function
int main() {
    NumberGuessingGame game;

    do {
        game.playGame();
    } while (game.askPlayAgain());

    game.displayResults();
    return 0;
}

