/*
선택정렬 , 시간복잡도 O(n^2) 
why? = > 한번 반복시마다 집합의 크기가 1씩 줄어든다. => n+(n-1)+ ... 0 => n(n-1)/2 => O(n^2)
  */ 
#include <iostream>
using namespace std;
#define MAX 10000

int N;
int array[MAX+1];
int i,j; 

int index =0;
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
        int min_index = i; // 맨 앞 인덱스부터 최소값 비교
        for(int j=i+1;j<N;j++){ 
            if(array[j]< array[min_index]){ // 지정된 인덱스의 다음 인덱스부터 대소비교.
                min_index = j;    // min_index 보다 작으면 min_index 자리에 해당 인덱스를 넣어줌.
            }
        }
        swap(array[i],array[min_index]); // 가장 작은값을 찾았으면 기존비교 대상과 위치를 바꿔줌.
    }
}
int main()
{   
    input();
    solve();
    for(int i=0; i<N;i++){
        cout<<array[i];
    }
}