#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
*Generates a random number between minNumber and maxNumber (inclusive).
* @param minNumber The minimum number in the range.
* @param maxNumber The maximum number in the range.
* @return A random number between minNumber and maxNumber.
*/
int generateRandomNumber(int minNumber, int maxNumber){
    int number = rand() % (maxNumber - minNumber +1) + minNumber;
    return number;
}

/**
 * Runs the number guessing game. Prompts the user to enter a range and then
 * attempts to guess the randomly generated number within a limited number of tries.
 */
void NumberGuessingGame(){
    cout<<"Hello! Between wich two numbers the random number should be?\n";
    int minNumber, maxNumber;
    cout<<"Please enter the smallest number and the biggest number respectively:\n";
    cin>>minNumber>>maxNumber;

    //Validate the input range
    while(minNumber > maxNumber){
        cout<<"Invalid range. The smallest number must be less than or equal to the biggest number.\n";
        cout<<"\n";
        cout<<"Please enter the smallest number and the biggest number respectively:\n";
        cin>>minNumber>>maxNumber;
    }

    // Generate a random number within the specified range
    int randomNumber = generateRandomNumber(minNumber, maxNumber);
    cout<<"Let's start! Try to find the random number.\n";
    int guess;

    // Loop until the useer guesses correctly
    while(true){
        cout<<"Enter a guess: ";
        cin>> guess;

        if(guess == randomNumber){
            cout<<"YOU ARE CORRECT!\n\n";
            return;
        }else{
            cout<<"Wrong Answer...Try again.\n";
            if(guess < randomNumber) cout<<"The guess is too low!\n";
            else{cout<<"The guess is too high!\n";}
        }
    }
}

bool promptPlayAgain(){
    int choice;
    cout<<"\n";
    cout<<"Do you want to play again? Choose 1 for 'yes' and 0 for 'no'. \n";
    cin>>choice;

    //Validate the user's input
    while(choice != 0 && choice != 1){
        cout<<"Please enter 1 for 'yes' or 0 for 'no'. \n";
        cin>>choice;
    }

    return choice == 1;
}

/**
 * The main function initializes the random number generator and runs the game loop.
 * @return Exit status of the program.
 */
int main(){
    srand(time(0));

    do{
        NumberGuessingGame();
    }while(promptPlayAgain());

    return 0;
}
