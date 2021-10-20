/*
Written By: Nikhil Nayak
Date: 10/20/21
Description: An implementation of guessing game in c++. Compares user input to a random number, and gives feedback (higher/lower) until the number is guessed. 
*/

#include <iostream> // for IO
#include <cstring> // c string operations (strcmp)
#include <time.h> // for getting unix time
#include <limits> // for 

void play_game()
{
	const uint8_t random_number = rand() % 100; // gets a random number from 0 to 100

	// std::cout << (int)random_number << "\n"; // prints number (for debugging)

	uint32_t num_guesses = 0; // tracks number of guesses; hopefully user doesnt guess 2^32 times

	uint64_t guess = 0; // stores the user's guess
	while (true)
	{
		std::cout << "Submit a guess: ";
		while(!(std::cin >> guess)){
			// for when you pass anything other than a number
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the whole buffer
			std::cout << "Invalid input, please try again: ";
		}
		num_guesses += 1;
		// print out messages according to whether the guess is less than, equal, or greater than the number
		if (guess == random_number)
		{
			std::cout << "You guessed the number in: " << num_guesses << " guesses\n";
			return;
		}
		else if(guess > random_number){
			std::cout << "Too high\n";
		}
		else{
			std::cout << "Too low\n";
		}
	}
}

bool play_again(){
	char input[256]; // stor 256 characters for input(if you pass more than 256 characters, the program will hang)
	while(true){
		std::cout << "Would you like to play again (y/n): ";
		std::cin >> input;
		if(strcmp(input, "y") == 0){
			return true;
		}
		else if(strcmp(input, "n") == 0){
			return false;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL)); // set random seed based on unix time

	while(true){
		play_game();
		if(!play_again()){
			break;
		}

	}
	return 0;
}
