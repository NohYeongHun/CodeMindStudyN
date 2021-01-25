#include <stdio.h>
int main(){
   int n, i, j, x, y;
   int a[19][19]={0,}; //19*19 바둑판
   int b[19]={0,}; //가로
   int c[19]={0,}; //세로
    // for(i=0;i<19;i++)
    //     for(j=0;j<19;j++)
    //         scanf_s("%d",a[i][j]);
    scanf_s("%d",&n);
    for(i=0;i<n;i++){
        scanf_s("%d %d",&x,&y);
        b[x]=(b[x]+1)%2;
        c[y]=(c[y]+1)%2;
    }
    printf("%d %d",b[x],c[y]);
    
}