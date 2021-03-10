#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long A=0, B=0, C=0,T=0;
int main(){
    cin>>A>>B>>C;
    int count=0;    
    if(C!=B) T = A/(C-B)+1;
    if(T<=0){
        cout<<-1;
    }else{
        cout<<T;
    }
}