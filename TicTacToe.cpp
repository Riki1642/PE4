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


bool IsGameOver(int* Table){
    int temp;
    bool same = true;
    //Test verical rows for winner.
    for(int col = 0; col < 3; col++){
        temp = Table[col]; //Set temp to first element for comparing.
        if(temp == 0){
            //If a temp is 0, then the player hasn't won in this column so we can skip.
            continue;
        }
        for(int y = 0; y < 3; y++){
            //For each vertical element in that column.
            if(Table[col + 3*y] != temp){
                //Element is different from top of col - no winner in this col.
                same = false;
                break;
            }
        }
        if(same){
            //Winner Declared
            std::cout<<"Winner in vertical row!"<<std::endl;
            return true;
        }
    }
    //Test horizontal rows for winner.
    for(int row = 0; row < 3; row++){
        same = true;
        temp = Table[3*row];
        if(temp == 0){
            continue;
        }
        for(int x = 0; x < 3; x++){     
            if(Table[3*row + x] != temp){
                same = false;
                break;
            }
        }
        if(same){
            //Winner Declared
            std::cout<<"Winner in horizontal row!"<<std::endl;
            return true;
        }
    }

    //Test Downward Right diagonal line
    temp = Table[0];
    if(temp != 0){
        //If Temp = 0, this line is not a winner so we can skip.
        //If it is not 0, we have to test to see if there is a winner.
        same = true;
        for(int i = 0; i < 3; i++){
            if(Table[3*i + i] != temp){
                same = false; 
            }
        }
        if(same == true){
            //Winner Declared
            std::cout<<"Winner in Downward Right Diagonal!"<<std::endl;
            return true;
        }
    }
    //Test Upward Left diagonal line
    temp = Table[2];
    if(temp != 0){
        same = true;
        int j = 0;
        for(int i = 2; i >= 0; i--){
            if(Table[3*i + j] != temp){
                same = false;
            }
            j++;
                
        }
        if(same == true){
            //Winner Declared
            std::cout<<"Winner in Upward Left Diagonal!"<<std::endl;
            return true;
        }
    }


    for(int i = 0; i < 9; i++){
        if(Table[i] == 0){
            return false;
        }
        else{
            continue;
        }
    }
    std::cout<<"All Spaces Taken. Game is a draw.";
    return true;
}

int main(){
    int* table =  CreateBoard();
    int turncount = 0;
    int turnmarker = -1;
    while(!IsGameOver(table)){
        turncount++;
        std::cout<<std::endl;
        if(turncount % 2 == 0){
            std::cout<<"Player X"<<std::endl;
            turnmarker = 1;
        }
        else{
            std::cout<<"Player O"<<std::endl;
            turnmarker = 2;
        }
        int choice = GetPlayerChoice(table);
       PlaceMarker(choice, turnmarker, table);
    }
    std::cout<<std::endl;
    DisplayBoard(table);
}