#include <iostream>
using namespace std;
int main(){
    long long int m,a,b,n;
    cin>>a>>b>>n;
    for(m=1;m<n;m++){
        a=a*b;
    }
    cout<<a;
}