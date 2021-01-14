//템플릿 을 이용한  메타프로그래밍 = 컴파일러가 코드를 생성해줌.
//자바 활용성 높다.
#include <iostream>
using namespace std;
template <int n,typename T = int>
struct Fibonacci
{
    enum
    {
        value = Fibonacci<n-1,int>::value + Fibonacci<n-2,int>::value
    };
};

template<typename T>
struct Fibonacci<0,T>
{
    enum
    {
        value = 1
    };
};

template<typename T>
struct Fibonacci<1,T>
{
    enum
    {
        value = 1
    };
};

int main()
{
    int x = Fibonacci<0,int>::value;
    int y = Fibonacci<1,int>::value;
    int z = Fibonacci<2,int>::value;
    cout <<x <<endl;
}