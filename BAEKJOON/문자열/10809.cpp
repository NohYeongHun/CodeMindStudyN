#include <iostream>
using namespace std;
/*
알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서,
단어에 포함되어 있는 경우에는 처음 등장하는 위치를,
포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

각각의 알파벳에 대해서, 
a가 처음 등장하는 위치, 
b가 처음 등장하는 위치, 
... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.
만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 
단어의 첫 번째 글자는 0번째 위치이고,
 두 번째 글자는 1번째 위치이다.
*/
 int main()
{   
    char a[26];
    int t[26]={};
    fill_n(t,26,-1);
    for(int i=0; i<26; i++)   //아스키 코드 사용
    a[i] = 'a'+i; 
    char baek[100]={};
    cin>>baek;
    for(int i=0; i<26;i++){
        for(int j=0; j<sizeof(baek)/sizeof(char);j++){
            if(a[i]==baek[j]){ // ex) a[0]==baek[1]이랑 같으면 t[i]=1;
            //    a[i]=' '; // a[i]값을 뺀다.
                t[i]=j;   //t[i]배열에 j값을 넣어줌. j=0~100
                if(t[i]!=-1){
                    break;
                }
            }
        }
        cout<<t[i]<<" ";
    }
}

