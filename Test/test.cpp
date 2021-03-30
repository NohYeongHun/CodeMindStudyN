//boj.kr/1541
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string calc;
void Input(){
    cin>>calc;
}
int main()
{       
    bool check =false;
    string temp="";
    int result =0;
    Input();
    for(int i=0; i<=calc.size();i++){
        if(calc[i]=='+'||calc[i]=='-'||calc[i]=='\0')
        {
            if(check){
                result -=stoi(temp);
            }
            else{
                result +=stoi(temp);
            }
            temp="";
            if(calc[i]=='-')
                check = true;
            continue;
        }
        temp+=calc[i];
    }
    cout<<result;
}