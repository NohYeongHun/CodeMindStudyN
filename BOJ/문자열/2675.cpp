#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
문제
문자열 S를 입력받은 후에, 각 문자를 R번 반복해 
새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오. 
즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 
식으로 P를 만들면 된다. 
S에는 QR Code "alphanumeric" 문자만 들어있다.

QR Code "alphanumeric" 문자는 
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.

입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다.
 각 테스트 케이스는 반복 횟수 R(1 ≤ R ≤ 8),
  문자열 S가 공백으로 구분되어 주어진다. 
  S의 길이는 적어도 1이며, 20글자를 넘지 않는다. 

출력
각 테스트 케이스에 대해 P를 출력한다.
*/
 int main()
{   
    int T; //테스트 케이스 개수
    int R; //반복횟수.
    string str,x;//반복할 문자.
    vector<string> result;
    cin>>T;
    for(int i=0; i<T;i++){
        cin>>R>>str;
        string s; 
        for(int j=0; j<str.size(); j++){
            for(int k=0;k<R;k++)
                s += str[j];
        }
        result.push_back(s); // 뒤에다가 s원소 넣어줌.
    }

    //iterator it 에 result.begin()값을 넣고. it!=result.end()일때 까지 it++
    for(vector<string>::iterator it = result.begin();it!=result.end(); it++){
        cout<<*it<<endl;
        cout <<"it["<<0<<"] : "<<it[0]<<endl;
    } // == it[0],it[1]
    
    // vector<string>::iterator xx= result.begin();
    // cout<<"why no cout? : "<<xx[0]<<"\n";
    // cout<<"how vector? : "<<xx[1]<<"\n";
}
