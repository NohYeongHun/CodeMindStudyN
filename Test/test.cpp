#include <iostream>
using namespace std;
int main(){
    int x=1,y=1; // 시작 좌표.(2,2)
    int map[10][10]={};
    //미로 상자구조 입력(먹이, 위치)
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>map[i][j];
        }
    }
    cout<<endl;
    //로직
    //계속오른쪽이 비었는지 체크해야됨.
    while(map[x][y]!=2)
    {
        map[x][y]=9; //default (2,2)=9
        if(map[x][y+1]!=1) y+=1; //map[x][y+1]==1이면 else if 실행 
        else if(map[x+1][y]!=1) x+=1; //map[x+1][y]==1이면 break;
        else break;
    }
    map[x][y]=9;
    //정답 출력
     for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
     }
}