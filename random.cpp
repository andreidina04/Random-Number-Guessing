#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int SelectLevel() {
	int choice;
	cout << "Select the difficulty (1-3)" << endl;
	cout << "1. Easy (10 attempts)" << endl;
	cout << "2. Medium (5 attempts)" << endl;
	cout << "3. Hard (3 attempts)" << endl;
	cin >> choice;
	while (choice < 1 || choice > 3) { // Check if the player's choice is valid
		cout << "Sorry! Your input is invalid!" << endl;
		cin >> choice;
	}
		return choice;
}

void PlayGame(int chances) {
	int NumberToGuess = rand() % 100 + 1;
	int playerGuess;

	for (int attempts = 0; attempts < chances; attempts++) { // Stop the game when the number of attempts reaches the maximum
		cout << "Enter your guess: ";
		cin >> playerGuess;
	
		if (playerGuess < 1 || playerGuess > 100) { 
			cout << "Invalid guess. Please guess a number between 1 and 100." << endl;
			attempts--; // Don't count invalid attempts
			continue;
		}
		if (playerGuess == NumberToGuess) { // Check if the player's guess is correct
			cout << "Congratulations! You did it! The number is " << NumberToGuess << "." << endl;
			return;
	}
		else if (playerGuess < NumberToGuess) { // The guess is too low
			cout << "Incorrect! The number is greather than " << playerGuess << "." << endl;
		}
		else if (playerGuess > NumberToGuess) { // The guess is too high
			cout << "Incorrect! The number is less than " << playerGuess << "." << endl;
		}
	}
	cout << "Game Over! You used all your chances. The correct number was " << NumberToGuess << "." << endl;
}

int main() {
	srand(time(0));

	cout << "Welcome to Number Guessing Game!" << endl;
	cout << "You need to guess a number between 1 and 100. Good luck!" << endl;

	int level = SelectLevel();
	int chances;
	switch (level) {
	case 1:
		cout << "You selected the Easy Level." << endl;
		chances = 10;
		break;
	case 2:
		cout << "You selected the Medium Level." << endl;
		chances = 5;
		break;
	case 3:
		cout << "You selected the Hard Level." << endl;
		chances = 3;
		break;
	default:
		cout << "Invalid level selected. Exiting game." << endl;
		return 1;
	}

	PlayGame(chances);
}
