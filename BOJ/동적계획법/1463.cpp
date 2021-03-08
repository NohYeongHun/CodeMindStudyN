/*

*/
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000+1

long long dp[MAX];
long long N=0;

int minCalc(int n){
    if(n==1){
        dp[1]=0;
        return 0;        
    }
    else if(dp[n]!=0)  return dp[n];
        else{
        if(n%6==0){
            dp[n]=min(min(minCalc(n/3),minCalc(n/2)),minCalc(n-1))+1;
            return dp[n];
        }
        else if(n%3==0){
            dp[n]=min(minCalc(n/3),minCalc(n-1))+1;
            return dp[n];
        }else if(n%2==0){
            dp[n]=min(minCalc(n/2),minCalc(n-1))+1;
            return dp[n];
        }else{
            dp[n]=minCalc(n-1)+1;
            return dp[n];
        }
    }
}
int main(){
    cin>>N;
    cout<<minCalc(N);
}