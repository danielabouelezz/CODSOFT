#include <iostream>
#include <vector>

using namespace std;


struct task{
    string toDo;
    bool isComplete;

    task(string newTask){
        toDo = newTask;
        isComplete = false;
    }
};

vector<task> _List;

void displayChoices(){
    cout<<"Input 1 to add task: \n";
    cout<<"Input 2 to display tasks: \n";
    cout<<"Input 3 to mark task as completed: \n";
    cout<<"Input 4 to remove task: \n";
    cout<<"Input 5 to exit: \n";
}

void addTask(string enterTask){
    task newTask(enterTask);
    _List.push_back(newTask);
}

void displayList(){
    int i{0};
    for(auto& task : _List){
        cout<<i<<"- "<<task.toDo<<"\t";
        if(task.isComplete) cout<<"Completed.\n";
        else cout<<"Not completed.\n";
        i++;
    }
}

void removeTask(int index){
    _List.erase(_List.begin() + index);
}

void markAsComplete(int index){
    _List[index].isComplete = true;
}

int main(){
    bool exit = false;

    while(!exit){
        system("clear");
        cout<<"##TO-DO-LIST##\n\n";
        int choice;
        displayChoices();
        cin>>choice;
        while(choice < 1 || choice > 5){
            cout<<"Invalid choice. Choose again: ";
            cin>>choice;
        }

        switch(choice){
            case 1:{
                string enterTask;
                cout<<"Enter your task to the to do list: \n";
                cin.ignore();
                getline(cin, enterTask);
                addTask(enterTask);
                break;}
            case 2:{
                cout<<"Display List: \n";
                displayList();
                cout<<"\n\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;}
            case 3:{
                if(_List.empty()){
                    cout<<"The list is empty.";
                    break;
                }
                displayList();
                cout<<"\n\nMark task as completed using its number: \n";
                cout<<"Enter the number of the task: ";
                int i;
                cin>>i;
                while(i < 0 || i >= _List.size() || _List[i].isComplete){
                    cout<<"Invalid choice. Choose another task: ";
                    cin>> i;
                }
                markAsComplete(i);
                break;}
            case 4:{
                if(_List.empty()){
                    cout<<"The list is empty.";
                    break;
                }
                displayList();
                cout<<"\n\nRemove task using its number: \n";
                int index;
                cin>>index;
                while(index < 0 || index >= _List.size()){
                    cout<<"Invalid choice. Choose again: ";
                    cin>> index;
                }
                removeTask(index);
                break;}
            case 5:{
                exit = true;
                break;}
            default:
                cout<<"Enter a valid choice. \n";
                break;
        }
    }

    return 0;
}
