/* 문제
인하은행에는 ATM이 1대밖에 없다.
 지금 이 ATM앞에 N명의 사람들이 줄을 서있다.
  사람은 1번부터 N번까지 번호가 매겨져 있으며, 
  i번 사람이 돈을 인출하는데 걸리는 시간은 Pi분이다.

사람들이 줄을 서는 순서에 따라서, 
돈을 인출하는데 필요한 시간의 합이 달라지게 된다.
 예를 들어, 총 5명이 있고, 
 P1 = 3, P2 = 1, P3 = 4, P4 = 3, P5 = 2 인 경우를 생각해보자. 
 [1, 2, 3, 4, 5] 순서로 줄을 선다면, 1번 사람은 3분만에 돈을 뽑을 수 있다.
2번 사람은 1번 사람이 돈을 뽑을 때 까지 기다려야 하기 때문에,
3+1 = 4분이 걸리게 된다. 3번 사람은 1번, 2번 사람이 돈을 뽑을 때까지 기다려야 하기 때문에,
총 3+1+4 = 8분이 필요하게 된다. 
4번 사람은 3+1+4+3 = 11분, 5번 사람은 3+1+4+3+2 = 13분이 걸리게 된다. 
이 경우에 각 사람이 돈을 인출하는데 필요한 시간의 합은 3+4+8+11+13 = 39분이 된다.

줄을 [2, 5, 1, 4, 3] 순서로 줄을 서면, 
2번 사람은 1분만에, 
5번 사람은 1+2 = 3분, 1번 사람은 1+2+3 = 6분, 4번 사람은 1+2+3+3 = 9분,
3번 사람은 1+2+3+3+4 = 13분이 걸리게 된다.
각 사람이 돈을 인출하는데 필요한 시간의 합은 1+3+6+9+13 = 32분이다.
이 방법보다 더 필요한 시간의 합을 최소로 만들 수는 없다.

줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어졌을 때,
각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다.
 둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)

출력
첫째 줄에 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 출력한다. 
삽입 정렬 개념이 들어간다.
why? 가장 적은수를 앞에 두게 배열을 이동시키면 해결되는 문제

// 선택 정렬
#include <stdio.h>
//삽입 정렬 

int main() {
    int n=5;
    int arr[10] = {3, 2, 1, 5, 4};

    for(int i=0; i<n; i++) {
        // i부터 1까지 비교해야 비교문에서  
        // (arr[j-1]이 배열의 최소인 0 인덱스에 접근 가능)
        for(int j=i; j>=1; j--) {
            if(arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            // j번째가 더 크다면 
            // j-1 부터 0번째까지는 정렬되어 있으므로 
            // j번째가 j-1 부터 0번째까지 다 크기때문에 비교 안해도 됨
            else {
                break;
            }
        }
    }


    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

해당 문제는 삽입 정렬을 사용해서 푸는 문제이다.
 */

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;//사람의 수
	cin>>N;
	vector<int> V(N);//사람마다 걸리는시간
	int i=0,j=0;
	int sum=0,T=0;
	for(i=0;i<N;i++){
		cin>>V[i];
	}
 	for(int i=0; i<N; i++) {
        // i부터 1까지 비교해야 비교문에서  
        // (arr[j-1]이 배열의 최소인 0 인덱스에 접근 가능)
        for(int j=i; j>=1; j--) {
            if(V[j-1] > V[j]) {
                int temp = V[j-1];
                V[j-1] = V[j];
                V[j] = temp;
            }
            // j번째가 더 크다면 
            // j-1 부터 0번째까지는 정렬되어 있으므로 
            // j번째가 j-1 부터 0번째까지 다 크기때문에 비교 안해도 됨
            else {
                break;
            }
        }
    }
	
	/* 
	V[i]가 최소인 값부터 순서를 정하면된다? 
	정렬을 V[i]가 최소인 값으로 정렬시키면됨.
	*/
	for(int i=0;i<N;i++){
		sum=sum+V[i];
		T+=sum;
	}
	//출력
		cout<<T;
}
/*
필요한 속성
int num, sum, now, N;
vector<int> T;
N => 사람의 수
num => vector 배열에 푸시해줄 값.
now => 현재 줄을 선사람이 소요해야 하는 시간
sum = > 총 시간
vector<int> T => 각사람의 소요시간이 들어갈 배열
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> T;
int main()
{       
    cin.tie(NULL); 
    ios::sync_with_stdio(false);
    int num;
    int now = 0 ,sum = 0;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        T.push_back(num);
    }
    sort(T.begin(),T.end());
    for(auto iter=T.begin(); iter!=T.end(); iter++){
        now+=*iter;
        sum+=now;
    }
    cout<<sum;
}
*/