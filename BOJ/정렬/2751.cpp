// boj.kr/2751
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000


void threeSort(int arr[], int front, int mid, int rear){
    if(arr[front]>arr[mid]) swap(arr,front,mid);
    if(arr[mid]>arr[rear]) swap(arr,mid,rear);
    if(arr[front]>arr[mid]) swap(arr, front, mid);
}
void swap(int arr[], int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
void quick_sort(int arr[], int front, int rear){ //rear = 끝 인덱스, front = 처음 인덱스
    int i, j, pivot, mid = front+(rear-front)/2;
    threeSort(arr, front, mid, rear);
    if(rear-front+1>3){
        pivot = arr[mid]; // pivot = 중앙인덱스.
        swap(arr, mid, rear-1);
        i = front; // 맨앞은 이미 정렬
        j = rear-1; // 맨뒤는 이미 정렬
    while(true){
        //왼쪽 pivot보다 작은곳 pivot보다 큰값이 왼쪽에 나오면 종료.
        while(arr[++i]<pivot && i<rear);  //pivot보다 작을 동안 =>arr[++(front)]<pivot and i<rear ==제약조건
        //오른쪽 pivot보다 큰곳 pivot보다 작은 값이 오른쪽에 나오면 종료.
        while(arr[--j]>pivot && front<j); //pivot보다 클 동안 arr[--(rear-1)]<pivot and fornt<j ==제약조건       
        if(i>=j) break; //while문 종료시 i값이 j보다 크거나 같으면 break;
        swap(arr, i, j); // while문 종료시 arr[i]값과 arr[j]값을 교환한다.
    }
    swap(arr, i, rear-1);
    quick_sort(arr, front, i-1);
    quick_sort(arr, i+1, rear);  
    }
}
int N=0;
int main(){
    cin.tie(NULL); 
    ios::sync_with_stdio(false);
    int N=0;
    cin>>N;
    vector<int> T(N,0);
    for(int i=0; i<N;i++)
        cin>>T[i];
    sort(T.begin(),T.end());
    for(int i=0; i<N;i++)
        cout<<T[i]<<"\n";
}