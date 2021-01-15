//구조체 테스트
// &p->st == &p
#include<iostream>
using namespace std;

int a = 5;
float b = 10.0;
struct DStruct{
    int st;
    float ct;
};

void setDStruct(struct DStruct p, int a, float b){
    p.st =a;
    p.ct =b;
    if(p.st == p.ct){
        cout<< "p.st == p.ct"<<endl;
        cout << p.st <<endl;
    }else{
        cout<< "not equal" << endl;
        cout <<"pst: " <<p.st <<endl;
        cout <<"pct: " <<p.ct <<endl;
    } 
    
}

int main(){
    // DStruct Dt;
    // StructTest(Dt, a,b);
    // cout<< Dt.st << endl;
    struct DStruct d1;
    setDStruct(d1,a,b);
    cout << d1.ct <<endl;
    cout << "set st : "<< a <<endl;
    cout << "set ct : "<< b <<endl;
    return 0 ;
}