/* 
문제
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.
 */
/* 
<math.h>
round(수)
double round_digit(double num, int d)
 { double t = pow(10, d - 1); return round(num * t) / t; }
round_digit(a1, 1)
 */
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;



int main(){
    cin>>N;
    int cnt=0;
    int idx=0;
    double first=0;
    int fincnt=0;
    int choicount=0;// 동일 최빈값 개수 세기
    int AS=0;
    vector<int> T(N,0);
    vector<int> out(4,0);
    vector<int> A(N,0);
    vector<int> S(N,0);
    //입력
    for(int i=0; i<N; i++){
        cin>>T[i];
    }
    sort(T.begin(), T.end());
    for(int i=0; i<N; i++){
        first+=T[i];
    }

    for(int i=0; i<N;i++){
        cnt++; 
        if(i==N-1||T[i]!=T[i+1]){ // 다음 변수랑 다르면 T[0]!=T[1]
            if(cnt==fincnt){
                fincnt=cnt;
                choicount++;
                if(choicount<=2){
                    AS=T[i];
                }
            }
            else if(cnt>fincnt){
                fincnt=cnt;
                AS=T[i];
                choicount=0;
                choicount++;
            }
            cnt=0;
        }
        
    }
    out[0]=round(first/N);
    out[1]=T[round(N/2)];
    out[2]=AS;
    out[3]=T[N-1]-T[0];
    for(int i=0; i<4; i++){
        cout<<out[i]<<"\n";
    }
    
}
