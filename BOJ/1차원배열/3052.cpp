#include <iostream>
using namespace std;
int main(){
    int num[10];
    int x[10];
    int t=0,cnt=10; 
    int i,j;
    for(i=0;i<10;i++)
        cin>>num[i];
    for(i=0;i<10;i++)
        num[i]=num[i]%42;
    for(i=0;i<10;i++){
            t=num[i];
        for(j=i+1;j<10;j++){ 
                if(t==num[j]){
                   cnt--;
                   break;
                }
            }
        }
    cout<<cnt;
}
