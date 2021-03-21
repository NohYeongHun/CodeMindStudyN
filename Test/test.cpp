//boj.kr/2751
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000
void swap(int arr[], int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void threeSort(int arr[], int front, int mid, int rear){
    if(arr[front]>arr[mid]) swap(arr,front,mid);
    if(arr[mid]>arr[rear]) swap(arr,mid,rear);
    if(arr[front]>arr[mid]) swap(arr, front, mid);
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
        while(arr[++i]<pivot && i<rear);  //arr[++(front)]<pivot and i<rear
        while(arr[--j]>pivot && front<j); //arr[--(rear-1)]<pivot and i<rear
        if(i>=j) break;
        swap(arr, i, j);
    }
    swap(arr, i, rear-1);
    quick_sort(arr, front, i-1);
    quick_sort(arr, i+1, rear);
    }
}
int N=0;
int main(){
    int N=0;
    cin>>N;
    vector<int> T(N,0);
    for(int i=0; i<N;i++)
        cin>>T[i];
    sort(T.begin(),T.end());
    for(int i=0; i<N;i++)
        cout<<T[i]<<"\n";
}
/* 
int N=0;
int main(){
    int N=0;
    cin>>N;
    int T[N];
    for(int i=0; i<N;i++)
        cin>>T[i];
    quick_sort(T,0,N-1);
    for(int i=0; i<N;i++)
        cout<<T[i]<<"\n";
}
 */
