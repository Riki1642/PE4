#include <iostream>

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
        
        if(table[i] == 0){
            std::cout <<"_";
            break;
        }
        else if(table[i] == 1){
            std::cout<< "X";
            break;
        }
        else if(table[i] == 2){
            std::cout<<"O";
            break;
        }
        else{
            std::cout<< " error ";
        }
        if(i % 3 == 2){
            std::cout<<std::endl;
        }
    }
}

int main(){
	int* table = CreateBoard();
}