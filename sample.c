// #include<stdio.h>

// int main(){
//     int N;
//     scanf("%d",&N);
//     int a=0;
//     int b=N/5;
//     int c=N%5;

//     if(c==0){
//         b=N/5;
//         printf("a+b = %d",a+b);
//     }else if(c==1 && b>=1){
//         b=N/5-1;
//         a=2;
//         printf("a+b = %d",a+b);
//     }else if(c==2 && b>=2){
//         b=N/5-2;
//         a=4;
//         printf("a+b = %d",a+b);
//     }else if(c==3){
//         b=N/5;
//         a=1;
//         printf("a+b = %d",a+b);
//     }else if(c==4 && b>=1){
//         b=N/5-1;
//         a=3;
//         printf("a+b = %d",a+b);
//     }else{
//         printf("%d", -1);
//     }
// }