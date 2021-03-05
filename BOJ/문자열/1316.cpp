/* 
a~z(97~122) ASCII코드
st1.length() : string의 길이를 반환
str1.size() : string의 사이즈를 반환    
alpabet[26]// true, false 판독
while(1){ 
if(tmp!=word[++i]) 
    i--;
    break;
}
word[i]는 알파벳임.
alpabet[word[i]-'a'] = true는
ex) word[0]='a'면 alpabet[97-97=0]=true
word[7]='b'면 alpabet[98-97=1]=true
현재 알파벳과 다른 알파벳이 올때까지 탐색
그러면서 i값을 1씩 올려줌.
다른 알파벳을 찾으면 i--;하고 for문의 시작점으로 돌아감.
if(alpabet[word[i]-'a']){
    return false;
}
다른 알파벳을 찾고 for문의 시작점으로 돌아왔을 때
그 알파벳이 이미 alpabet[26]배열 안에 들어 있으면 false 리턴
ex) alpabet[true,true,true...]
word = aabbaa라고 가정하면
word[1]=> alpabet[0]=true
word[3]=> alpabet[1]=true
word[5]=> alpabet[0]=true


*/
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;

int T=0;
string word[MAX+1];

void input(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>word[i];
    }
}

bool groupCheck(string word){
    bool alpabet[26]={false};

    for(int i=0; i<word.length();i++){
        cout<<"up i :"<<i<<"\n";
        if(alpabet[word[i]-'a']){ //true 이면 이미 있었으므로 false
            return false;
        }
        else{ //false 이면 처음 오는 알파벳 이므로 check
            char tmp = word[i];
            alpabet[word[i]-'a'] =true; //알파벳이 왔으면 true로 바꿔줍니다
            cout<<"check up tmp : "<<tmp<<"\n";
            while(1){
                cout<<"while i :"<<i<<"\n";
                if(tmp != word[++i]){  //현재 알파벳과 다른 알파벳이 올때까지 탐색합니다
                    cout<<"check i :"<<i<<"\n";
                    i--;
                    break;
                }
            }
        }
    }
    return true;
}

int main(){
    input();
    int count=0;    
    for(int i=1;i<=T;i++){
        if(groupCheck(word[i])){
            count++;
        }
    }
    cout<<count;
}
