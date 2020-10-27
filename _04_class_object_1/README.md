[<< BACK](https://github.com/dlalstj0213/CppStart)

---

# 클래스와 객체 (1)
- [클래스와 객체 (1)](#클래스와-객체-1)
  - [객체지향 프로그래밍의 주요 개념](#객체지향-프로그래밍의-주요-개념)
  - [클래스 선언과 객체 정의](#클래스-선언과-객체-정의)
  - [예제 - Counter 클래스](#예제---counter-클래스)
  - [생성자](#생성자)
  - [소멸자](#소멸자)


## 객체지향 프로그래밍의 주요 개념
- **객체란?**
  - 소프트웨어 시스템 안의 어떠한 대상을 표현한 것으로
    - 정해진 처리를 수행함 **-> 행위, 메소드, 멤버함수**
    - 처리 과정에 따라 내부 상태가 변화할 수 있음 **-> 속성, 데이터 멤버**
    - 다른 객체와 상호작용 할 수 있음 **-> 메시지 전달(멤버함수 호출)**

- **클래스(class)란?**
  - 객체의 설계도
  - 객체가 포함할 **속성에 대한 명세**와 **메소드의 정의**를 포함함

- **캡슐화(encapsulation)란?**
  - 객체 내부의 상세한 구현 부분과 외부 사용자의 관점을 분리함
    - 내부 속성 등 구현에 대한 부분은 공개하지 않으며(**정보은닉**), 객체 외부에서는 **공개된 인터페이스를 통해 객체를 사용**할 수 있음
  - 장점
    1. **소프트웨어의 유지보수가 용이함**: 프로그램의 다른 부분에 영향을 미치지 않고 객체 내부 구현 방법을 수정할 수 있음
    2. **재사용이 용이함**: 잘 설계된 캡슐화된 객체는 다른 응용에서도 재사용할 수 있어 소프트웨어 개발 비용을 줄일 수 있음

- **상속**
  - 클래스의 **계층적 설계**
  - 기초 클래스 -> 파생 클래스


## 클래스 선언과 객체 정의
- **클래스 선언**
  - 클래스
    - 표현하고자 하는 대상의 메소드와 속성을 선언한 것
        |클래스|내용|
        |---|---|
        |속성|- 객체의 상태를 표현<br>- **데이터 멤버**|
        |메소드|- 객체의 행위를 정의<br>- **멤버 함수**|
  - 클래스 선언문의 형식
    ```c++
    class ClassName{
        가시성_지시어_1:
            데이터 멤버 또는 멤버함수 리스트;
        가시성 지시어_2:
            데이터 멤버 또는 멤버함수 리스트;
            ......
    }; // 세미클론 꼭 작성
    ```
    - 가시성 지시어
      - 클래스 멤버가 공개되는 범위를 나타냄
      - 종류: `private`, `public`, `protected`
        |가시성 지시어|공개 범위|
        |:---:|---|
        |private<br>(디폴트)|- 소속 클래스의 멤버함수<br>- 친구 클래스의 멤버함수 및 친구함수<br>- 그 외의 범위에는 비공개|
        |public|- 전 범위|

        |가시성 지시어|용도|
        |:--:|---|
        |private<br>(디폴트)|- **정보은닉**을 위해 사용됨<br>- 클래스의 구현을 위한 내부 상태(데이터 멤버)는 일반적으로 private으로 지정함|
        |public|- 주로 외부에 제공할 인터페이스를 공개하기 위해 사용됨|
        ```c++
        class CircleClass{
            // 기본적으로(default) 가시성 지시어를 선언하지 않으면 private 이다
            C2dType center; // private 
            double radius; // private
            
            public:
            void init(){......}
            double area() const{......}
            bool chkOverlap() const{......}
            void display() const{......}
        };
        ```
- **객체의 정의 및 사용**
  - 객체 정의 형식
    1. `ClassName objName;`
    2. `ClassName objName1, objName2, ...;`
    - ex)
      ```c++
      int main(){
          CircleClass c1, c2;
          ......
      }
      ```
  - 객체 사용 형식
    - 객체 이름에 멤버선택 연산자`.`를 사용하여 객체의 멤버를 액세스함
    ```c++
    cin >> objName.dataMember;
    objName.memFunc(.....);
    ```
    - 객체의 멤버함수 안에서 그 객체에 속한 멤버를 사용할 때는 멤버 이름만으로 액세스함


## 예제 - Counter 클래스
- **Counter 클래스의 명세**
    |Counter 클래스|
    |:---|
    |계수기를 나타내는 클래스를 선언하라.<br>계수기 객체는 값을 0으로 지울 수 있고(*reset*),<br>값을 1씩 증가시킬 수 있으며(*count*),<br>현재의 계수기 값을 알려줄 수 있다.|
  - 행위
    |메소드|비고|
    |---|---|
    |`void reset()`|계수기의 값을 0으로 지움|
    |`void count()`|계수기의 값을 +1 증가시킴|
    |`int getValue()`|계수기의 현재 값을 알려 줌|
  - 속성  
    |속성|비고|
    |---|---|
    |`int value`|계수기의 현재 값을 저장|
  - UML 도안 표기법
    |Counter|
    |---|
    |-value:int|
    |+reset():void<br>+count():void<br>+getValue():int|

- **소스 파일의 구성 (정해진 법칙은 없음)**
    ```c++
    // ClassA.h

    // 일반적으로 클래스 선언문은 헤더 파일에 선언해주는 것이 좋다
    class ClassA{
        // 클래스 멤버 선언
        ......
    };
    ```
    ```c++
    // 멤버함수가 너무 커서 별도로 바깥에다가 선언할 경우 일반적으로 .cpp에다가 선엄함
    #inclue "ClassA.h"
    // 클래스 멤버 정의
    void ClassA::f(){......}
    ......
    ```
- **헤더파일 내용의 중복 include 방지**
  - ERROR
    ```c++
    // Counter.h
    class Counter{

    };
    ```
    ```c++
    // ClassA.h
    #include "Counter.h"
    class ClassA{

    };
    ```
    ```c++
    // Main.cpp
    // include를 통해 선행처리 결과 Counter클래스가 중복 선언이 될 수 있다.
    #include "Counter.h"
    #include "ClassA.h"

    int main(){
        ......
    }
    ```
    - Solution: `#ifndef`,`#define`,`#endif`를 통해 해결
    ```c++
    // Counter.h
    #ifndef COUNTER_H_INCLUDED
    #define COUNTER_H_INCLUDED

    class Counter{

    };
    #endif // COUNTER_H_INCLUDED
    // 이미 Counter.h가 이미 include 되었다면 #ifndef 부터 #endif 까지의 정의된 것을 건너띈다.
    ```
    ```c++
    // ClassA.h
    #ifndef CLASSA_H_INCLUDED
    #define CLASSA_H_INCLUDED
    #include "Counter.h"

    class ClassA{

    };
    #endif // CLASSA_H_INCLUDED
    ```
    ```c++
    // Main.cpp
    #include "Counter.h"
    #include "ClassA.h"

    int main(){
        ......
    }
    ```
    <!> `#pragma once` : 한 번만 번역(선행처리)되게하는 명령어 (`#ifndef`,`#define`,`#endif`와 동일한 동작)
    <br>( 초기의 버전(예전 환경)에서는 동작하지 않을 수 있음 )

- **Counter 클래스의 선언 - Counter.h**
  - Counter.h
    ```c++
    #ifndef COUNTER_H_INCLUDED
    #define COUNTER_H_INCLUDED

    class Counter{  // 클래스 Counter의 선언 시작
        int value;  // private 데이터 멤버

        public: // public 멤버 함수
            Counter(){
                value = 0;
            }
            void reset(){   // 계수기의 값을 0으로 지움
                value = 0;
            }
            void count(){   // 계수기의 값을 1 증가
                ++value;
            }
            int getValue() const{ // 계수기의 현재 값을 반환
                return value;
            }
        // 함수를 클래스 선언문 안에다가 선언한 경우 reset(), count(), getValue()는 inline함수로 선언된 효과를 가진다.
        // inline 함수: 함수 호출 과정을 생략을 하고 그 함수의 코드를 그대로 호출 문장에 삽입 되게끔 만들어줌
    }; 

    #endif
    ```
  - CntMain.cpp
    ```c++
    #include <iostream>
    #include "Counter.h"
    using namespace std;

    int main(){
        Counter cnt;    // Counter 객체의 정의
        cnt.reset();    // 계수기를 0으로 지움
        cout << "계수기의 현재 값 : " << cnt.getValue() << endl;
        cnt.count();    // 계수기를 1 증가시킴
        cnt.count();
        cout << "계수기의 현재 값 : " << cnt.getValue() << endl;
        return 0;
    }
    ```
- **const 멤버함수**
  - 데이터 멤버의 값을 수정하지 않는 멤버함수
  - `int getValue() {return value;}`
    ```c++
    const Counter c;
    int n = c.getValue(); // OK
    c.count(); // ERROR
    ```


## 생성자
- **생성자(constructor)란?**
  - **객체가 생성될 때 수행할 작업**을 정의하는 특수한 멤버함수
  - **매개변수를 통해** 인수를 전달할 수 있으며, **다중정의**를 할 수 있음


- **생성자 특성**
  - **클래스의 이름**을 사용하여 선언함
  - 생성자 머리에 **반환 자료형을 표시하지 않으며**, return 명령으로 **값을 반환할 수 없음**
  - 생성자를 public으로 선언해야 클래스 외부에서 객체를 생성할 수 있음

- **생성자 선언 형식**
    ```c++
    class ClassName{
        ......
        public:
            ClassName(fParameterList){
                ......  // 객체 생성을 위한 준비 작엄
            }
            ......
    }
    ```

- **초기화 리스트**
  - 생성자의 머리에 데이터 멤버를 초기화하는 값들을 나열한 리스트
  - `데이터 멤버이름{초기값}` 형태로 초깃값을 지정 <!>주의: 대입이 아니라 초기화를 시키는 것임
    ```c++
    class Counter{
        int value;
        
        public:
            Counter() : value{0} {
                // 생성자 바디 부분은 아무 동작이 없더라도 블록을 사용해 바디를 표현해야한다.
            } // 생성자
            // value() 를 쓸 수 있지만 C++11부터는 {}를 쓰도록 권장함
            ......
    }
    ```

## 소멸자
- **소명자(destructor)란?**
  - **객체가 소멸될 때 수행할 작업**을 정의하는 특수한 멤버함수

- **소멸자의 특성**
  - **클래스의 이름**에 `~`를 붙여 선언함
  - 소멸자 머리에 반환 자료형을 표시하지 않으며, *return* 명령으로 값을 반환할 수 없음
  - 매개변수를 포함할 수 없음
  - 다중정의할 수 없으며, **클래스에 하나만 정의**함
  - 일반적으로 `public`으로 선언하는 것이 일반적임
  - **상속을 통해 파생 클래스를 정의하는 경우**, `virtual`을 지정하여 가상함수가 되도록 하는 것이 좋음

- **소멸자 선언 형식**
    ```c++
    class ClassName{
        ......
        public:
            ClassName(fParameterList){
                ......  // 객체 생성을 위한 준비 작업
            }
            ~ClassName(){
                ......  // 객체 제거를 위한 정리 작업: 소멸자
            }
            ......
    }
    ```

- **Person 클래스의 명세**
    |Person 클래스|
    |---|
    |사람을 나타내는 클래스를 선언하고자 한다.<br>사람 객체는 '~에 사는 ~입니다.'라고 자신을 알릴 수 있으며,<br>주소를 변경할 수 있다.|

    |메소드|비고|
    |---|---|
    |`Person(char *name, char *addr)`|생성자|
    |`~Person()`|소멸자|
    |`void print()`|'~에 사는 ~입니다'라고 출력함|
    |`void chAddr(char *newAddr)`|주소를 변경함|

    |속성|비고|
    |---|---|
    |`char *name`|이름을 저장함|
    |`char *addr`|주소를 저장함|

- **Person 클래스의 선언 - Person.h**
    ```c++
    #ifndef PERSON_H_INCLUDED
    #define PERSON_H_INCLUDED
    
    class Person{
        char *name; // 클래스 Person의 선언 시작
        char *addr; // 이름을 저장하는 데이터멤버

        public: // public 멤버함수
            Person(char *name, char *addr); // 생성자
            ~Person();  // 소멸자
            void print() const; // 이름과 주소 출력
            void chAddr(const char *newAddr); // 주소 변경
    };

    #endif
    ```

- **Person 클래스의 선언 - Person.cpp**
    ```c++
    #include <iostream>
    #include <cstring>
    #include "Person.h"
    using namespace std;

    //Person::란 ::뒤의 Person이라는 것이 Person 클래스에 속하는 멤버라는 의미, 즉 Person의 생성자를 선언하고 있다는 것을 정의해야함
    Person::Person(const char *name, const char *addr){ // 생성자
        // 이름을 저장할 공간 할당
        // 여기서의 this는 Person객체 자신을 가리키는 pointer를 의미
        this -> name = new char[strlen(name)+1]; // strlen: 문자열의 길이를 구하는 함수

        // 데이터 멤버 name에 이름을 복사
        strcpy(this -> name, name); // strcpy: 문자열을 복사해 주는 함수
        
        // 주소를 저장할 공간 할당
        this -> addr = new char[strlen(addr)+1];
        
        // 데이터 멤버 addr에 주소를 복사
        strcpy(this -> add, addr);
        cout << "Person 객체 생성함(" << name << ")" << endl;
    }

    // strlen에 +1 을 왜 했을까? 
    /*
    예를 들어 "abc"는 문자열의 길이가 3이지만 끝에 +1을 해줘서 문자열이 끝났다는 것을 알리기 위함.
    즉, 만약 char[] 배열에 {'a', 'b', 'c'}가 들어갔다면, 
    실제 메모리에서는 끝 빈자리에 null문자인 '\0'이라는 코드가 들어간다. {'a', 'b', 'c', '\0'}
    */
    // this?
    /*
    this는 객체 자기 자신을 가리키는 포인터이다. 그러므로 Person.cpp의 this->name처럼 표기하면
    객체의 데이터 멤버 name을 지칭하는 것이다.
    */
    
    Person::~Person(){  // 소멸자
        cout << "Person 객체 제거함(" << name << ")" << endl;
        delete [] name; // 이름 저장 공간 반납
        delete [] addr; // 주소 저장 공간 반납
    }

    void Person::print() const{
        cout << addr << "에 사는 " << name << "입니다." << endl;
    }

    void Person::chAddr(const char *newAddr){
        delete [] addr; // 기존 공간 반납
        // 새로운 주소에 맞는 공간 할당
        addr = new char[strlen(newAddr)+1];
        strcpy(addr, newAddr);  // 데이터멤버 addr에 새로운 주소를 복사
    }
    ```
    
- **Person 클래스의 선언 - PrsnMain.cpp**
    ```c++
    #include <iostream>
    #include "Person.h"
    using namespace std;

    int main(){
        Person *p1 = new Person("이철수", "서울시 종로구");
        Person *p2 = new Person("박은미", "강원도 동해서");
        p1 -> print();
        p2 -> print();
        cout << endl << "주소 변경 : ";
        p2 -> chAddr("대전시 서구");
        p2 -> print();
        delete p1;
        delete p2;
        return 0;
    }
    ```
---

[^TOP](#클래스와-객체-1)

---