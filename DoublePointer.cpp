#include <iostream>
#include <stdlib.h>
using namespace std;
/* 매개 변수에 a_str_list[][]라고 적으면 안되나요??
ex) char(*ap_str_list)[]; == (불가능)
why? => char(*ap_str_list)[16]이라고 적을 경우 ap_str_list는 
char[16]이라는 대상을 가리킨다는 뜻이 되어 다음 대상이 16바이트 뒤에
있다는 것을 알 수 있지만 char(*ap_str_list)[]라고 적을 경우 대상의 크기가
char[]가 되어 크기를 예상할 수 없어서 오류 발생.
동적할당의 경우에는 2차원 배열 **int a_list 이런식으로 매개변수를 넘길 수 있음
ex) void(**int a_list){
}
*/
// void assign(int** arr, int m, int n) //double pointer
// {
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             arr[i][j] = i + j;
//         }
//     }
// }
/* 
a_int_list[a_count][a_count]
*/
#define  a_count 5

void doublePointer(int (*a_int_list)[a_count], int a_count_){ //(*a_int_list) -> &(a_int_list[0][index])

    for (int i =0; i<a_count_; i++){
        //a_int_list[0][i] = i+1;
        //*(a_int_list)[i] = i+1; == a_int_list[0][0] = i+1;
        //cout << a_int_list[0][i]<<endl;
        *(a_int_list)[i] =i+1;
        cout << *(a_int_list)[i]<<endl;
        cout << a_int_list[i]<<endl;
     }
     cout << *(a_int_list)[a_count_-1] <<endl; // *(a_int_list)[a_count_] == 2차원 배열 값.
     cout << a_int_list[a_count_] <<endl; // a_int_list[a_count_] == 2차원 배열 주소값
}

int main(){
    int a_int_list[a_count][a_count]={};
    doublePointer(a_int_list,a_count);
}