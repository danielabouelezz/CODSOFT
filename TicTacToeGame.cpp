#include <iostream>

using namespace std;
char board[10];

void setUp(){
    system("clear");
    cout<<"##Let's play some Tic-Tac-Toe!!!##";
    cout<<"\n\nPlayer 1 -> X, Player 2 -> O";
    cout<<"\n\n   |   |   ";
    cout<<"\n "<<board[1]<<" | "<<board[2]<<" | "<<board[3];
    cout<<"\n---|---|---";
    cout<<"\n "<<board[4]<<" | "<<board[5]<<" | "<<board[6];
    cout<<"\n---|---|---";
    cout<<"\n "<<board[7]<<" | "<<board[8]<<" | "<<board[9];
}

int checkWinOrDraw(){
    //Cheching if there's a win
    if(board[1] == board[2] && board[2] == board[3]) return 1;
    else if(board[4] == board[5] && board[5] == board[6]) return 1;
    else if(board[7] == board[8] && board[8] == board[9]) return 1;
    else if(board[1] == board[4] && board[4] == board[7]) return 1;
    else if(board[2] == board[5] && board[5] == board[8]) return 1;
    else if(board[3] == board[6] && board[6] == board[9]) return 1;
    else if(board[1] == board[5] && board[5] == board[9]) return 1;
    else if(board[3] == board[5] && board[5] == board[7]) return 1;
    //Checking if there's a draw
    else if(board[1] != '1' && board[2] != '2' && board[3] != '3' &&
            board[4] != '4' && board[5] != '5' && board[6] != '6' &&
            board[7] != '7' && board[8] != '8' && board[9] != '9'){
            return 0;
            }
    //The game is still ongoing
    else return -1;

}

bool promptAnotherGame(){
    system("clear");
    cout<<"\nDo you wanna play another match?(y/n)";
    char choice;
    cin>>choice;
    choice = tolower(choice);
    while(choice  != 'y' && choice != 'n'){
        cout<<"Enter a valid choice(y/n):";
        cin>>choice;
        choice = tolower(choice);
    }
    return choice == 'y';
}

int main(){
    do{
        board[1] = '1', board[2] = '2', board[3] = '3',
        board[4] = '4', board[5] = '5', board[6] = '6',
        board[7] = '7', board[8] = '8', board[9] = '9';
        int player = 1, i = -1, choice;

        while(i == -1){
            setUp();
            player = (player % 2)? 1 : 2;
            cout<<"\nIt is player "<<player<<"'s turn: ";
            cout<<"\nChoose a number: ";
            cin>>choice;
            while(choice > 9 || choice < 1 || board[choice] == 'O' || board[choice] == 'X'){
                cout<<"\nInvalid choice. Choose another number: ";
                cin>>choice;
            }
            board[choice] = (player%2)? 'X' : 'O';

            i = checkWinOrDraw();
            if(i == 1) {cout<<"PLAYER "<<player<< " WINS!!";break;}
            else if(i == 0) {cout<<"It is a DRAW.\n";break;}
            player++;
        }

    }while(promptAnotherGame());


    return 0;
}
