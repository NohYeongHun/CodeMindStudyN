#include <stdio.h>
int a = 10;
int b = 20;
//call by value
void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


int main(){

    printf("Previous swap  : %d %d\n", a, b);

    swap(&a, &b);
    // 호출되는 시점에 동작은 수행하지만 but 값은 가지고 오지 않음.

    printf("after swap  : %d %d\n", a, b);

    return 0;
}

// call by reference