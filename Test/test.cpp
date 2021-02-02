/*
문제
세계는 균형이 잘 잡혀있어야 한다. 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.

정민이의 임무는 어떤 문자열이 주어졌을 때, 
괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.

문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 
문자열이 균형을 이루는 조건은 아래와 같다.

모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.

입력
하나 또는 여러줄에 걸쳐서 문자열이 주어진다.
 각 문자열은 영문 알파벳, 공백, 소괄호("( )") 대괄호("[ ]")등으로 이루어져 있으며, 길이는 100글자보다 작거나 같다.

입력의 종료조건으로 맨 마지막에 점 하나(".")가 들어온다.
출력
각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력한다.

균형잡힌 문자열.
1. 문자열 하나를 입력받고 입력의 종료조건으로 맨 마지막에 점(".") 하나가 들어온다.
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define STACK_SIZE 10000
typedef char element;

int check(char* VPS);

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

int main(){
	//선언
	char VPS[100]; //입력 문자열
	while(VPS[0]!='.'){
		cin.getline(VPS, 100); //공백이 포함된 문자열 입력 받기.
		cout<<"VPS[0] : " <<VPS[0]<<"\n";
		cout<<"End VPS : "<<VPS<<"\n";
	}
	//입력

}

int check(char* VPS){
	char ch;
	int n = strlen(VPS);
	for(int i=0; i<n;i++){
		ch = VPS[i]; // ch = VPS[0];
		switch(ch) //ch
		{
			case '(': //ch가 '(', '['인 경우
			case '[':
			push(ch);
			break;
			case ')': //ch가 ')', ']'인 경우
			case ']':
			if(isEmpty()) return 0; // isEmpty() == true이면 즉 스택이 비어있으면 return 0; 
			else{ //스택이 비어있지 않으면
				 pop(); //top의 원소를 pop()해서 가지고옴.
				//  if(open_ch=='(' && ch!=')') // open_ch =='('이고  ch =='(''이면.
				//  	return 0;
			}
			break;
		}
	}
	//검사가 끝났는데 스택에 원소가 있으면 잘못된 식.
	if (!isEmpty()){
		while(!isEmpty()){
			pop();
		}
		return 0;
	}
	//아무런 이상이없다면. 
	return 1;
}