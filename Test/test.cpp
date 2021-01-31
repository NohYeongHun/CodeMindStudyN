/*
/문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;
#define STACK_SIZE 10000
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
		return -1;
	}
	else{ 
		cnt--;
		return stack[top--];
		} // 현재 top의 원소를 삭제한 후 top 감소
}

//스택의 top 원소를 검색하는 연산
element peek(){
	if(isEmpty()){
		return -1;
	}
	else return stack[top];
}

int main(){
	//선언
	element item; // 스택의 요소.
	int N,pcheck; // 1~10000까지의 정수 명령수를 결정
	string order; //ex) "push" "1" 구분
	int numcheck=0; 
	//입력
	cin>>N;
	int *num=(int *)malloc(sizeof(int)* N);//출력값.

	//로직
	for(int i=0; i<N; i++){
			cin>>order;
		if(order=="push"){
			cin>>pcheck;
			push(pcheck);
		}else if(order=="top"){ // 스택의 가장 위의 정수 출력
			if(top==-1){
				num[numcheck]=-1;
				numcheck++;
			}
			else{
				num[numcheck]=stack[top];
				numcheck++;
			}
		}else if(order=="size"){
				num[numcheck]=cnt;
				numcheck++;
		}else if(order=="empty"){
			if(isEmpty()){
				num[numcheck]=1;
				numcheck++;
			}
			else {
				num[numcheck]=0;
				numcheck++;
				}
		}else if(order=="pop"){
			num[numcheck]=pop();
			numcheck++;
		}
	}
	//출력
	for(int i=0; i<numcheck; i++){
		cout<<num[i]<<"\n";
	}
	free(num);
}