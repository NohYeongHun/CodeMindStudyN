#include <iostream>
#include <stdlib.h>
using namespace std;
/* 매개 변수에 a_str_list[][]라고 적으면 안되나요??
ex) char(*ap_str_list)[]; == (불가능)
=======
#include <cstdlib>
using namespace std;
/* 매개 변수에 a_str_list[][]라고 적으면 안
>>>>>>> main
why? => char(*ap_str_list)[16]이라고 적을 경우 ap_str_list는 
char[16]이라는 대상을 가리킨다는 뜻이 되어 다음 대상이 16바이트 뒤에
있다는 것을 알 수 있지만 char(*ap_str_list)[]라고 적을 경우 대상의 크기가
char[]가 되어 크기를 예상할 수 없어서 오류 발생.
동적할당의 경우에는 2차원 배열 **int a_list 이런식으로 매개변수를 넘길 수 있음
ex) void(**int a_list){
<<<<<<< HEAD

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
#define  a_count 5

void doublePointer(int (*a_int_list)[a_count], int a_count_){ //(*a_int_list) -> &(a_int_list[0][index])
/* 
a_int_list[a_count][a_count]
*/
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
// call by reference  
// 배열 포인터(*a_int_list)[a_count] 
// != 포인터 배열 *(a_int_list)[a_count]
// a_int_list[1][0] = 10; //a_int_list[1][0] == (*a_int_list[1])
    // cout<<"[1]address : "<<a_int_list[1] << endl;
    // cout<<"aaa : "<< (*a_int_list[1]) <<endl; 
    // cout<<"xxx : "<< a_int_list[1][0]<<endl; 
    // cout<<"ddd : "<<(*a_int_list)[1]<<endl; 
    // cout<<"CCC : "<<a_int_list[0][1] <<endl; 
//call by reference랑 call by value가 혼합되있음. 상기 함수에서 주소값은 call by value이나 주소가 가리키는 값은 call by value형식이다.

#define  a_count 5

void PointerArray(int (*a_int_list)[a_count], int a_count_){ //(*a_int_list) -> &(a_int_list[0][index]) //질문
    int i=0;    
    for (i =0; i<a_count_; i++){ 
        (*a_int_list)[i] =i+1;
        cout << (*a_int_list)[i]<<endl; // 값
        cout << a_int_list[i]<<endl; // 주소값
    }
    

    if ((*a_int_list)[i-1] !=0){
        cout <<"i : "<< i<<endl;
        cout<< "a_int_list[0][i] not null" << endl; 
        cout << a_int_list[0][4] << endl;
    }
     
}

void DoublePointer(int **doublearray, int size){
    doublearray = (int**)malloc(sizeof(int*)*a_count);
    int* arr = (int*)malloc(sizeof(int)*a_count);
       for(size=0;size<a_count;size++){
        doublearray[size] = (int*)malloc(sizeof(int)*a_count);
    }
    for(size =0; size<a_count; size++){
        doublearray[size][size] = size;
    }
    if(doublearray[size-1][size-1]!=0){
        cout << "doublearray not null"<< endl;
    }
}

void DoubleTest(int **arr, int i){
    if(arr[i][i]!=0){
        cout<< "end"<<endl;
    }else{
        cout<<arr[i][i]<<endl;
    }
}


int main(){
    int a_int_list[a_count][a_count]={};
    PointerArray(a_int_list,a_count);
    /*2차원 배열 동적할당 필요조건 더블포인터 
    배열을
    */
    // int b_int_list[][] = malloc()
    // cout << a_int_list[0][1] << endl;
    int* arrarr;
    DoublePointer(&arrarr,a_count);
 
}