#include <iostream>
using namespace std;
//�Լ��� ���� ���� n��° �ڸ����� �ݿø��ϴ� ���� �Ұ����ϸ�,
//ù° �ڸ������� �ݿø��� �����ϴ�. 
//���� �Ҽ��� n��° �ڸ��� �Ҽ��� ù° �ڸ��� ����� �ݿø� �� �����·� ������ ���̴�.
// cin.ignore:Ư�� ���ڰ� ���ö����� ��ٸ�.
// cout.width : ��� �ڸ��� ���� / cout.fill(): ��� �ڸ����� ���߰� ���ڸ��� �������� ä�����.
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