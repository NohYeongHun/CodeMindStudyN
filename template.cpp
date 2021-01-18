//템플릿 을 이용한  메타프로그래밍 = 컴파일러가 코드를 생성해줌.
//자바 활용성 높다.
#include <iostream>
using namespace std;
<<<<<<< HEAD
=======
template <typename S>
S Mincheck(const int& lv, const int& rv){
    return lv < rv ? lv : rv;
}
>>>>>>> main
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
<<<<<<< HEAD
=======
void Fibocheck(int x, int y){
    if(x !=y){
        x = y;
        cout << "x not fibo<0> or <1>" <<endl;
    }else{
        cout << "x && y fibo<0> or <1>"<<endl;
    }
}
>>>>>>> main

int main()
{
    int x = Fibonacci<0,int>::value;
    int y = Fibonacci<1,int>::value;
    int z = Fibonacci<2,int>::value;
<<<<<<< HEAD
=======
    Fibocheck(x,y);
    int a = Mincheck<int>(y,z);
    cout << a << endl;
>>>>>>> main
    cout <<x <<endl;
}