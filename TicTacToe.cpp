#include <iostream>

//A nicer looking way to implement std::endls.
void InsertLines(int num){
    for(int i = 0; i < num; i++){
        std::cout<<std::endl;
    }
}


//Initializes 3x3 board of 0s.
int* CreateBoard(){
    int* arr = new int[9];
    for(int i = 0; i < 9; i++){
        arr[i] = 0;
    }
    return arr;
}


//Displays board with code 0 = _ , 1 = X, 2 = O.
void DisplayBoard(int* table){
    for(int i = 0; i < 9; i ++){
        switch (table[i])
        {
        case 0:
            std::cout <<"_";
            break;
        
        case 1:
            std::cout<< "X";
            break;

        case 2:
            std::cout<<"O";
            break;
        
        default:
            std::cout<< " error ";
        }
        if(i % 3 == 2){
            InsertLines(1);
        }
    }
}


//Prints the board that shows number locations (1-9 grid).
void PrintLocationBoard(){
    for(int i = 1; i < 10; i++){
        std::cout<<i;
        if(i % 3 == 0){
            InsertLines(1);
        }
    }
}


//Gets the location the player wants to place thier mark.
int GetPlayerChoice(int* table){
    int choice = -1;
    InsertLines(1);
    std::cout<<"Choose Where to play. Input Correspoinding number.";
    InsertLines(2);
    bool valid_guess = false;
    while(!valid_guess){
        PrintLocationBoard();
        InsertLines(1);
        DisplayBoard(table);
        InsertLines(1);
        std::cout<<"Input: ";
        std::cin >> choice;
        choice = choice -1; // Displayed table was range 1-9 while we need it in terms of 0-8.
        if(choice >= 0 && choice < 9){
            if(table[choice] == 0){ //If Space empty
                valid_guess = true;
            }
            else{
                InsertLines(1);
                std::cout<<"This square has already been chosen."<<std::endl<<"Please Choose Again";
                InsertLines(1);
            }
        }
        else{
            InsertLines(1);
            std::cout<<"Your input was out of range."<<std::endl<< "Please choose a number between 1-9";
            InsertLines(1);
        }
        InsertLines(1);
    }
    return choice;
}



void PlaceMarker(int location, int marker, int* table){
    if(marker != 0 && marker != 1 && marker != 2){
        std::cout <<"Error. Incorrect marker value"<<std::endl;
    }
    else{
        table[location] = marker;
    }
}

int main(){
	int* table = CreateBoard();
}