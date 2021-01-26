#include <iostream>
using namespace std;
int main(){
    int A,B,C;
    int Sum, cnt=0;
    int X[10]={};
    int T[10]={};
    cin>>A>>B>>C;
         Sum = A*B*C; 
    for(int i=0;i<=9;i++){
        if(Sum!=0){ 
            X[i]=Sum%10; 
            cnt++;
        }
        Sum = Sum/10;
    }
    
    for(int i=0;i<=9;i++){
        for(int j=0; j<cnt;j++){
            if(X[j]==i){
                T[i]+=1;
            }
        }
    }

    for(int i=0;i<=9;i++){
        cout<<T[i]<<"\n";
    }
}
