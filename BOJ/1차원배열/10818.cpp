#include <iostream>
using namespace std;
int main() {
    int n;
    int max,min;
    cin>>n;
    int *a= new int[n];   
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    min=a[0];
    max=a[0];
    for(int i=1; i<n;i++){
        if(a[i]<min) min=a[i];
        if(a[i]>max) max=a[i];
    }
    delete []a;
    cout<<min<<' '<<max;
    return 0;
}