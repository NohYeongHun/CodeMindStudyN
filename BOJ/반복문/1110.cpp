#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int a,b;
    int x=n,cycle=0;
    while(true){
        a = n/10 + n%10;
        b = (n%10)*10 + (a%10);
        n =b;
        cycle +=1;
        if(n==x){
            break;
        }
    }
    cout<<"cycle : "<<cycle;
}