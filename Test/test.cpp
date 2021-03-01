/* 
1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

점화식-

메모이제이션-

 */
/* 
빨강 = 0
초록 = 1
파랑 = 2

if(n==1){
        if(dp[n]!=0) return dp[n];
        else{
            if(house[n][0]<house[n][1]){
                if(house[n][0]<house[n][2]){
                    dp[n] = 0;
                    return 0;
                }else{
                    dp[n] = 2;
                    return 2;
                }
            }else{
                if(house[n][1]<house[n][2]){
                    dp[n] = 1;
                    return 1;
                }else{
                    dp[n] = 2;
                    return 2;
                }
            }
        }
    }

else if(n>=2){
        if(dp[n]!=0) return dp[n];
        else{
            if(RGB(n-1)==0){
                if(house[n][1]<house[n][2]){
                    dp[n] = 1;
                    return 1;
                }else{
                    dp[n] = 2;
                    return 2;
                }
            }else if(RGB(n-1)==1){
                if(house[n][0]<house[n][2]){
                    dp[n] = 0;
                    return 0;
                }else{
                    dp[n] = 2;
                    return 2;
                }
            }else{
                if(house[n][0]<house[n][1]){
                    dp[n] = 0;
                    return 0;
                }else{
                    dp[n] = 1;
                    return 1;
                }                
            } 
        }
    }

 */
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N=0;
int dp[1001]={0,};
int house[1001][4]={0,};
int RGB(int n){
    int temp =0;
    if(dp[n]!=0) return dp[n];
    else{

    }   
}   

int main(){
    cin>>N;
    int tem=0;
    for(int i=1; i<=N;i++){
        cin>>house[i][1]>>house[i][2]>>house[i][3];
    }
}