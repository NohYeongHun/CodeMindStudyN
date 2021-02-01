#include <iostream>
using namespace std;
int main() {
    int N[9];
    int MAX,cnt=0,result;
    for(int i=0; i<9;i++){
        cin>>N[i];
    }
    MAX=N[0];
    for(int i=0; i<9;i++){
        cnt++;
        if(MAX<N[i]){ 
            MAX=N[i]; result=cnt;
            }
    }
    cout<<MAX<<"\n"<<result; 
}