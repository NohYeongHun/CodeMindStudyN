#include <iostream>
using namespace std;
//함수를 통해 직접 n번째 자리에서 반올림하는 것은 불가능하며,
//첫째 자리에서만 반올림이 가능하다. 
//따라서 소수점 n번째 자리를 소수점 첫째 자리로 만들고 반올림 후 원상태로 복구할 것이다.
// cin.ignore:특정 문자가 나올때까지 기다림.
// cout.width : 출력 자릿수 설정 / cout.fill(): 출력 자릿수를 맞추고 빈자리를 무엇으로 채울건지.
int main(){
  int num1,num2;

  cin>>num1;
  cin.ignore(256,'-');
  cin>>num2;
  cout.width(6); cout.fill('0');
  cout<<num1;
  cout.width(6); cout.fill('0');
  cout<<num2;
    return 0;
}