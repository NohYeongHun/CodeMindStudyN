#include<iostream>
using namespace std;

//ex) Function Pointer
void PrintV(int value){
    cout << "Value : " << value <<endl;
}

int main(){
    int i =0;
    void (*p_print)(int) = PrintV;
    PrintV(6);
    p_print(5);
    return 0;


    cout<< "testarray["<< i <<"]" <<endl;
}