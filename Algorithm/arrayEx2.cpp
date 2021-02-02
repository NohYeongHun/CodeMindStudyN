#include <iostream>
using namespace std;
/*
모든 막대를 놓은 격자판의 상태를 출력한다.
막대에 의해 가려진 경우 1, 아닌 경우 0으로 출력한다.
단, 각 숫자는 공백으로 구분하여 출력한다.
*/
int main(){
    int w,h,n;//격자판 세로, 가로, 막대 개수
    int l,d; // 길이 l, 방향 d={0,1} d=0이면 가로 1이면 세로방향으로 뻗음.
    int x,y;
    int i,j;
    int field[100][100]={};
    cin>>w>>h;
    cin>>n;
    //field 0으로 초기화.
    for(i=0;i<w;i++){
        for(j=0;j<h;j++){
            field[i][j]=0;
        }
    }

    for(i=0;i<n;i++){
        cin>>l>>d>>x>>y;
        if(d==0){
        for(int k=0;k<l;k++)
                field[x-1][y-1+k]=1;
        }else{
        for(int k=0;k<l;k++)
            field[x-1+k][y-1]=1;
        }
    }

    for(i=0;i<w;i++){
        for(j=0;j<h;j++){
            cout<<field[i][j]<<" ";
        }
        cout<<endl;
    }
    
    /*
            if(d=0) // 만약 l이 3이라면
            field[x-1][y-1]=1 , field[x-1][y]= 1, field[x-1][y+1]=1

            if(d=0){
                for(i=0;i<l;i++){
                    field[x-1][y-1+i]=1;
                }
            }
    */
}