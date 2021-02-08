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
#include <vector>
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

void EmptyMake(){
	while(!isEmpty()){
		pop();
	}
}

int main(){
	//선언
	int N; //수열의 길이.	
	cin>>N;
	int i =0;
	vector<int> V(N); //N개의 원소를 가지는 벡터 생성

	vector<int> answer(V.size(), -1); // -1로 초기화 크기는 N개;
	for(i=0; i<N; i++) cin>>V[i];
	
	for(i = 0; i < V.size(); i++){
		while(!isEmpty() && V[peek()] < V[i] ){ 
			/* 
			4 => 3, 5, 2, 7
			stack이 비어있지않고 V[peek()]<V[i]가 성립하면 answer[peek()]= V[i]를 넣어줌.
			i=0일때 => push(0) stack[top]= 0; stack ={0}
			i=1일때 => while(!isEmpty() && V[peek()]< V[i]) => !isEMpty() = true V[peek()==0]  <V[1] => V[0]<V1 3<5
			answer[0] = V[1] // answer[0] = 5;
			pop() => isEmpty() =>  while문 탈출
			push(1); stack={1} stack[top]=1;
			i=2일때 => !isEmpty() = true V[1] < V[2] => 5<2 => false 
			=> push(2) stack={2,1} stack[top]=2;
			i=3일때 => !isEmpty() = true; V[stack[top]==2]<V[3] => 2<7(true)
			=> answer[2] = V[3]; answer[2]= 7; pop() => stack[top]=1;
			=> !isEmpty() =true; V[stack[top]==1]<V[3] => 5<7(true)
			=> answer[1] = V[3]; answer[1]= 7; pop() => stack[top]=NULL;
			push(3);
			i=4 종료. 마지막으로 스택엔 {3}원소가 남아있게됨.
			*/
			answer[peek()] = V[i]; // V[peek()]<V[i]이면 출력할 배열의 인덱스에 V[i]값을 넣어줌.  
			pop(); // 해당 인덱스값을 사용하였으므로 pop();
		}
		push(i); //스택에 인덱스값을 푸시 0 1 2 3 
	}
	for(int i: answer){ // 배열 출력.
		cout<<i<<" ";
	}
}
/*

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm>
#include <climits>
#include <set> 
#include <unordered_map> 
#include <unordered_set> 
#include <map> 
#include <cstdio>
#include <stack>
  using namespace std; 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
     int n; 
     cin >> n; 
     vector<int> v(n); 
     for (int i = 0; i < n; i++) cin >> v[i]; 
     stack<int> st; 
     vector<int> ans(v.size(), -1);
      for (int i = 0; i < v.size(); i++) 
      { 
          while (!st.empty() && v[st.top()] < v[i] ) 
            {   
                cout<<"st.top() : "<<st.top()<<"\n";
                ans[st.top()] = v[i]; 
                st.pop(); 
            } st.push(i); 
        } 
        for (int x : ans) cout << x << " "; 
        return 0; 
    }
*/
