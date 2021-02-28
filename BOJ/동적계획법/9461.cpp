#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 
2 테스트 케이스 개수
1,1,1,2,2,3,4,5,7,9
점화식 만들기 => 메모이제이션
fado(n)= fado(n-1)+fado(n-5)
 */
int T=0;
int N=0;
long long int dp[101]={0,1,1,1,2,2};
long long int fado(int n){
    if(n<=5)  return dp[n];
    if(n>=6){
        if(dp[n]!=0) return dp[n];
        else{
        dp[n]= fado(n-1)+fado(n-5);
        return fado(n-1)+fado(n-5);
        }
    }
};

int main(){
    cin>>T;
    for(int i=0; i<T;i++){
        cin>>N;
        cout<<fado(N)<<"\n";
    }
}