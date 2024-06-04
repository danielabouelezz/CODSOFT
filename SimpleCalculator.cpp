#include <iostream>
#include <cctype>

using namespace std;

double add(){
    double number1, number2;
    cout<<"Number 1: ";
    cin>> number1;
    cout<<"Number 2: ";
    cin>> number2;

    return number1 + number2;
}

double substract(){
    double number1, number2;
    cout<<"Number 1: ";
    cin>> number1;
    cout<<"Number 2: ";
    cin>> number2;

    return number1 - number2;
}

double multiply(){
    double number1, number2;
    cout<<"Number 1: ";
    cin>> number1;
    cout<<"Number 2: ";
    cin>> number2;

    return number1 * number2;
}

double divide(){
    double number1, number2;
    cout<<"Devidend : ";
    cin>> number1;
    cout<<"Divisor : ";
    cin>> number2;

    while(!number2){
        cout<<"The Divisor can't be 0, Enter another number: ";
        cin>> number2;
    }
    return number1 / number2;
}

bool promptUseCalculatorAgain(){
    cout<<"Do you want to do another equation(y/n): ";
    char choice;
    cin>>choice;
    choice = tolower(choice);
    while(choice != 'y' && choice != 'n'){
        cout<<"Choose 'y' for yes and 'n' for no: \n";
        cin>>choice;
        choice = tolower(choice);
    }
    return choice == 'y';
}

int displayChoiceMenu(){
    cout<<"Choose: \n";
    cout<<" 1--> addition\n 2--> substruction\n 3--> multiplication\n 4--> division\n";
    int choice;
    cin>>choice;
    return choice;
}

int main(){
    do{
        int choice = displayChoiceMenu();

        switch(choice){
            double x;
            case 1:
                cout<<"\n";
                x = add();
                cout<< "The Sum is : "<< x<<"\n";
                break;
            case 2:
                cout<<"\n";
                x = substract();
                cout<< "The result is : "<< x<<"\n";
                break;
            case 3:
                x = multiply();
                cout<< "The result is : "<< x<<"\n";
                break;
            case 4:
                x = divide();
                cout<< "The result is : " << x<<"\n";
                break;
            default:
                cout<<"Choose from the givin numbers: \n";
                break;

        }
    }while(promptUseCalculatorAgain());
    return 0;
}
