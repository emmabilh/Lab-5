// Emma Bilhimer
// FA 2023
// Due 10/10/2023
// Busch Lab 5
/* Description: Write a number-guessing game in which the computer selects a random
 number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
 the end of each game, users should be told whether they won or lost, and then be asked
 whether they want to play again. When the user quits, the program should output the
 total number of wins and losses. To make the game more interesting, the program
 should vary the wording of the messages that it outputs for winning, for losing, and for
 asking for another game. Create 10 different messages for each of these cases, and use
 random numbers to choose among them. This application should use at least one Do-
 While loop and at least one Switch statement. Write your C++ code using good style and
 documenting comments. You should use classes in your code as well. Your source code
 file should be called Lab5.cpp.
 Lab5.hpp
 Lab5
 */

#ifndef LAB5_H
#define LAB5_H

class NumberGuessingGame {
public:
    NumberGuessingGame();  // constructor
    void StartGame();
    void PlayAgain();
    void PrintGameResults(bool isWin);

private:
    int secretNumber;
    int attemptsLeft;
    int wins;
    int losses;

    const int maxAttempts = 20;

    // private
    void GenerateSecretNumber();
};

#endif
