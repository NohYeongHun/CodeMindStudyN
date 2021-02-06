/*
문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 
수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. 
Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 
NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다.
 A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 
둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define STACK_SIZE 1000000
typedef int element;

element stack[STACK_SIZE]; // 1차원 배열 스택 선언
int top = -1; //top index
int cnt = 0;//스택안의 정수의 개수 세기

//스택이 공백인지 확인하는 연산.
int isEmpty(){ 
	if(top==-1)
		return 1; //true
	else return 0; //false
}

//스택이 포화 상태인지 확인하는 연산
int isFull(){
	if(top == STACK_SIZE -1) return 1;
	else return 0;
}
//스택의 top에 원소를 삽입하는 연산
void push(element item){
	if (isFull()){
		return;
	}
	else{ 
	stack[++top]= item;
	cnt++;
	}
}

//스택의 top에서 원소를 삭제하는 연산
element pop(){
	if (isEmpty()){
		exit(1);
	}
	else{ 
		cnt--;
		return stack[top--];
		} // 현재 top의 원소를 삭제한 후 top 감소
}

//스택의 top 원소를 검색하는 연산
element peek(){
	if(isEmpty()){
		exit(1);
		}
	else return stack[top];
}

/*
4
3527 => 5 7 7 -1
오큰수 3은 5 2 7 과 다비교를해야함.
*/
int main(){
	int N; // 크기가 N인 수열
	int i=0, j=0, c=1;
	cin>>N; //
	int *nge = (int*)malloc(sizeof(int)*N); //일반 수열
	int *obig = (int*)malloc(sizeof(int)*N);//오큰수
	for(i=0; i<N;i++){
		cin>>nge[i];
		cout<<"nge["<<i<<"] : "<<nge[i]<<"\n";
	}	

}