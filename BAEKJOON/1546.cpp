#include <iostream>
using namespace std;
/*
문제
세준이는 기말고사를 망쳤다. 
세준이는 점수를 조작해서 집에 가져가기로 했다.
 일단 세준이는 자기 점수 중에 최댓값을 골랐다. 
 이 값을 M이라고 한다. 그리고 나서 모든 점수를 점수/M*100으로 고쳤다.

예를 들어, 세준이의 최고점이 70이고, 수학점수가 50이었으면 
수학점수는 50/70*100이 되어 71.43점이 된다.

입력
첫째 줄에 시험 본 과목의 개수 N이 주어진다. 
이 값은 1000보다 작거나 같다.
 둘째 줄에 세준이의 현재 성적이 주어진다. 
 이 값은 100보다 작거나 같은 음이 아닌 정수이고, 
 적어도 하나의 값은 0보다 크다.

 출력
 첫째 줄에 새로운 평균을 출력한다. 
 실제 정답과 출력값의 절대오차 또는 상대오차가 10-2 이하이면 정답이다.
*/

int main(){
    int N; //과목 수    
    double avg,sum=0,max=0; // 점수 저장 배열
    int i,j;
    //입력
    cin>>N;
    double *jum=(double *)malloc(sizeof(double) * N);
    //로직
    for(i=0;i<N;i++){
        cin>>jum[i];
        if(max<jum[i])
            max=jum[i];
        sum+=jum[i];
    }
    sum=(sum/max)*100;
    // for(i=0;i<N;i++){
    //     if(max<jum[i])
    //         max=jum[i];
    // }
    // for(i=0;i<N;i++){
    //     jum[i]=(jum[i]/max)*100;
    //     sum=sum+jum[i];
    // }
    avg=sum/N;
    //출력
    cout<<avg;
    free(jum);
}

/* 다른 예시
#include <iostream>
using namespace std;

int main(){
    int N; //과목 수    
    double avg,x,M; // 점수 저장 배열
    cin>>N;
    for(int i=0; i<N;i++)
    {
        cin>>x; avg+=x; if(x>M){M=x;}
    }
    avg/=N;
    cout<<100*avg/M;
}
*/