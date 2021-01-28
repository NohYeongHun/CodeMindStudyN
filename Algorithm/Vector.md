# vector container
- 정의 : 크기가 변경 될 수 있는 배열을 나타내는 시퀀스 컨테이너.
- 자동으로 메모리가 할당되는 배열.
- 맨 뒤쪽에서 삽입과 삭제가 가능.(스택과 비슷한 느낌.)
- 배열 기반이므로 삽입 삭제가 빈번하게 일어나면 비효율적임.

# vector의 사용

- `<vector>`헤더파일을 추가해야함.
- `using maespace std;` 를 해주면 편리함.
-   vector의 선언은 - vector<[data type]> [변수이름] 입니다.
    ex) `vector<int> v;`

# vector의 생성자와 연산자
- `vector<int> v;`
- 비어있는 vector v를 생성합니다.

- `vector<int> v(5);`
- 기본값(0)으로 초기화 된 5개의 원소를 가지는 vector v를 생성합니다.

- `vector<int> v(5, 2);`
- 2로 초기화된 5개의 원소를 가지는 vector v를 생성합니다.

- `vector<int> v1(5, 2);`
- `vector<int> v2(v1);`
- v2는 v1 vector를 복사해서 생성됩니다.
- `vector<int> v1;` , `vector<int> v2;`가 있고, 
  내부에 인자들이 있다고 했을때.


# vector의 멤버 함수
== `vector<int> v;` 라고 가정.
== 참조 한다는 것은 해당 데이터를 리턴 한다는 뜻입니다.

v.assign(5, 2);
- 2의 값으로 5개의 원소 할당.

`v.at(idx);`
- idx번째 원소를 참조합니다.
- `v[idx]` 보다 속도는 느리지만, 범위를 점검하므로 안전합니다.

`v[idx]`;
- idx 번째 원소를 참조합니다.
- 범위를 점검하지 않으므로 속도가 v.at(idx)보다 빠릅니다.

v.front();
- 첫번째 원소를 참조합니다.

v.back();
- 마지막 원소를 참조합니다.

v.clear();
- 모든 원소를 제거합니다.
- 원소만 제거하고 메모리는 남아있습니다.
- size만 줄어들고 capacity는 그대로 남아있습니다.

v.push_back(7);
- 마지막 원소 뒤에 원소 7을 삽입합니다.

v.pop_back();
- 마지막 원소를 제거합니다.

v.begin();
- 첫번째 원소를 가리킵니다. (iterator와 사용)

v.end();
- 마지막의 "다음"을 가리킵니다 (iterator와 사용)

v.rbegin();
- reverse begin을 가리킨다 (거꾸로 해서 첫번째 원소를 가리킵니다)
- iterator와 사용.

v.rend();
- reverse end 을 가리킨다 (거꾸로 해서 마지막의 다음을 가리킵니다)
- iterator와 사용.

v.reserve(n);
- n개의 원소를 저장할 위치를 예약합니다(미리 동적할당 해놉니다)

v.resize(n);
- 크기를 n으로 변경한다.
- 더 커졌을 경우 default값인 0으로 초기화 한다.
v.resize(n,3);
- 크기를 n으로 변경한다.
- 더 커졌을 경우 인자의 값을 3으로 초기화한다.


 


v.size();
- 원소의 갯수를 리턴한다.

v.capacity();
- 할당된 공간의 크기를 리턴한다.
- 공간 할당의 기준은 점점 커지면서로 capacity를 할당하게 됩니다.
**size와 capacity에 관계는 4번 항목에서 설명드립니다. 중요하니 꼭 보고 가세요
v2.swap(v1);
- v1과 v2의 원소와 capacity 바꿔줍니다. (모든걸 스왑해줌)
- v1의 capacity를 없앨때 (할당한 메모리를 프로그램이 끝나기 전에 없애고 싶을때) 사용하기도 합니다.
- v2를 capacity가 0인 임시 객체로 만들어서 스왑을 해줍니다.
- vector<int>().swap(v1);

v.insert(2, 3, 4);
- 2번째 위치에 3개의 4값을 삽입합니다. (뒤엣놈들은 뒤로 밀림)

v.insert(2, 3);
- 2번째 위치에 3의 값을 삽입합니다.
- 삽입한 곳의 iterator를 반환합니다.

v.erase(iter);
- iter 가 가리키는 원소를 제거합니다.
- size만 줄어들고 capacity(할당된 메모리)는 그대로 남습니다.
- erase는 파라미터 하나를 받을때와 두개를 받을 때 다릅니다.
- 그에 따른 예제는 여기있습니다.
v.empty()
- vector가 비었으면 리턴 true
- 비어있다의 기준은 size가 0이라는 것이지, capacity와는 상관이없습니다.

# vector의 멤버 형식

iterator - 반복자 형식
reverse_iterator - 역 반복자 형식
value_type - 원소의 형식
size_type - 원소의 개수의 형식
# iterator

# iterator 사용 형태
```c++
// iterator 사용한 형태
vector<int>v;
for(auto iter = v.begin(); iter!=v.end(); iter++)
    cout<<*iter<<"\n"

//기존 벡터 접근해서 값 변경하는 for문
vector<int>v;
for(auto iter=v.begin(); iter!=v.end();iter++)
  *iter+=2020;
  //code
    ```
```c++
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
        ans+=*iter;
    }
    return ans;
}
```
<br>
-------------------------------------
```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
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

```

# reference
[vector구조]https://blockdmask.tistory.com/70
