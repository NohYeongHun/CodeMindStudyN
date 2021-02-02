/*
문제
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 
‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 
그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다.
만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 

여러분은 입력으로 주어진 괄호 문자열이 
VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 

입력
입력 데이터는 표준 입력을 사용한다. 
입력은 T개의 테스트 데이터로 주어진다.
 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 
 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 
 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 

출력
출력은 표준 출력을 사용한다.
만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면
“YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 
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
	int T; // 테스트 케이스
	cin>>T;
	char VPS[50];
	//입력
	for(int i=0; i<T; i++){
		cin>>VPS;
		if(check(VPS)==1){
			cout<<"YES"<<"\n";
		}else if(check(VPS)==0){
			cout<<"NO"<<"\n";
		}
	}
}

int check(char* VPS){
	char ch, open_ch;
	int n = strlen(VPS);
	for(int i=0; i<n;i++){
		ch = VPS[i]; // ch = VPS[0];
		switch(ch) //ch
		{
			case '(': //ch가 '('인 경우
			push(ch);
			break;
			case ')': //ch가 ')'인 경우
			if(isEmpty()) return 0; // isEmpty() == true이면 즉 스택이 비어있으면 return 0; 
			else{ //스택이 비어있지 않으면
				 open_ch = pop(); //top의 원소를 pop()해서 가지고옴.
				 if(open_ch=='(' && ch!=')') // open_ch =='('이고  ch !=')'이면.
				 	return 0;
				// => 이부분은 예외처리.
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
	
	return 1;
}

/*
해설
'('가 나왔을때는 stack에 push()를해줘서 stack안에 집어넣고
')'가 나왔을때는 stack에 pop()을 해줘서 안에 '('가 있을때만 괄호가 정상적으로 동작하는경우이다.
ex) '()(())' => push pop push push pop pop
*/