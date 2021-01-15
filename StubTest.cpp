#include <iostream>
#include "AAA.h"
using namespace std;
int StubTest(int a, int b){ // int 파라미터 심볼 생성
    int x = AStub(1,1);
    if(x > (a-b)){
        return x;
    }else if(x <= (a-b)){
        return a-b;
    }else{
        return -1;
    }
}


int main(){
    cout <<StubTest(4,3) <<endl;
    if((4%3) > (4-3)){
        cout << "4%3 > 4-3" <<endl;
    }
    return 0;
}