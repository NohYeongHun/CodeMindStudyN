#include <iostream>
using namespace std;
int a=0;
int b=0;
int FTest(int a, int b){ 
    if(a >=b){ //int 파라미터 심볼화
        return a;
    }else{
        return b;
    }
    
}
void FParam(int (*fp)(int ,int)){ // int *fp 선언 (int, int)인자를 가진 함수를 매개변수로받음
    printf("%d %d", a ,b);
}
int main(){
    cout<<a<<endl;
    FParam(FTest);
    return 0;
}