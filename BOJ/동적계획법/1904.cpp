/* 

입력
첫 번째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 1,000,000)

출력
첫 번째 줄에 지원이가 만들 수 있는 길이가 N인 모든 2진 수열의 개수를 
15746으로 나눈 나머지를 출력한다.
ex) N=1 1
2 / 00 11 ,2
3 / 100 001 111 3
4 / 0011 1001 1100 1111 0000 ,5
5 / 10000 00100 00001 11100 00111 11111 ,8
 */
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
#define MOD 15746
using namespace std;

int N=0;
int DP[MAX];
int tile(int n){
    if(n==1){
        if(DP[n]!=0) return DP[n];
        else{ 
        DP[n]=n;
        return DP[n];
        }
    }else if(n==2){
        if(DP[n]!=0) return DP[n];
        else{ 
        DP[n]=n;
        return DP[n];
        }
    }else{
        if(DP[n]!=0) return DP[n];
        else{ 
        DP[n]=(tile(n-1)+tile(n-2))%MOD;
        return (tile(n-1)+tile(n-2))%MOD;
        }
    }
}
int main(){
    cin >> N;
    cout<<tile(N);
}
