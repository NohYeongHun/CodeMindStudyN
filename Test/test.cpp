/* 



 */
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int T=0;
int min_index=0;
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
    cout << money.back();
/*     min_index = min_element(money.begin(), money.end()-1) - money.begin();
    cout<<min_index<<"\n";
    money.erase(money.begin()+min_index);
    min_index = min_element(money.begin(), money.end()-1) - money.begin();
    cout<<min_index; */

}
/* 
    while(money[0]!=0){
        min_index = min_element(money.begin(), money.end()-1) - money.begin();

    }
 */