#include <iostream>
#include <vector>
using namespace std;

/*문제
정수 n개가 주어졌을 때, n개의 합을 구하는 함수를 작성하시오.
C++, C++11, C++14, C++17, C++ (Clang), C++11 (Clang), C++14 (Clang), 
C++17 (Clang): long long sum(std::vector<int> &a);
a: 합을 구해야 하는 정수 n개가 저장되어 있는 배열 
(0 ≤ a[i] ≤ 1,000,000, 1 ≤ n ≤ 3,000,000)
리턴값: a에 포함되어 있는 정수 n개의 합
*/
long long sum(vector<int> &a){ //참조로 전달하는 이유 메모리 절약.
    long long ans =0;
    for(vector<int>::iterator iter = a.begin(); //a 의 시작배열
    iter <a.end(); iter++) //a의끝배열, iter ++ 추가
    {
        ans+=*iter; //iter 참조값을 가져옴.
    }
    return ans;
}
