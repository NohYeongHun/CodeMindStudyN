#include <iostream>
using namespace std;
//미로 찾기
/*
미로 상자 구조 
0(갈수 있는 곳),
1(벽 또는 장애물),
2(먹이)
*/
/*
1. 오른쪽 벽에 막히기전까지 계속 오른쪽으로 가야함
(바로 밑에 먹이가 있어도 오른쪽으로 진행하고 있다면 먹지못함)
2. 오른쪽으로 이동할때 먹이를 만나면 벽이 없어도 9로 바꾸고 
무조건 종료
3. 오른쪽 벽에 부딪혔을때 밑에도 벽이있으면 종료
4. 오른쪽 벽에 부딪혔을때 밑에 벽이 없으면 밑으로 한칸 이동후 
다시 오른쪽 벽있는지 검사 후 이동
5. 밑으로 이동중 먹이를 만나면 9로 바꾸고 종료
(즉, 오른쪽으로 가다 먹이를 만날 수도있고 
밑으로 이동하다 먹이를 만날 수도 있음)

방향전환을 위한 배열.
int [][]direction={{-1,0},{0,-1}};
개미가 지나간곳은 9로 변경된다.
ant[x][y]
map[x][y]는 4가지 경우가 있다. 0, 1, 2, 9
if(map[x+1][y]=0||map[x+1][y]=2){
    ant[x][y]
}
map[x][y]=9;
*/
/*
개미의 초기위치
ant[2][2];
*/
/*조합, 그리디
오른쪽으로 쭉-> 벽만남 아래쪽으로 쭉
        int nextX = x + direction[0][0]; //X의 다음 좌표 값
        int nextY = y + direction[1][1]; //Y의 다음 좌표 값.
*/
int main(){
    int i,j;
    int cnt=0;//오른쪽, 아래쪽 상태 0,1
    int x=1,y=1; // 시작 좌표.(2,2)
    int direction[2][2] ={{1,0},{0,1}}; //1,0 => 오른쪽 0,1 =>아래
    int ant[10][10];
    int map[10][10]={};
    //미로 상자구조 입력(먹이, 위치)
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            cin>>map[i][j];
        }
    }
    cout<<endl;
    cout<<"map[y][x+2]: "<<map[y][x+2]<<endl;
    map[y][x]=9; //map[1][1]=9;
    //로직
    //계속오른쪽이 비었는지 체크해야됨.
    while(1){
        if(map[y][x+1]==0){
            map[y][x+1]=9;
            x=x+1;
        }else if(map[y][x+1]==1){
            if(map[y+1][x]==0){
                map[y+1][x]=9;
                y=y+1;
            }else if(map[y+1][x]==1){
                break;
            }else if(map[y+1][x]==2){
                map[y+1][x]=9;
                y=y+1;
                break;
            }
        }else if(map[y][x+1]==2){
            map[y][x+1]=9;
            x=x+1;
            break;
        }
    }
    cout<<"break;"<<endl;
    //정답 출력
     for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
     }
}
/* 성실한 개미 solution -1
#include <stdio.h>
int map[12][12];

void back(int r, int c)
{
	if(map[r][c] == 2)
	{
			map[r][c] = 9;
			return ;
	}
	map[r][c] = 9;

	if(map[r][c+1] != 1)
		back(r, c+1);
	else if(map[r+1][c] != 1)
		back(r+1, c);
}

int main()
{
	int i, j;
	for(i = 1; i <= 10; i++)
		for(j = 1; j <= 10; j++)
			scanf("%d", &map[i][j]);
	back(2, 2);

	for(i = 1; i <= 10; i++,puts(""))
		for(j = 1; j <= 10; j++)
			printf("%d ", map[i][j]);
}
*/
/* 성실한 개미 solution-2
#include <iostream>
using namespace std;
int main() 
{ 
    int map[10][10],x=1,y=1,i,j; 
    for(i=0;i<10;i++) 
        for(j=0;j<10;j++) 
            cin>>map[i][j];
    while(map[x][y]!=2) 
    { 
        map[x][y]=9; 
        if(map[x][y+1]!=1) y+=1; 
        else if(map[x+1][y]!=1) x+=1; 
        else break; 
    } 
    cout<<endl;
    map[x][y]=9; 
    for(i=0;i<10;i++) 
    { 
        for(j=0;j<10;j++) 
            cout<<map[i][j]<<" ";
        cout<<endl;
    } 
    return 0; 
}

*/

/* 모범소스 1
#include <stdio.h>
int map[12][12];

void back(int r, int c)
{
	if(map[r][c] == 2)
	{
			map[r][c] = 9;
			return ;
	}
	map[r][c] = 9;

	if(map[r][c+1] != 1)
		back(r, c+1);
	else if(map[r+1][c] != 1)
		back(r+1, c);
}

int main()
{
	int i, j;
	for(i = 1; i <= 10; i++)
		for(j = 1; j <= 10; j++)
			scanf("%d", &map[i][j]);
	back(2, 2);

	for(i = 1; i <= 10; i++,puts(""))
		for(j = 1; j <= 10; j++)
			printf("%d ", map[i][j]);
}
*/

/* 모범소스 2
#include<stdio.h> 
int main() 
{ 
    int map[11][11],x=2,y=2,i,j; 
    for(i=1;i<=10;i++) 
        for(j=1;j<=10;j++) 
            scanf("%d",&map[i][j]); 
    while(map[x][y]!=2) 
    { 
        map[x][y]=9; 
        if(map[x][y+1]!=1) y+=1; 
        else if(map[x+1][y]!=1) x+=1; 
        else break; 
    } 
    map[x][y]=9; 
    for(i=1;i<=10;i++) 
    { 
        for(j=1;j<=10;j++) 
            printf("%d ",map[i][j]); 
        printf("\n"); 
    } 
    return 0; 
}

*/