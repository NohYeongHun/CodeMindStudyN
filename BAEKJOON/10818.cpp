#include <iostream>
using namespace std;
int main() {
    int N;
    cin>>N;
    int *A;
    A = (int *)malloc(sizeof(int) * N);
    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int i=0; i<N;i++)
        cout<<A[i]<<" ";
}
