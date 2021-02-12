#include <iostream>
#include <vector>
using namespace std;

int main(){
	//입력 및 선언
	int N,M; /* N: 카드의 개수 M: M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력.*/
	int sum = 0,max = 0; /* M을 넘지않는 3개 카드의 최대합 수 */
	int i=0,j=0,k=0;
	cin>>N>>M; /* 카드개수 입력 받고 최대합숫자 입력 */
	vector<int> V(N);
	for(i=0;i<N;i++){
		cin>>V[i];
	}
	//로직
	/* sum= V[0]+V[1]+V[2] 
	0,1,2 / 0,1,3 /0,1,4/ 0,2,3 / 0,2,4 / 0,3,4 / 1,2,3/1,2,4/2,3,4
	*/
	for(i=0;i<N;i++){/* 시작 인덱스 정하기. */
		for(j=i+1;j<N;j++){
			for(k=j+1;k<N;k++){
				sum = V[i]+V[j]+V[k];
				if(sum>max && sum <=M)
					max=sum;
			}
		}
	}
	//출력
	cout<<max;
}