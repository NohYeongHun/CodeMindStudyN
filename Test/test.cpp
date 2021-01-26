#include <iostream>
using namespace std;
#define MAX_DIGITS 10
int main() {
    int A,B,C;
    int Multiple;
    int N[9];
    int T[10]={0};
    cin>>A>>B>>C;
    Multiple=A*B*C;
    cout<<Multiple<<"\n";
    for(int i=0;i<9;i++){
        N[i]=Multiple%10;
        Multiple/=10;
    }
    for(int i=0;i<9;i++){
        cout<<"N["<<i<<"]: "<<N[i]<<"\n";
        // if(N[i]==i){ 
        //     T[i]+=1;
        // }
    }

    
}
