#include <stdio.h>
#include "TTT.h"
#include <assert.h>

int assert1(int x, int y){

    assert(x == 100);
}
int out(int x, int y){
    int a[2] = {1,2};
    
    printf("%d",a[3]);
    if(a[3] == 100){
        return 1;
    }

    assert(x != 0);
}
int seg(int x, int y){

    int n;
    int b = n + 1;
    printf("%d",b);
    if (n > 10){
        return 10;
    }

}
int div(int x, int y){
    if(x / y){
        return 0;
    }

}
int doublePointer(int** doublePointer){
    if(**doublePointer == 0){
        return 0;
    }
    else{
        return 1;
    }
}
// int isStubTest(int a, int b){
//     int x = isStub(a,b);
//     if(x > 0){
//         return 1;
//     }
//     else {
//         return 0;
//     }
//     return 0;
// }

int pointerFunc(double* flot){
    if(*flot > 10.1){
        return 1;
    }
    else{
        return 0;
    }
}
int arrayFunc(int array[]){
    if(array[1] == 0){
        return 1;
    }
    else if(array[2] >= 10){
        return 0;
    }
    else{
        return 0;
    }
    return -1;
}

struct T{
    int T1;
    int T2;
};

typedef struct T TStruct;

int stuct(TStruct t)
{
    if(t.T1 == 1){
        return 0;
    }
    return 1;
}
int main (){
    int** a = 123;
    seg(1,2);
    return 0;
}