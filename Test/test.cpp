/* 
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 
그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 
가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 
5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 
입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string V;
//문자열 표현시 문자열의 끝을 의미하는 문자인 '\0'이 삽입됨. NULL 문자라함.
int minCalc(){
    int result =0;
    string temp ="";
    bool check = false;
    for(int i=0; i<=V.size(); i++){
        // 기호가 나오기전까지 temp에는 숫자가 들어가게 됨.
        if(V[i]=='+' || V[i]=='-'|| V[i]=='\0') 
        {
            if(check)
                result -=stoi(temp);
            else
                result +=stoi(temp);
            temp=""; 
            if(V[i]== '-')
                check=true;
            continue;
        }
        temp +=V[i]; 
        //continue 이동 위치 
    }
    return result;
}

int main(){
    cin>>V;
    cout<< minCalc()<<"\n";
}