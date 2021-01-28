#include <iostream>
using namespace std;
int main(){
    int A,B,C;
    int Sum, cnt=0;// Sum의 자리수.
    int X[10]={};// 개수 배열
    int T[10]={};// 출력 배열
    cin>>A>>B>>C; //입력
    Sum = A*B*C; //곱한 값.
    cout<<"Sum : "<<Sum<<"\n";
    for(int i=0;i<=9;i++){
        if(Sum!=0){ 
            X[i]=Sum%10; 
            cnt++;
        }
        Sum = Sum/10;
    }
    cout<<"cnt: "<<cnt<<"\n";
    //로직
    for(int i=0;i<=9;i++){
        cout<<"X["<<i<<"]: "<<X[i]<<"\n";
        for(int j=0; j<cnt;j++){
            if(X[j]==i){
                T[i]+=1;
            }
        }
    }

    // 출력
    for(int i=0;i<=9;i++){
        cout<<"T["<<i<<"]: "<<T[i]<<"\n";
    }
}

/*
번외 풀이
#include<stdio.h>
int a,b,c,x[10],i;
main(){
	scanf("%d%d%d",&a,&b,&c);
	a*=b*c;
	while(a){
		x[a%10]++;
		a/=10;
	}
	for(i=0;i<10;i++)printf("%d\n",x[i]);
}
*/
