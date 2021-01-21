# 배열
```
    동적할당 malloc(m*sizeof(int *))을 int**으로 형변환
    배열은 수식에서 사용될 때 포인터로 변환됨.   
    numArr[3]=0; 
    []를 사용하면 numArr은 배열의 첫번째 요소를 가리키는 포인터로 변환
    numArr == numArr->numArr[0]
    numPtr = numArr; //수식에서 numArr은 배열의 첫번째 요소를
    가리키는 포인터로 변환됨.
    하지만 sizeof 연산자로 배열의 크기를 구할 때, & 연산자로 주소를
    구할 때, 문자 배열을 선언하면서 문자열로 초기화 할 때는 배열이
    포인터 변환되지 않고 배열 그자체로 사용됨.
    numPtr = &(numArr[0]);

    3[numArr]도 되는 이유는??
    배열 첨자 연산자[]는 교환법칙이 성립하기 때문. []는 포인터 연산과 역참조로 표현 가능.
    
    int t[5];
    for(i=0;i<sizeof(t)/sizeof(int);i++){
        cout<< "sizeof를 배워보자"<<endl;
    }
    /*
    sizeof 연산자는 배열이 차지하는 전체공간이므로
    sizeof(t)는 20이다. 고로 요소의 개수를 구할 때는 배열이 차지하는
    전체 공간에서 요소의 크기로 나눠준다.
    */
    
    배열의 범위를 벗어난 값을 대입해도 컴파일러는 오류처리를
    하지않는다.
```    
# reference
[배열범위초과]https://m.blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221054714926&proxyReferer=https:%2F%2Fwww.google.com%2F