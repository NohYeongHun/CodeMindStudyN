/*
해야될 것
int(o)/float(o)/구조체/공용체/배열/포인터 파라메터 심볼 생성 ex) (int a, int b)
함수 포인터 파라메터 생성 //(o)
void (*p_func)(int) =PrintValue; // p_func 변수 선언 PrintValue 함수 주소 대입
int add(int a, int b)
{
    return a + b;
}
//void executer(int (*fp)(int,int))
{
    printf("%d\n", fp(10,20));
}
int main()
{
    executer(add); // execuer 호출시 add 함수의 메모리 주소 전달

}
외부 라이브러리(헤더 파일)내 사용자 설정 함수(o) ex) int stub(int a, int b)
이중 포인터 구조체 파라메터 심볼 생성 ?? struct Person *p1; 
구조체 포인터= & 구조체 변수;
**p2 = &p1;

리턴값 심볼 자동 생성.(o)
클래스, 네임스페이스(o)
ex) int x = AStub(a,b);
if(x > 0){
    return 1;
}
x는 외부함수 리턴값으로 선언받아서 분기문에 들어가서 심볼화됨.
0으로 나누기 ex) 상수/0 divide zero (o)
배열 범위 초과 
ex) int arr[2] ={1,2};
if(arr[3] == 100){
return 1;
}
널 객체 필드 접근
클래스 심볼 생성
메소드 드라이버 자동 생성
사용자 드라이버/스텁 추가 기능
protected/private 필드 접근 우회 지원
템플릿 사용 지원
XLine *x = new XLine; // new 할당시 (포인터로 할당해줘야 컴파일)
    x->line1 = 1;
    cout << x->line1 <<endl;
*/
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "AAA.h"
#include <string.h>
using namespace std;
using namespace RCalc;
int a=0;
int b=0;
int z=0;
int w=0;
int Trray[5];

float FReturn(float a, float b){
    RMulti Rm;
    if(Rm.ResultMultiple(a,b)> a+b && Rm.ResultDivision(a,b) > a-b ){
        return Rm.ResultADD(a,b);
    }else{
        return (a+b)+(a-b);
    }
}

int FTest(int a, int b){ 
    if(a >=b){ 
        return a;
    }else{
        return b;
    }
    
}

int RTest(int a, int b){
    int x = AStub(a,b);
    if(x > (a-b)){
        return 1;
    }else if (x <=(a-b)){
        return 2;
    }else{
        return 3;
    }
}

void zeroTest(int a, int b){ //divide zero
    if(a/b < a){
        a = 0;
    }else{
        b = 0;
    }
}
void arrayTest(){ //array length over
    char data[5];
    for(int index=0; index<6; index++){
        data[index] = index;
    }
}


void FParam(int (*fp)(int ,int)){ //포인터 파라메터 심볼
    cout << a<<' '<<b <<endl;
}


struct DStruct{
    int st;
    int ru;
};


void StructTest(struct DStruct Dt){
    if(Dt.st > (a+b)){
        Dt.st = a;
    }else {
        Dt.ru = b;
    }
}

void assign(int** arr, int m, int n) //double pointer
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = i + j;
        }
    }
}
void NullCheck(int a, int b){
    int *k;
    cout << *k << endl;
}

union UBox{
    bool a;
    int x,y;
};

void UnionFunc(UBox* up){
    up->x = 10;
}

class A{
    public:
    int x=10, y=10;
};

void ClassFunc(A x){
    for(int i = 0; i<x.x; i++){
    for(int j = 0; j<x.y; j++){
        cout<<"*";
    }
        cout<<"\n";
    }
}

int main(){
    UBox u1;
    UnionFunc(&u1);
    cout << "UNION x value = "<<u1.x <<endl;
    /*-------*/
    FParam(FTest);
    float tt =FReturn(5,3);
    cout << tt <<endl;
    /*-------*/
    int m=5;
    int n=5;
    int **arr = (int **)malloc(m * sizeof(int *));
    for (int r =0; r < m; r++)
        arr[r] = (int *)malloc(n * sizeof(int));
    assign(arr, m,n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j];
        }
        cout <<endl;
    }
    for (int i = 0; i < m; i++)
        free(arr[i]); //이차원 배열 동적할당 해제
    free(arr); 

    // int *p = &a;
    // cout << *p <<endl;
    // Potr(&p);
    // cout << *p <<endl;
    return 0;
}