#include <string.h>
#include <iostream>
using namespace std;

class A{
    private:
        int a;
        int b;
    public:
        A(int a, int b){
            this->a = a;
            this->b = b;
            //this->a 멤버 a는 매개 변수
        }
        void printing(){
            cout <<this ->a <<endl;
            cout <<this ->b <<endl;  
        }   
        void ClassFunc(A at){ //클래스 심볼
            for(int i = 0; i<at.a; i++){
            for(int j = 0; j<at.b; j++){
            cout<<"* ";
        }
            cout<<"\n";
        }
    }
    protected:
        float z;
        float w;
};





//<>안에는 타입
int main(){
    A xA(5,5); //private 값 접근
    xA.ClassFunc(xA); // 클래스 심볼 생성
    cout << Min(10,20)<<endl;
    return 0;
}