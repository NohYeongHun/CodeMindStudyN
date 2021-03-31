/* 
삽입정렬
최악의 경우 => 시간복잡도 O(n^2) N + (N-1) .. .. 0 
일반적인 경우에 삽입정렬이 버블과, 선택정렬과 비교해서 가장 적게 연산한다.
삽입정렬이 최악의 경우 => 10,9,8,7,6,5,4,3,2,1
거의 정렬된 상태라면 가장 효율적임.
ex) 2 3 4 5 6 7 8 9 10
 */
#include <iostream>
using namespace std;
#define MAX 10000

int N;
int array[MAX+1];

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
    int j = 0;
    for(int i=0; i < N-1; i++){ // j와 j+1의 대소비교를 해서 위치를 바꾸므로 N-1까지만 비교하면 된다.
        j=i; // j=0부터 시작.
        while(array[j]>array[j+1]){ // array[j]> array[j+1]이면 둘의 위치를 바꾸고 array[j] <=array[j+1]일때 까지 j-- why? => 정렬을 위해.
            swap(array[j],array[j+1]);
            j--; // array[j] <=array[j+1]일때 까지 j-- why? => 정렬을 위해.
        }
    }
}
void print(){
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
}
int main()
{   
    input();
    solve();
    print();
}