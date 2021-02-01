#include <iostream>
using namespace std;
/*
문제:
수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다.  
입력:
첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다.
    이 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다.
출력:
첫째 줄에, 42로 나누었을 때, 
서로 다른 나머지가 몇 개 있는지 출력한다.
내 로직 = 중복된 개수를 찾고 최대 개수에서 뺀다.
*/

int main(){
    int num[10];
    int x[10];
    int t=0,cnt=10; //최소 1 최대 10
    int i,j;
    //입력
    for(i=0;i<10;i++)
        cin>>num[i];
    /*
    num[i]와 num[j+1]을 비교 즉 num[0]과num[1~9]비교 => num[1]과 num[2~9]비교
    */
    //로직
    for(i=0;i<10;i++)
        num[i]=num[i]%42;
    for(i=0;i<10;i++){
            t=num[i];
        for(j=i+1;j<10;j++){ //45번 비교 0 = 1~9 1 = 2~8
                if(t==num[j]){
                   cnt--;
                   break;
                }
            }
        }
    for(int i=0;i<10;i++)
        cout<<"num["<<i<<"] : "<<num[i]<<"\n";

    //출력
    cout<<"cnt : "<<cnt<<"\n";
}

/* 
다른 답안
#include <iostream>
using namespace std;
int main(){
    int num[42]={},a=0,i,j,x;
    for(i=0;i<10;i++)// 입력
        cin>>x,num[x%42]++; // num[x%42]++ == num[x%42]=num[x%42]+1
        x%42가 인덱스로 들어가고. num[x%42]에는 1의 값이 저장됨.
    for(i=0;i<42;i++)
        if(num[i]) a++; //num[i]가 1이면 a++;
        cout<<a;
}
*/