/* 
1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

점화식-

메모이제이션-

n-1번째까지 최소값+ 빨강
n-1번째까지 최소값+ 초록
n-1번째까지 최소값+ 파랑
 */
/* 
빨강 = 0
초록 = 1
파랑 = 2


 */
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
int N, Solution;
int dp[1001][3];
int house[1001][3];
void In(){
    cin >> N;   
    for(int i=1; i<=N; i++){
        cin >> house[i][0]>>house[i][1]>>house[i][2];
    }
    dp[0][0] = dp[0][1] = dp[0][2] =0;
    house[0][0] = house[0][1] = house[0][2] = 0;
}
void Sol(){
    for (int i=1;i <= N; i++){
        dp[i][0] = MIN(dp[i-1][1],dp[i-1][2])+ house[i][0];
        dp[i][1] = MIN(dp[i-1][0],dp[i-1][2])+ house[i][1];
        dp[i][2] = MIN(dp[i-1][1],dp[i-1][0])+ house[i][2];
    }
    Solution = MIN(MIN(dp[N][0],dp[N][1]),dp[N][2]);
    cout<<Solution<<"\n";
}

void Solve(){
    In();
    Sol();
}
int main(){
    Solve();
}