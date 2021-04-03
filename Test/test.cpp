#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> food_times;
int n;
int food;
long long sum=0;
long long k;
void input(){
    cin>>n;
    cin>>k;
    for(int i=0; i<n;i++){
        cin>>food;
        sum+=food;
        food_times.push_back(food);
    }
}
//  vec.erase(vec.begin()+3); // 세 번째 인덱스 원소 제거.
int solution(vector<int> food_times, long long k) {
    int answer = 0; //현재 음식의 위치
    int i=0;
    if(k>=sum) return -1;
    vector<pair<int,int>> que;
    for(int i= 0; i<n; i++){
        que.push_back(make_pair(food_times[i],i+1));
    }
    long long sum_value =0;
    long long previous =0;
    int length = food_times.size();
    
    while(sum_value +((que[0].first - previous)* length)<=k){
        int now = que[0].first;
    }

    return answer;
}
int main(){
    input();
    cout<<solution(food_times,k);

}