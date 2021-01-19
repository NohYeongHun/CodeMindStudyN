#include<stdio.h>

int main(){
    int N;
    int count = 0;
    scanf("%d",&N);

    if(N%5==0){
        count = N/5;
    }else if(N%5==1 && N/5>=1){
        count = N/5+1;
    }else if(N%5==2 && N/5>=2){
        count = N/5+2;
    }else if(N%5==3){
        count = N/5+1;
    }else if(N%5==4 && N/5>=1){
        count = N/5+2;
    }else{
        count =-1;
    }

    printf("%d", count);
}