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

int main(){
	int* table = CreateBoard();
}