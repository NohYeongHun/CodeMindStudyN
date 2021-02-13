/* 문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. 
(1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다. */
#include <iostream>
#include <vector>
using namespace std;

int main(){
	//입력 및 선언
	int N, K,M=0;// N: 동전의 수, K: 금액, M : 최소 동전 개수
	cin>>N>>K;
	int i=0;
	vector<int> V(N);
	for(i=0; i<N; i++)
		cin>>V[i];
	//while()문을 돌려서. i값을 고정시킴.
	//로직
	i=i-1;
	while(i>=0){
		if(V[i]<K){
			K=K-V[i];  
			/* K가 5000원이라면 V[i]가 500원이라면 K = 5000- 500 M++; 
			다시 이 계산 수행 */
			M++;
		}
		else if(V[i]>K){ 
			/* 만약에  위 계산을 수행했을때 K=60000 V[i]=50000 K= 60000-50000 K<V[i]만족 
			다음 10000과 비교하러감. */
			i--;
		}
		else if(V[i]==K){
			M++;
			break;
		}
	}

	
	cout<<M;
	return 0;
}