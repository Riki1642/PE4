#include <iostream>

//Initializes 3x3 board of 0s.
int* CreateBoard(){
    int* arr = new int[9];
    for(int i = 0; i < 9; i++){
        arr[i] = 0;
    }
    return arr;
}

int main(){
	int* table = CreateBoard();
}