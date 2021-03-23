//boj.kr/2751
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 
출력스트림에 들어갈 수 있는 최대 문자열의 크기는 8MB를 초과한다.
출력스트림에서 한 줄당 [1, 0, 0, 0, 0, '\n'] 총 6바이트가 필요하게 되는데, 10,000,000개의 입력되는 숫자가 모두 10,000이라면 60,000,000바이트의 크기의 출력스트림을 갖게 되는 것이다.
당연히 이 크기는 메모리 범위를 넘어서 메모리초과를 일으킨 것이다.
*/
void input(){
    int N;
    cin>>N;
    int x;
    int num[10001] ={0,};
    
    // 카운트 정렬
    for(int i = 0 ; i < N; i++){
        int a;
        cin >> a;
        num[a] += 1;
    }

    // 각 숫자를 개수만큼 출력해주기
    for(int i = 1 ; i <= 10000; i++) 
        for (int j = 0; j < num[i]; j++) // num[1]==0이면 출력 x 1이면 1한번 출력
            cout << i << "\n";
}
int main()
{   
    cin.tie(NULL); 
    ios::sync_with_stdio(false);
    input();

}
