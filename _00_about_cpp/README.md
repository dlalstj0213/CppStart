[<< BACK](https://github.com/dlalstj0213/CppStart)

---

# ABOUT C++
- [ABOUT C++](#about-c)
  - [역사](#역사)
  - [C++ 프로그램의 소스 파일](#c-프로그램의-소스-파일)
  - [C++ 프로그램의 빌드](#c-프로그램의-빌드)
- [C++ 프로그래밍 첫걸음](#c-프로그래밍-첫걸음)
  - [주석](#주석)
  - [선행처리](#선행처리)
  - [문장](#문장)
  - [함수](#함수)
  - [명칭공간](#명칭공간)


## 역사
1970년 *Bell* 연구소의 *Bjarne Stroustrup*이 C 언어를 확장하여 만든 프로그래밍 언어<br>
-> C with Classes
<br>
-> 1983년부터 C++이라는 이름을 사용함
- 주요 확장 내용 :
  - **객체지향** 프로그래밍: 클래스, 상속, 다형성, 동적 바인딩 등
  - 일반화 프로그래밍: 템플릿
  - 예외처리

## C++ 프로그램의 소스 파일
- C++ 소스 프로그램 파일
  - **처리**하고자 하는 작업을 수행하는 C++ 프로그램 명령어들을 담고 있는 파일
  - 파일의 확장자: '*.cpp*', '*.cxx*', '*.C*' 등을 사용
- C++ 헤더파일
  - 클래스, 함수의 원형, 매크로, 전역변수, 상수 등 여러 소스 파일에 공통적으로 선언되는 내용을 담고 있는 파일
  - 단독으로 컴파일되지 않고, *#include* 라는 선행철리기 지시어에 의해 소스 프로그램 파일에 삽입되어 함께 컴파일됨
  - 확장자: 일반적으로 '*.h*' 를 사용

## C++ 프로그램의 빌드
< 헤더파일: Sub.h >
```C++
#define SUB_CONST
...
```
< 소스파일: Sub.cpp >
```C++
#include <iostream>
#include "sub.h"
using namespace std;
...
```
< 소스파일: Sample.cpp >
```C++
#include <iostream>
#include "sub.h"
using namespace std;
...
int main(){
  ...
}
```
 이 세 파일들을 모두 컴파일해서 실행파일로 만들 때 헤더파일은 단독적으로 컴파일 되는 파일이 아니기 때문에 Sub.cpp 나 Sample.cpp 의 적절한 위치에 include 라고 하는 명령어를 통해 삽입을 시킨다. 그리고 나서 Sub.h와 Sub.cpp 가 결합된 하나의 소스 파일과 Sub.h와 Sample.cpp가 결할된 소스 파일로 2개의 파일이 컴파일 된다.
 1. 소스 (프로그램) 파일 --**컴파일**--> 목적 (프로그램) 파일
    - ex) Sample.cpp--Complie-->Sample.obj
 2. 목적 파일(Sample.obj) + 라이브러리(library) --> 실행 파일 (Sample.exe)
    - ex) 링커가 목적 파일과 라이브러리를 **링크**해주면 마침내 실행 프로그램 파일이 생성
  - 필요한 도구 --> IDE ( 통합개발환경 ex) VS, ECLIPSE, ... )
    - 소스 프로그램 및 GUI 등의 편집기
    - 컴파일러
    - 링커
    - 디버깅 도구

# C++ 프로그래밍 첫걸음
## 주석
  ```C++
  // 주석 1
  /* 주석 2 */
  ```
## 선행처리
```c++
  #include <iostream> 
  //선행처리기 지시어
```
- C++ 프로그램을 컴파일하기 전에 소스 프로그램을 **가공**하여 컴파일러가 실제로 번역할 소스 프로그램을 만드는 것
- 선행처리기 지시어(preprocessor directives)로 처리를 지시함
  - 선행처리기 지시어는 '**#**'로 시작함
  - 선행처리기 지시어 문장은 **한 행에 한 개의 문장**을 작성함
- 대표적인 선행처리
  - 헤더파일 삽입: #include
  - 매크로 선언 및 해제: #define, #undef
  - 조건부 컴파일: #if, #ifdef, #ifndef

```c++
#include "a.h"
#include <iostream>
```
- ""와 <>의 차이점
  - ""는 직접 파일의 경로를 설정할때 쓰임
  - <>는 표준 라이브러리에서 설정된 경로를 가져올때 쓰임 (ex) iostream -> cout, endl 함수 사용 가능)
    - iostream, cmath, string ...
  
## 문장
- 문장의 끝 : ';'<br>
- 블록: '{', '}'
  - 한 개 이상의 문장을 중괄호 안에 나열하여 묶어 놓은 것
  - **여러 개의 문장을 묶어 하나의 문장처럼 취급**하거나 **함수의 몸체**를 구성하기 위해 사용됨

## 함수
```c++
#include <iostream>

int main() //머리부 : int=결과의 자료형, main=이름, ()=인수
{ //START 몸체 블록
  std::cout << "나의 첫 번째 C++ 프로그램" << std::endl;
  return 0;
} //END 몸체 블록
```
- std::cout 객체
  - 표준 출력 스트림 객체
  - 데이터를 문자열 형태로 변환하여 출력함
  - **출력 연산자**(삽입 연산자): '<<'
```c++
std::cout << "나의 첫번째 C++프로그램";
```
[결과 : 나의 첫번째 C++프로그램]
```c++
int a = 10;
std::cout << "a의 값은 ";
std::cout << a << "입니다." << std::endl;
```
[결과 : a의 값은 10입니다.]
<br>

- std::cin 객체
  - 표준 입력 스트림 객체
  - 문자열을 입력 변수의 자료형의 값으로 변환하여 입력함
  - **입력 연산자**(추출 연산자) : '>>'

```c++
int a;
char str[100];
std::cin >> a >> str;
```

## 명칭공간
- 특정한 이름들이 인식되는 프로그램의 부분
```c++
namespace myNSpc{ // myNSpc=명칭공간 이름
  int count; // 명칭을 선언하는 문장 나열
}
```
- 명칭공간에 정의된 명칭의 사용
```c++
myNSpc::count = 0; // ::=영역을 지정해주는 연산자
```
- **동일한 명칭이라도 서로 다른 명칭공간에서 정의되었다면 별개의 것으로 구분**함
  - 여러 프로그래머가 작성한 프로그램을 결합하여 완성된 프로그램을 만들 경우 각자 필요한 명칭을 독립적으로 만들어 사용할 수 있음
- 전역 명칭공간: 특정 명칭공간에 속하지 않는 기본 명칭공간
- std 명칭공간: 표준 C++라이브러리의 명칭들이 정의되어 있는 명칭공간
```c++
#include <iostream>

namespace myNSp1 { int n = 10; }
namespace myNSp2 { int n = 20; }
int n = 30;

int main()
{
  int n = 40;
  std::cout << myNSp1::n << std::endl; //결과 : 10
  std::cout << myNSp2::n << std::endl; //결과 : 20
  std::cout << ::n << std::endl; //결과 : 30
  std::cout << n << std::endl; //결과 : 40
  return 0;
}
```
- 'using'을 이용한 명칭공간 사용
  - 특정 명칭공간이나 명칭공간 내의 특정 이름을 **자주 사용**하는 경우 명칭공간 지정을 **간소화** 할 수 있음
  - ex) using namespace std;
  - ex) using std::cout;
  - ex) using std::endl;

```c++
#include <iostream>

using namespace std;
namespace myNSp1 { int n = 10; }
namespace myNSp2 { int n = 20; }
int n = 30;

int main()
{
  int n = 40;
  cout << myNSp1::n << endl; //결과 : 10
  cout << myNSp2::n << endl; //결과 : 20
  cout << ::n << endl; //결과 : 30
  cout << n << endl; //결과 : 40
  return 0;
}
```

---

[^TOP](#)

---