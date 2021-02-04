/*
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 
스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 
제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때
스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 
어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

입력
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다.
 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다.
 물론 같은 정수가 두 번 나오는 일은 없다.

출력
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. 
push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.


1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 

임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 
있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define STACK_SIZE 100000
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
//push와 pop의 순서를 배합해서 입력한 수열을 만들 수 있는지 확인
int main(){
	//선언
	int N; // 1~n까지의 범위
	//입력
	cin>>N;
	int i=0,j=0,c=0;
	char *sign = (char *)malloc(sizeof(char)*N*2);
	int *arr = (int *)malloc(sizeof(int)*N);
		for(i=0; i<N;i++){
			cin>>arr[i];
	}
	i=1;
	// 로직 완성 불가능한경우 NO 출력.
	while(1){
		if(arr[j]==stack[top]){
			pop();
			sign[c]='-';
			c++;
			j++;
		}
		else if(arr[j]!=stack[top]){
			if(i>N){
				cout<<"NO\n";
				break;
			}
			push(i);
			sign[c]='+';
			c++;
			i++;
		}
		if(isEmpty() && j==N){
			c=0;
			while(c!=N*2){
				cout<<sign[c]<<"\n";
				c++;
			}
			break;
		}

	}
	free(arr);
	free(sign);
}
/*요점 : +가 많아서 오류가 나는 경우는 있지만
-가 많아서 오류가 나는 경우는 없다.
즉 push()가 예상보다 많이 나와서 수열을 완성하지 못하는 경우는 있지만
pop()이 예상보다 많이 나올수는 없다. why? push()를 해서 스택에 채워야만이 pop()을 할 수 있기 때문
*/
/*
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int n, cur = 1;
    vector<int> stack;
    vector<char> result;

    scanf("%d", &n);
    stack.reserve(n);
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);

        while (cur <= num) {
            stack.push_back(cur++);
            result.push_back('+');
        }
        
        if (stack.back() == num) {
            stack.pop_back();
            result.push_back('-');
        } else {
            printf("NO");
            return 0;
        }
    }

    for (unsigned int i = 0; i < result.size(); ++i) { printf("%c\n", result[i]); }
    return 0;
}
*/