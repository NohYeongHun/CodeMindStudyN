#include <iostream>
using namespace std;
#define MAX 10000

int N;
int array[MAX+1];


// 정렬의 기본이되는 함수 인수 두개의 위치를 바꿔줌.
void *swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
}

void quick_sort(int *arr,int front, int end){
    if (front >= end) return;
    int i,j=0;
    int pivot = front;
    i = front+1;
    j = end;
    while(i<=j){ // 엇갈릴때 까지 반복
        while(arr[i]<=arr[pivot]){ // pivot 기준 왼쪽 => 오른쪽arr[i]>arr[pivot]인 i 인덱스 찾기.
            i++;
        }
        while(arr[j]>=arr[pivot] && j>front){ // 맨 오른쪽 => 왼쪽arr[j]<arr[pivot]인 j 인덱스 찾기.
            j--;
        }
        if(i>j){ // 만약 i값이 j값보다 크다면
            swap(arr,pivot,j); // swap(arr[pivot], arr[j])
        }else{
            swap(arr,i,j); // 아닌 경우엔 arr[i]>pivot && arr[j]<arr[pivot]인 상황이므로 둘의 값을 변경함.
        }
    }
    quick_sort(arr,front,j-1); //현재 pivot값은 j인덱스에 있으므로 front ~ j-1 까지 정렬해줌.
    quick_sort(arr,j+1,end); // 현재 pivot값은 j인덱스에 있으므로 j+1~end 까지 정렬해줌.
}
//내림차순
void quick_sort_reverse(int *arr,int front, int end){
    if (front >= end) return;
    int i,j=0;
    int pivot = front;
    i = front+1;
    j = end;
    while(i<=j){ // 엇갈릴때 까지 반복
        while(arr[i]>=arr[pivot]){ // pivot 기준 왼쪽 => 오른쪽arr[i]<arr[pivot]인 i 인덱스 찾기.
            i++;
        }
        while(arr[j]<=arr[pivot] && j>front){ // 맨 오른쪽 => 왼쪽arr[j]>arr[pivot]인 j 인덱스 찾기.
            j--;
        }
        if(i>j){ // 만약 i값이 j값보다 크다면
            swap(arr,pivot,j); // swap(arr[pivot], arr[j])
        }else{
            swap(arr,i,j); // 아닌 경우엔 arr[i]>pivot && arr[j]<arr[pivot]인 상황이므로 둘의 값을 변경함.
        }
    }
    quick_sort_reverse(arr,front,j-1); //현재 pivot값은 j인덱스에 있으므로 front ~ j-1 까지 정렬해줌.
    quick_sort_reverse(arr,j+1,end); // 현재 pivot값은 j인덱스에 있으므로 j+1~end 까지 정렬해줌.
}
void print(){
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
}
int main()
{   
    input();
    //quick_sort(array,0,N-1);
    quick_sort_reverse(array,0,N-1);
    print();
}