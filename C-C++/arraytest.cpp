#include <string.h>
#include <iostream>
using namespace std;

void arrayTest(int i){ // i값에 -를 주니까.. ?? 오류.
    int data[5];
    for(int index=0; index<i+2; index++){
        data[index] = index;
        cout << data[index] <<endl;
    }
}

void arrayTest2(){ //배열 길이초과
    char data[5];
    for(int index=0; index<6; index++){
        data[index] = index;
        cout << data[index] <<endl;
    }
}

// union UBox{
//     bool a;
//     int x,y;
// };


// void UnionFunc(UBox* up){
//     up->x = 10;
// }
<<<<<<< HEAD:arraytest.cpp

//

// 클래스 심볼  parameter 클래스

=======
//

// 클래스 심볼  parameter 클래스
    //UBox u1;
     //UnionFunc(&u1);
    // cout << u1.x <<endl;
    // int i = 0;
    //arrayTest(i);
>>>>>>> Nbranch:C-C++/arraytest.cpp


// 클래스 심볼  parameter 클래스
int main(){
    // UBox u1;
    // UnionFunc(&u1);
    // cout << u1.x <<endl;
    int i = 0;
    arrayTest(i);
<<<<<<< HEAD:arraytest.cpp

=======
>>>>>>> Nbranch:C-C++/arraytest.cpp

    // altx(5,5.5);
    // abc();
    // int *p;
    // abc(&p);
    return 0;
}
