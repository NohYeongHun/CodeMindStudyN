/*
알파벳을 숫자로 맵핑하고 알파벳은char []
char b[] => int a[]변경
int a[] 안에 원소들에 모두 2를더함
for(~@~@)
    a[i]=a[i]+2;
for(~@@)
    x+=a[i];
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    char ASC[26];
    for(int i=0; i<26; i++)
        ASC[i] = 'A'+i;
    cout<<ASC[0];
    int X;
  	char alpabet[]={
          'A','B','C',
          'D','E','F',
          'G','H','I',
          'J','K','L',
          'M','N','O',
          'P','Q','R','S',
          'T','U','V',
          'W','X','Y','Z',
          };
    int num[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    for(int i=0;i<26;i++){
        num[i]=num[i]+2;
    }
    string s;
    cin>>s;
    for(int i=0;i<26;i++){
        for(int j=0; j<s.size();j++)
            if(s[j] == alpabet[i]){
                X+=num[i];
                cout<<X<<"\n";
        }
           
    }

}