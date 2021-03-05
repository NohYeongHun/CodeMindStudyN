    /* 
    v.erase(iter) 처럼 파라미터를 하나 받는 경우에는 벡터의 iter 위치의 인자를 삭제 합니다.
    v.erase(start, end) 처럼 파라미터를 두개 받는 경우에는 [start, end) 의 범위의 인자를 삭제 합니다.
    start 이상 end 미만

     */
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

int T=0;
long long result=0;
long long km[MAX+1];
long long cost[MAX+1];
void input(){
    cin>>T;
    for(int i=1; i<=T-1;i++){
        cin>> km[i];
    }
    for(int i=1; i<=T;i++){
        cin>> cost[i];
    }
}
long long answer(){
    int now=1;   
    int i=1,j=1;
    while(j<=T-1){
        if(cost[now]>cost[i+1]){
            result+=cost[now]*km[j];
            i=i+1;
            now=i;
            j=j+1;
        }
        else if(cost[now]<=cost[i+1]){
            result+=cost[now]*km[j];
            i=i+1;
            j=j+1;
        }
    }
    return result;
}
int main(){
    //입력
    input();
    cout<<answer();
}   

   
 /*  //로직
    money.erase(money.begin()+T-1);
    while(last_index!=0){
        for(auto i = money.begin(); i!=money.end(); ++i){
        last_index= i- money.begin(); //last_index 구하기
        }
        min_index= min_element(money.begin(),money.end())-money.begin(); //min_index 구하기
        for(int i=min_index;i<=last_index;i++){
        result += money[min_index]*km[i]; //결과값 구하기
        }
        if(last_index!=0) 
        {
            money.erase(money.begin()+min_index,money.begin()+last_index+1);
        }
        
    }
    cout<<result;
  */