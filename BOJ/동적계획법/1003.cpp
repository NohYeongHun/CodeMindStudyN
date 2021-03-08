/*
문제
다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
fibonacci(0)은 0을 출력하고, 0을 리턴한다.
fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때,
 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

출력
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

예제 입력{
    3 // 테스트케이스 수
    0
    1
    3
}
예제 출력{
    1 0
    0 1
    1 2
}
return값을 사용한 계산이아니라 함수의 호출을 통해 메모이제이션한 값을 가져온다.
  */
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int memo[40][2]{};
int n=0;
int temp=0;
int fibo(int n){
    if(n==0){
        if(memo[n][n]!=0) return memo[n][n] + memo[n][1];
        else{
            memo[n][n]=1;
            return memo[n][n]+memo[n][1];
        }
    }else if(n==1){
        if(memo[n][n]!=0) return memo[n][n]+memo[n][0];
        else{
            memo[n][n]=1;
            return memo[n][n]+memo[n][0];
        }
    }else{
        if(memo[n][0]!=0 || memo[n][1]!=0) return memo[n][0]+memo[n][1]; // fibo(n)값
        else{
            memo[n][0]=(fibo(n-1)-memo[n-1][1])+(fibo(n-2)-memo[n-2][1]);
            memo[n][1]=(fibo(n-1)-memo[n-1][0])+(fibo(n-2)-memo[n-2][0]);
            return fibo(n-1)+fibo(n-2);
        }
    }
}

int T=0;
int main(){
    cin>>T;
    vector<int> dp(T,0);
    for(int i=0; i<T; i++){
        cin>>dp[i];        
    }
    for(int i=0; i<T;i++){
        //fibo(dp[i]) == memo[dp[i]][0]+memo[dp[i]][1]
        temp=fibo(dp[i]); 
        cout<<temp-memo[dp[i]][1]<<" "<<temp-memo[dp[i]][0]<<"\n";
    }
  
}