//typeid().name = ()안의 변수의 타입을 리턴해줌.
#include<iostream>
using namespace std;
float dividezero(float a, float b){
    if(a/b > a){
        cout << a/b <<endl;
        return a/b;
    }else if(a/b < a){
        cout << a <<endl;
        return a;
    }
    return b;
}

int main(){
    return 0;
}