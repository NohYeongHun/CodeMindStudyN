/* 
버블 정렬, 시간복잡도 O(n^2)
why? => 한번 반복시마다 집합의 크기가 1씩 줄어든다. => N + (N-1) + .... 0 => N(N-1)/2 => O(n^2)

 */
#include <iostream>
using namespace std;
#define MAX 10000

int N;
int array[MAX+1];
int i,j;   

// 정렬의 기본이되는 함수 인수 두개의 위치를 바꿔줌.
void *swap(int &arr1, int &arr2){
    int temp =0;
    temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
}
void solve(){
    for(int i=0; i<N;i++){
        for(int j=0;j<N-1;j++){ 
            if(array[j]> array[j+1]){ // 왼쪽 인덱스의 값이 오른쪽 인덱스의 값보다 클 경우 
                swap(array[j],array[j+1]);  // 위치를 바꿔준다.
            }
        }
         // 가장 작은값을 찾았으면 기존비교 대상과 위치를 바꿔줌.
    }
}
int main()
{   
    input();
    solve();
    for(int i=0; i<N;i++){
        cout<<array[i]<<" ";
    }
}