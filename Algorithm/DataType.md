# 10진수의 Zone 표기
- 10진수 한 자리를 Zone 형식 표현을 위해 1바이트(8비트)를 한 단위로 
  사용.
- 8비트는 상위 4비트 존영역과 하위 4비트 수치영역으로 구성됨.
- 존 영역에는 항상 1111 표시
- S부호 양수(1100), 음수(1101)
  ex) 10진수 -39
  {1111(존 영역) 0011(10진수 십의 자리)} {1101(S부호) 0101(10진수 일의 자리)}

# 10진수의 Pack 표기
- 1바이트에 10진수 두자리를 표현.
- 부호는 최하위 바이트의 하위 4비트에 표시
- S부호 양수(1100), 음수(1101)
ex) 10진수 -39
{0011(10진수 십의자리), 0101(10진수 일의자리), 1101(음수)}

# 2진수의 정수 표현
- 보수 : 보충을 해주는 수 1에 대한 10의 보수는 9 4에 대한 15의 
  보수는 11의 개념.
- 컴퓨터에서는 음수를 2진수의 1의 보수로 변환하여 표현.
  어떤 값 -x(음수 x)를 n비트의 1의 보수로 표현하는 방법은
  (2^n-1) -|x|이다. 

- 1의 보수 n비트인 x를 절댓값으로 표현한 값에서 0은 1로 바꾸고
  1은 0으로 바꾸면 1의 보수가됨.
  전체 n 비트를 1로 설정한 값에서 x의 절댓값을 뺀 값이 1의 보수가됨.
  ex )21의 1의 보수 -> 11111111- 00010101 = 11101010 
- 2의 보수는 1의 보수를 구한 값에 1을 더해주면 된다.
- ex) -39를 3바이트 표시 -39: 10100111
  부호 절댓값 형식 : 10100111
  1의 보수 형식 : -39의 절댓값 11111111 - 00100111 = 11011000
  2의 보수 형식 : 11011000 +1 = 11011001

  # 부동 소수점 표현 방식
  - 과학적 표기 방식의 실수를 사용, 고정 소수점 표현 방식에 비해 
    아주 작은 값이나 아주 큰 값 표현가능
    ex) 213 = 0.213 * 10^3(실수의 과학적 표기)
  - 실수 표현시 부호, 지수, 가수의 세영역 사용
    IEEE 754 표준 예시 (100010.101)
    1. 정규화 : 정수부가 1이 되도록 소수점을 이동하여 과학적 표기로 변환.
    2. 부호 : 양수는 0, 음수는 1을 저장.
    3. 가수부 : 정규화하면 정수부는 항상 1이 되므로, 정수부를 생략하고 소수부(00010101)만 저장.
    4. 지수부 : 정규화해서 구한 지수와 바이어스를 더한 값을 저장.
       바이 어스는 지수의 부호를 표현하기 위해 사용하는 값으로
      단정도 부동소수점 표현 방식에서는 127을 사용하여 지수 5+127=
      132=10000100(2진수), 배정도 부동소수점 표현 방식에서는 1023을 사용하여 지수 5+1023 = 10000000100

      ex) 0.625 :
      0.625 * 2 = 1.25 -> 1빼내고 나머지 0.25
      0.25 * 2 = 0.5 -> 0빼내고 나머지 0.5
      0.5 * 2 = 1.0 -> 1빼내고 나머지 0
    5. 고정 소수점 표현방식
    ex)7.625 => 0(부호비트)0000111(정수부).10100000(소수부)-16비트
    맨 앞은 부호 비트 0(양수), 1(음수)
    6. 부동 소수점 표현 방식
    ex) 2진수로 변환한 결과를 그대로 박아넣지 않고 몇가지 과정 추가로 거침.
    - 정규화 : 정규화라는 단어는 수학이나 컴퓨터 분야에서 다양한 의미로 쓰이지만 여기서 말하는 정규화라는 것은 2진수를 1.xxxx*2^n 꼴로변환하는 것.
    - 정규화 변환 방법: 정수부에 1만 남을때까지 소수점을 왼쪽으로 이동시키고 이동한 칸 수만큼 n 자리에 집어넣으면 됨.
    - 부동 소수점의 표현 : 부호 비트는 고정 소수점과 동일하게 0이면 양수 1이면 음수. 가수부는 정규화 결과 소수점 오른쪽의 숫자들을 왼쪽부터 그대로 넣으면 됨.
    지수부는 IEEE 표준에 맞춰서 'bias'라고 하는 지정된 숫자를 더한 다음 넣어야함. ex) 32비트를 쓰고 지수부가 5면 바이어스 127을 더한 5+127 = 132가 지수부에 들어감. 10000100 
    64비트 체계에서는 지수부가 11비트, 가수부가 52비트이고. 지수부가 2^11 즉 2048개의 수를 표현할 수 있으므로 0~1023 구간은 음수, 1024~2047 구간은 양수 지수를 의미하며 bias는 1023 이 된다.

# 문자 자료의 표현
1. BCD 코드 :
  상위 2비트의 존비트와 하위 4비트의 숫자 비트로 이루어짐.
  00 : 숫자 0,1~9
  01 : 문자 A~I
  10 : 문자 J~R
  11 : 문자 S~Z

2. EBDIC 코드 :
   상위 4비트의 존비트와 하위 4비트의 숫자 비트로 이루어짐.
   존비트 AB 
   {{00: 여분},{01: 특수문자},{10: 영어 소문자},{11: 영어 대문자}}
   존비트 CD
   {{00: 문자 A~I},{01: 문자 J~R},{10: 문자 S~Z},{11: 숫자 0~9}}
3. ASCII 코드 :
   상위 3비트의 존비트와 하위 4비트의 숫자 비트로 이루어짐. 
   존 비트와 숫자 비트를 조합한 코드로 0부터 9까지의 10진수 숫자,
   영어대문자와 소문자, 특수문자를 나타낼 수 있다.

