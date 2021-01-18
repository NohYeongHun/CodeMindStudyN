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
ex) int x = isStub(a,b);
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
#include "AAA.h"
#include <string.h>

#define  a_count 5
using namespace std;
using namespace RCalc;
int a=0;
int b=0;
int z=0;
int w=0;
int m=5;
int n=5;

struct DStruct{ //구조체 선언
    int st;
    float ct;
    int getintStruct(){ return st; }
    int getfloatStruct(){ return ct; }
    void setintStruct(int stex){ st=stex; }
    void setfloatStruct(int ctex){ ct=ctex; }
};


class A{ // 클래스 체크
    private:
        int a;
        int b;
    public:
        A(int a, int b){
            this->a = a; // this 포인터 심볼 자동 생성
            this->b = b; 
            //this->a 멤버 a는 매개 변수
        }
        int getA(){return a;}
        void setA(int aa){ a=aa;}
        int getB(){return b;}
        void setB(int bb){ b=bb;}
        void printing(){
            cout <<this ->a <<endl;
            cout <<this ->b <<endl;  
        }   
        void ClassFunc(A at){ //클래스 심볼
            for(int i = 0; i<at.getA(); i++){
            for(int j = 0; j<at.getB(); j++){
            cout<<"* ";
        }
            cout<<"\n";
        }
    }
    protected:
        float z; // protected 필드 우회 접근
        float w;
};

template <typename S> // 템플릿 선언
S Mincheck(const int& lv, const int& rv){ //템플릿 사용
    return lv < rv ? lv : rv;
}

union UBox{ // Union 선언
    bool a;
    int x,y;
    int getUnionX(){ return x; }
    void setUnionX(int ex){ x = ex; }
    int getUnionY(){ return y; }
    void setUnionY(int ey){ y = ey; }
};

int FTest(int a, int b){ //int형 파라미터 심볼
    if(a >=b){ 
        return a;
    }else{
        return b;
    }
    
}

float FReturn(float a, float b){ //float 파라미터 심볼 생성
    RMulti Rm; //Namespace안의 class
    if(Rm.ResultMultiple(a,b)> a+b && Rm.ResultDivision(a,b) > a-b ){
        return Rm.ResultADD(a,b);
    }else{
        return (a+b)+(a-b);
    }
}

void setDStruct(struct DStruct p, int a, float b){ //구조체 파라미터
    if(p.getintStruct() == p.getfloatStruct()){
        cout<< "p.st == p.ct"<<endl;
        cout << p.getintStruct() <<endl;
        p.setintStruct(p.getfloatStruct()+1);
    }else{
        cout<< "not equal" << endl;
        cout <<"pst: " <<p.getintStruct() <<endl;
        cout <<"pct: " <<p.getfloatStruct() <<endl;
    } 
    
}

void UnionTest(UBox up,int a, int b){ // 공용체 테스트
    if(up.getUnionX() < b){
        up.setUnionX(b);
    }else{
        up.setUnionY(a);
    }
    
}

// 배열 포인터 선언
void PointerArray(int (*a_int_list)[a_count], int a_count_){
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

void FParam(int (*fp)(int ,int)){ //포인터 파라메터 심볼
    cout << a<<' '<<b <<endl;
}

void assign(int** arr, int m, int n) //이중 포인터
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = i + j;
        }
    }
}

int StubTest(int a, int b){ // 리턴값 심볼 자동 생성
int x = AStub(1,1);
    if(x > (a-b)){
        return x;
    }else if(x <= (a-b)){
        return a-b;
    }else{
        return -1;
    }
}

void arraylengthover(){ //array length over
    char data[5];
    for(int index=0; index<6; index++){
        data[index] = index;
    }
}

void dividezero(int a, int b){ //divide zero
    if(a/b < a){
        a = 0;
    }else{
        b = 0;
    }
}

void NullCheck(int a, int b){ //null check
    int *k;
    cout << *k << endl;
}


int main(){
    UBox u1;
    UnionTest(u1,3,2);
    cout << u1.getUnionX() << endl;
    /*-------*/
    FParam(FTest);
    float tt =FReturn(5,3);
    cout << tt <<endl;
    /*-------*/
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
    return 0;
}