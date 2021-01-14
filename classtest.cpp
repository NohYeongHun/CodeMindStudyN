#include <string.h>
#include <iostream>
using namespace std;

class A{
    private:
    int a;
    int b;
    public:
    int x=10, y=10;
    A(int a, int b){
        this->a = a;
        this->b = b;
        //this->a 멤버 a는 매개 변수
    }
    void printing(){
        cout <<this ->a <<endl;
        cout <<this ->b <<endl;      
    }
    protected:
        float z;
        float w;
};


// T sum (T a, T b){
//     return a + b;
// }

void ClassFunc(A x){
    for(int i = 0; i<x.x; i++){
    for(int j = 0; j<x.y; j++){
        cout<<"*";
    }
        cout<<"\n";
    }
}


int main(){
    // A as(2,3);
    // as.printing();
    // cout << "sum " << sum<double>(d1,d2) <<endl;
    return 0;
}