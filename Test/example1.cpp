#include <iostream>
using namespace std;

int main()
{
	int t[2];
	int r;
	cin >> r;
	/*
	sizeof 연산자는 배열이 차지하는 전체공간이므로
	sizeof(t)는 20이다. 고로 요소의 개수를 구할 때는 배열이 차지하는
	전체 공간에서 요소의 크기로 나눠준다.
	*/
	// for(int i=sizeof(t)/sizeof(int)+1;i>0; i--){
	for (int i = 0; i < 10; i++) {
		// cout<<r<<endl;
		t[i] = r % 10;
		r = r / 10;
		cout << "i:" << i << " " << t[i] << endl;
	}
	cout << "|-------------------------" << endl;
	for (int j = 0; j < 10; j++)
		cout << "| [" << j << "] :" << t[j] << ", ";
	cout << endl << "|--------------------------" << endl;
	cout << "tttt   " << sizeof(t) / sizeof(int) << endl;
}