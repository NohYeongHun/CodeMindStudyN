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
