#include <iostream>
using namespace std;

int main(){
    int N;
    double avg,sum=0,max=0;
    int i;
    cin>>N;
    double *jum=(double *)malloc(sizeof(double) * N);
    for(i=0;i<N;i++){
        cin>>jum[i];
        if(max<jum[i])
            max=jum[i];
        sum+=jum[i];
    }
    sum=(sum/max)*100;
    avg=sum/N;
    cout<<avg;
    free(jum);
}