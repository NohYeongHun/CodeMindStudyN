#include <stdio.h>
#include <math.h>
#include <time.h>
/* 1. 상근이는 지금 사탕가게에 설탕을 정확히 N킬로그램 배달.
   2. 설탕공장에서 만든 설탕봉지는 3킬로그램 봉지와 5킬로그램 봉지존재.
   3. EX) 18킬로그램 설탕 배달시 3킬로그램 봉ㅈ6개를 가져가도 되지만,
   5킬로그램 3개와 3킬로그램 1개를 배달시 더 적은 개수 봉지 전달가능
   상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를
   가져가야 하는가?
   봉지의 최소개수 구하기.
   정확하게 N킬로그램 만들수 없으면 -1 출력.
*/
int main(){
   int N;
   int a=5;
   int b=3;
   int t1;
   int t2;
   int x;
   int NthreeVal;
   int NFiveVal;
   scanf_s("%d",&N);
   // /5 or /3 
   /* 값이 5보다 클경우? if(N>5){
      N%5 = temp;
      
   }
   if(temp>3){
      temp%3=x;
   }

   */
   if(N%3==0 && N%15!=0){
      t1 = N/3;
      printf("%d",t1);
   }else if(N%5==0 || N%15==0){
      t2 = N/5;
      printf("%d",t2);
   }else{
      NthreeVal = N/3;
      NFiveVal = N/5;
      printf("%d %d", NthreeVal, NFiveVal);
   }
      
}