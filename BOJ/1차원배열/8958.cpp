#include<iostream>
#include<string>
using namespace std;
int main(){
    int T,i,j,x=0;
    string text;
    cin>>T;
    int *jum = new int[T]();
    for(i=0;i<T;i++){
        x=0;
        cin>>text;
        for(j=0;j<text.size();j++){
            text[j] =='O' ? jum[i]+= ++x : x=0;
        }
    }
    for(i=0;i<T;i++){
        cout<<jum[i]<<"\n";
    }
    delete[] jum;
}

/*
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
    //입력
    int T,i,j,x=0,*jum;
    string text;
    cin>>T;
        jum=(int *)malloc(sizeof(int)*T);
        memset(jum,0,sizeof(int)*T);
    //로직
    for(i=0;i<T;i++){
        x=0;
        cin>>text;
        for(j=0;j<text.size();j++){ 
            if(text[j]=='O'){
                x=x+1;
                jum[i]+=x;
            }else { x=0;}
        }
    }
    //출력
    for(i=0;i<T;i++){
        cout<<jum[i]<<"\n";
    }
    free(jum);
}
*/