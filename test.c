#include <stdio.h>
#include <math.h>

int main(){
   int x, y, w, h;
   scanf_s("%d %d %d %d",&x, &y, &w, &h);
   if(sqrt(x^2 +y^2) < sqrt((w-x)^2 +(h-y)^2)){
      if(x<y){
         printf("%d",x);
      }else if(x>y){
         printf("%d",y);
      }
   }else if(sqrt(x^2 +y^2) > sqrt((w-x)^2 +(h-y)^2)){
      if(w-x < h-y){
         printf("%d", w-x);
      }else if(w-x > h-y){
         printf("%d", h-y);
      }
   }

}