[<< BACK](https://github.com/dlalstj0213/CppStart)

---

# 📖 연산자 다중정의 (1)
- [📖 연산자 다중정의 (1)](#-연산자-다중정의-1)
  - [연산자 다중정의의 개념](#연산자-다중정의의-개념)
  - [단항 연산자의 다중정의](#단항-연산자의-다중정의)
  - [이항 연산자의 다중정의](#이항-연산자의-다중정의)
  - [스트림 출력 연산자의 다중정의](#스트림-출력-연산자의-다중정의)


## 연산자 다중정의의 개념

- ✅ **피연산자의 자료형과 연산자**
  - 동일한 연산자라도 구체적인 처리 방법은 피연산자의 자료형에 따라 다름
  - 연산자는 피연산자의 자료형에 따라 그것에 맞는 처리 절차가 정의되어 있음

- ✅ **연산자 다중정의란?**
  - C++에 정의된 연산자를 사용자가 선언한 클래스의 객체에 대하여 사용할 수 있도록 정의 하는 것

- ✅ **연산자 다중정의를 할 때 주의사항**
  - 연산자의 의미를 임의로 바꾸지 않는다.
  - 연산자의 고유한 특성이 유지되도록 한다.
    - 연산자의 우선순위나 피연산자 수 불변
    - 전위 표기와 후위 표기 연산자의 의미 유지

- ✅ **주요 연산자 다중정의 대상**
  - 클래스의 객체 간 대입 및 이동 대입 연산자
    - 특히 동적 할당을 받는 포인터를 포함하는 경우 고려할 필요가 있음
  - 수치형 객체의 산술 연산자 다중정의
    - 교환법칙도 함께 고려함
  - 두 객체를 비교하기 위한 관계 연산자의 다중정의
  - 스트림 입력 및 출력을 위한 >>, << 연산자

- ✅ **다중정의를 할 수 없는 연산자**
  - 멤버 선택 연산자(.)
  - 멤버에 대한 포인터 연산자(.*)
  - 유효범위 결정 연산자(::)
  - 조건 연산자(? :)

- ✅ **연산자 다중정의 위치**
  - 클래스의 멤버로 정의하는 방법
    - 연산자의 구현 과정에서 객체의 멤버를 액세스 할 수 있음
  - 클래스 외부에서 정의하는 방법
    - 클래스의 멤버가 아니므로, 객체의 private 멤버는 임의로 사용할 수 없음

## 단항 연산자의 다중정의

- ✅ **단항 연산자란?**
  - 피연산자가 1개인 연산자
  - 전위 표기법과 후위 표기법

<table style='text-align:center'>
    <thead>
    <tr>
        <th rowspan='2'>수식(a가 10일 때)</th>
        <th colspan='2'>실행결과</th>
    </tr>
    <tr>
        <th>a의 값</th>
        <th>b의 값</th>
    </tr>
    </thead>
    <tbody>
    <tr>
        <td>b = ++a;</td>
        <td>11</td>
        <td>11</td>
    </tr>
    <tr>
        <td>b = a++;</td>
        <td>11</td>
        <td>10</td>
    </tr>
    <tr>
        <td>b = --a;</td>
        <td>9</td>
        <td>9</td>
    </tr>
    <tr>
        <td>b = a--;</td>
        <td>9</td>
        <td>10</td>
    </tr>    
    </tbody>
</table>

- ✅ **전위 표기법 단항 연산자의 다중정의**
  - 다중정의 형식

    ```c++
    ReturnClass ClassName::operator opSymbol(){
        ......
    }
    ```
  - `opSymbol`: ++, -- 등의 단항 연산자 기호
  - 형식 매개변수 없음
  - ex)

      ```c++
      class IntClass1{
          int a;

          public:
            IntClass1(int n = 0) : a(n) {}    // 생성자
            IntClass1& operator ++() {    // 전위 표기 ++ 연산자 다중정의
                ++a;
                return *this;
            }
            int getValue() const {return a;}
      };

      int main(){
          IntClass1 i;
          cout << (++i).getValue() << endl; // 출력: 1
      }
      ```

- ✅ **후위 표기법 단항 연산자의 다중정의**
  - 다중정의 형식
    
    ```c++
    ReturnClass ClassName::operator opSymbol(int){
        ......
    }
    ```
  - `opSymbol`: ++, -- 등의 단항 연산자 기호
  - 형식 매개변수 표기 위치의 'int'는 인수 전달의 의미가 아니라 단지 후위 표기기법을 사용하는 단항 연산자임을 나타냄
  - ex)

    ```c++
      class IntClass2{
          int a;

          public:
            IntClass2(int n = 0) : a(n) {}    // 생성자
            IntClass2 operator ++(int) {    // 후위 표기 ++ 연산자 다중정의
                IntClass2 tmp(*this);
                ++a;
                return tmp;
            }
            int getValue() const {return a;}
      };

      int main(){
          IntClass2 i;
          cout << (i++).getValue() << endl; // 출력: 0
      }
    ```
- ✅ **예제: Pencils 클래스**
    
    |Pencils 클래스|
    |---|
    |n타 m자루 형태로 연필의 개수를 표현하는 클래스를 정의한다(1타는 12자루).<br>낱개의 수를 1개 증가시키는 전위 및 후위 표기 ++ 연산자를 포함하며<br>연필의 수량을 출력하는 메소드를 포함한다.|

    |멤버함수|비고|
    |---|---|
    |`Pencils()`|생성자(0으로 초기화)|
    |`Pencils(int n)`|생성자(n을 타와 낱개로 변환)|
    |`Pencils(int d, int n)`|생성자(d타 n자루로 초기화)|
    |`Pencils& operator ++()`|전위 표기 ++연산자|
    |`Pencils operator ++(int)`|후위 표기 ++연산자|
    |`void display()`|콘솔에 내용 출력|

    |데이터 멤버|비고|
    |---|---|
    |`int dozens`|타 수|
    |`int np`|낱개의 수|

  - Pencils.h

    ```c++
    #ifndef PENCILS_H_INCLUDED
    #define PENCILS_H_INCLUDED
    class Pencils{
        int dozens;
        int np;

        public:
            Pencils() : dozens(0), np(0) {}
            Pencils(int n){
                dozens = n / 12; np = n % 12;
            }
            Pencils(int d, int n) : dozens(d), np(n) {}
            Pencils& operator ++ ();
            Pencils operator ++ (int);
            void display() const;
    };
    #endif
    ```

  - Pencils.cpp

    ```c++
    #include <iostream>
    #include "Pencils.h"
    using namespace std;

    Pencils& Pencils::operator ++() {    // ++연산자(전위 표기)
        if(++np >= 12) ++dozens, np = 0;    // 낱개를 1 증가식킴. 결과가 12보다 크면 타수 1 증가시키고, 낱개는 0
        return *this;   // 증과된 결과를 반환
    }
    Pencils Pencils::operator ++(int) {  // ++연산자(후위 표기)
        Pencils tmp(*this); // 현재 객체를 보존
        if(++np >= 12) ++dozens, np = 0;    // 낱개를 1 증가시킴 결과가 12보다 크면 타 수 를 1 증가시키고, 낱개는 0
        return tmp; // 보존된 객체를 반환
    }
    void Pencils::display() const {
        if(dozens){
            cout << dozens << "타 ";
            if(np) cout << np << "자루";
            cout << endl;
        } else {
            cout << np <, "자루" << endl;
        }
    }
    ```

  - PnclMain.cpp

    ```c++
    #include <iostream>
    #include "Pencils.h"
    using namespace std;

    int main(){
        Pencils p1(5, 7);
        Pencils p2(23);

        p1.display();   // 출력: 5타 7자루
        (++p1).display();   // 출력: 5타 8자루
        p1.display();   // 출력: 5타 8자루
        cout << endl;
        p2.display();   // 출력: 1타 11자루
        p1 = p2++;
        p1.display();   // 출력: 1타 11자루
        p2.display();   // 출력: 2타 
        return 0;
    }
    ```


## 이항 연산자의 다중정의

- ✅ **다중정의 형식**
    
    ```c++
    ReturnClass ClassName::operator opSymbol(ArgClass arg){
        ......
    }
    ```
  - `opSymbol`: +, -, *, /, &&, || 등의 이항 연산자 기호
  - 객체 자신이 좌측 피연산자, `arg`가 우측 피연산자에 해당됨 

- ✅ **예제:  Complex2 클래스**
  - 복소수 객체와 복소수 객체의 덧셈 연산자
  - 수식: `complex2Obj1 + complex2Obj2`

    ```c++
    Complex2 Complex2::operator + (const Complex2& c) const {
        /* 방법 1
        Complex2 tmp(*this);
        tmp.rPart += c.rPart;
        tmp.iPart += c.iPart;
        return tmp;
        */

        // 방법 2 
        return Complex2(rPart + c.rPart, iPart + c.iPart);
    }
    ```

  - 복소수 객체와 실수의 덧셈 연산자
  - 수식: `complex2Obj + 10.0`

    ```c++
    Complex2 Complex2::operator + (double r) const {
        return Complex2(rPart + r, iPart);
    }
    ```
    - `Complex2(double r=0, double i=0)`이라는 생성자가 정의되어 있어 double 값이 묵시적으로 Complex2 객체로 형변환되므로, 이 연산자를 정의하지 않아도 Complex2 객체간 덧셈 연산자를 이용하여 수식을 처리할 수 있음

  - 실수와 복소수 객체의 덧셈 연산자
    - 좌측 피연산자가 실수이므로 Complex2 클래스의 멤버로 연산자를 정의할 수 없음
      - 클래스에 속하지 않은 외부의 별도 연산자로 정의함
    - 수식: `10.0 + complex2Obj`

    ```c++
    Complex2 operator + (double r, const Complex2 &c) {
        return Complex2(r + c.rPart, c.iPart);
    }
    // ERROR : private 멤버 사용
    ```

    - 해법1: Complex2에 private 멤버를 액세스할 수 있는 멤버함수 정의

    ```c++
    Class Complex2{
        double rPart, iPart;
        public:
            ......
            double real() const {return rPart;} // 실수부의 값 반환
            double imag() const {return iPart;} // 허수부의 값 반환
    };
    ```
    ```c++
    Complex2 operator + (double r, const Complex2 &c) {
        return Complex2(r + c.real(), c.imag());
    }
    ```

    - 해법2: Complex2에서 다중정의된 연산자를 `friend`로 선언

    ```c++
    Class Complex2 {
        double rPart, iPart;
        public:
            ......
            friend Complex2 operator + (double r, const Complex2 &c);
    };
    ```
    ```c++
    Complex2 operator + (double r, const Complex2 &c) {
        return Complex2(r + c.rPart, c.iPart);
    }
    ```

  - 복소수 객체의 복합 대입 연산자
  - 수식: `Complex2Obj1 += Complex2Obj2`

    ```c++
    Complex2& Complex2::operator += (const Complex2 &c) {
        rPart += c.rPart; 
        iPart += c.iPart;
        return *this;
    }
    ```

## 스트림 출력 연산자의 다중정의

- ✅ **<< 연산자를 정의할 위치**

    ```c++
    Complex2 c(1.0, 2.0);
    cout << c;
    ```
    - 좌측 피연산자인 `cout`이 Complex2의 객체가 아니며, `cout`이 속한 `ostream`클래스를 일반 프로그래머가 수정할 수 없음
    - 클래스에 속하지 않는 외부의 별도 연산자로 정의함
    - << 연산자가 Complex2 객체의 private 멤버를 액세스할 수 있게 `friend`로 지정

- ✅ **<< 연산자가 반환할 값**
  - `cout`을 통한 연속적인 출력 문장
  - `cout << "변수 a에 저장된 값 " << a;`

    ```c++
    Class Complex2{
        ......
        friend ostream& operator << (ostream &os, const Complex2 &c);
    }
    ```
    ```c++
    ostream& operator << (ostream& os, const Complex2 &c) {
        os << "(" << c.rPart;   // 실수부 출력
        if(c.iPart > 0) os << "+j" << c.iPart;
        else if(c.iPart < 0) os << "-j" << -c.iPart;
        os << ")";
        return os;
    }
    ```
    ```c++
    #include <iostream>
    #include "Complex2.h";
    using namespace std;

    int main(){
        Complex2 a(10, 20);
        Complex2 b(5, -3);
        cout << a << " + " << b << " = " << a + b << endl;
        // 출력: (10+j20) + (5-j3) = (15+j17)
        return 0;
    }
    ```

---

[^TOP](#)

---