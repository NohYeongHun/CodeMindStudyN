#include <iostream>
using namespace std;
// 문제
// 대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 
// 당신은 그들에게 슬픈 진실을 알려줘야 한다.

// 입력
// 첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

// 둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 
// 이어서 N명의 점수가 주어진다. 
// 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

int main(){
	//선언
	int C,N; // 테스트 케이스 개수 ,학생 수 
	int num[1000], stu=0 ,sum=0; // 학생들의 점수, 평균을 넘는 학생의 수, 학생의 점수합.
	float avg; //평균 

	//입력,로직
	cin>>C;
	float *over = (float *)malloc(sizeof(float) * C); //평균을 넘는 학생들의 비율(반올림 소수점 셋째자리.)
	for(int i=0; i<C;i++){
		cin>>N;
		for(int j=0; j<N; j++){
		cin>>num[j]; //학생들의 점수 입력
		sum+= num[j];
		}
		avg = sum/N; //평균 구하기
		for(int j=0; j<N; j++){
			if(num[j]>avg){
				stu++;
			}
		}
		over[i]=(float)stu/N; 
		stu=0;
		sum=0;
		avg=0;
	}


	//출력
	for(int i=0; i<C;i++){
		over[i]=over[i]*100;
		cout << fixed;
		cout.precision(3);
		cout<<over[i]<<"%\n";
	}
	free(over);
}