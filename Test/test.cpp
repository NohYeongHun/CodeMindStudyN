    /* 
    v.erase(iter) 처럼 파라미터를 하나 받는 경우에는 벡터의 iter 위치의 인자를 삭제 합니다.
    v.erase(start, end) 처럼 파라미터를 두개 받는 경우에는 [start, end) 의 범위의 인자를 삭제 합니다.
    start 이상 end 미만

     */
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int T=0;
int min_index=0;
int last_index=0;
int result=0;
int main(){
    cin>>T;
    vector<long long int> km(T-1,0);
    for(int i=0; i<T-1;i++){
        cin>> km[i];
    }
    vector<long long int> money(T,0);
    for(int i=0; i<T;i++){
        cin>> money[i];
    }
    money.erase(money.begin()+T-1);
    last_index = T-2;
    while(last_index!=0){
        for(auto i = money.begin(); i!=money.end(); ++i){
        last_index= i- money.begin(); //last_index 구하기
        }
        min_index= min_element(money.begin(),money.end())-money.begin(); //min_index 구하기
        for(int i=min_index;i<=last_index;i++){
        result += money[min_index]*km[i]; //결과값 구하기
        }
        money.erase(money.begin()+min_index,money.begin()+last_index+1);
    }
    cout<<result;
} 
   
  /*   min_index= min_element(money.begin(),money.end())-money.begin();
    cout<<last_index<<"\n"<<min_index<<"\n";
    for(int i=min_index;i<=last_index;i++){
        result += money[min_index]*km[i]; 
        cout<<"result : "<<result<<"\n";
    }
    money.erase(money.begin()+min_index,money.begin()+last_index);
    min_index= min_element(money.begin(),money.end())-money.begin();
    last_index=0;
    cout<<min_index<<"\n";
    cout<<result; */
    
    // money.erase(money.begin(),money.begin()+3);
    // cout<<money.front();
/*     min_index = min_element(money.begin(), money.end()-1) - money.begin();
    cout<<min_index<<"\n";
    money.erase(money.begin()+min_index);
    min_index = min_element(money.begin(), money.end()-1) - money.begin();
    cout<<min_index; */

/* 
    while(money[0]!=0){
        min_index = min_element(money.begin(), money.end()-1) - money.begin();

    }
 */