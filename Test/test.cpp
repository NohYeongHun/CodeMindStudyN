/* 
  int N;
    int min=100000;
    int A=100000;
    int B=0;
    int cnt=0;
    cin>>N;
    vector<vector<int>> matrix(N, vector<int>(N));

    for(int i=0; i<N; i++){
        for(int j=0; j<2; j++){
            cin>>matrix[i][j]; // matrix[0][0]=1 [0][1]=4
        }
    }

    // cout<<"\n";
    //min 초기화
    for(int i=0; i<N; i++){
        if(min>=matrix[i][1]){
            min=matrix[i][1];
        }
    }
    cnt++;

        for(int i=0;i<N;i++){
            if(matrix[i][0]>=min && A>=matrix[i][1]){ //matrix
                A=matrix[i][1]; // A=7; 
                min=A; //min=7;
                cnt++; //cnt =2
            }
            A=100000;
        }
        // cout<<"min : " <<min<<"\n";
        // cout<<"cnt : "<<cnt<<"\n";
        cout<<cnt;
 */


/* 
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 숫자가 주어진다.
이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int N;
    int temp=0;
    cin>>N;
    vector<int> V(N);
    for(int i=0; i<N; i++){
        cin>>V[i];
    }
    sort(V.begin(),V.end());
    for(int i=0; i<N;i++){
        cout<<V[i]<<"\n";
    }
}



