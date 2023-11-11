//  Lab5.cpp
//  Lab5


#include "Lab5.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//constructor
NumberGuessingGame::NumberGuessingGame() : secretNumber(0), attemptsLeft(0), wins(0), losses(0), maxAttempts(20) {
    // calls and sets the max number of attempts to 20
}

void NumberGuessingGame::GenerateSecretNumber() {
    // generate a random number between 0 and 100.
    // random using the current time //copilot
    srand(static_cast<unsigned int>(time(nullptr)));
    secretNumber = rand() % 101;
}

void NumberGuessingGame::StartGame() {
    attemptsLeft = maxAttempts;  // reset the number of attempts
    GenerateSecretNumber();  // generates a new number

    while (attemptsLeft > 0) {
        int guess;
        std::cout << "Attempts left: " << attemptsLeft << ". Enter your guess: ";
        std::cin >> guess;

        if (guess == secretNumber) {
            PrintGameResults(true);  // player guessed right
            wins++;  // add 1 to the win count
            break;
        } else {
            attemptsLeft--;
            if (attemptsLeft == 0) {
                PrintGameResults(false);  // player out of attempts
                losses++;  // add 1 to loss count
                break;
            } else {
                std::cout << "Wrong guess. Try again." << std::endl;
            }
        }
    }

    PlayAgain();  // asks to play again
}

void NumberGuessingGame::PlayAgain() {
    int choice;
    std::cout << "1. Play again" << std::endl;
    std::cout << "2. Quit" << std::endl;
    std::cout << "Pick one: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            StartGame();  // start a new game
            break;
        case 2:
            std::cout << "Thanks for playing! Total Wins: " << wins << ", Total Losses: " << losses << std::endl;
            break;  // quit the game and display the total wins and losses
       
    }
}

void NumberGuessingGame::PrintGameResults(bool isWin) {
    if (isWin) {
        std::cout << "You won!" << std::endl;  // player wins message
    } else {
        std::cout << "You lost." << std::endl;  // player loses message
    }
}
