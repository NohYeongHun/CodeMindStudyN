//boj.kr/1931
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 

*/


int N;
int cnt=0;
int main()
{   
    int min =0;
    cin.tie(NULL); 
    ios::sync_with_stdio(false);
    cin>>N;
    vector<pair<int,int>> T(N);
    for(int i=0; i<N;i++){
        cin>>T[i].second>>T[i].first;
    }
    // 정렬
    sort(T.begin(),T.end());
    for(int i=0;i<N;i++){
        if(T[i].second>=min){
            min=T[i].first;
            cnt++;
        }
    }
    cout<<cnt;
}
