/* 
a~z(97~122) ASCII코드
st1.length() : string의 길이를 반환
str1.size() : string의 사이즈를 반환    
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
        if(alpabet[word[i]-'a']){ //true 이면 이미 있었으므로 false
            return false;
        }
        else{ //false 이면 처음 오는 알파벳 이므로 check

            char tmp = word[i];
            alpabet[word[i]-'a'] =true; //알파벳이 왔으면 true로 바꿔줍니다
            while(1){
                if(tmp != word[++i]){
                    i--;
                    break;
                }
            }
        }
    }
    return true;
}

int main(){
    int count=0;    
    input();
    for(int i=1;i<=T;i++){
        if(groupCheck(word[i])){
            count++;
        }
    }
    cout<<count;
    
    
}