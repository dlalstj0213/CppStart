[⏪BACK](https://github.com/dlalstj0213/CppStart)

---


# 📖 연산자 다중정의 (2)

- [📖 연산자 다중정의 (2)](#-연산자-다중정의-2)
  - [대입 및 이동 대입 연산자](#대입-및-이동-대입-연산자)
  - [[] 연산자의 다중정의](#-연산자의-다중정의)
  - [문자열 클래스](#문자열-클래스)
  - [자료형의 변환](#자료형의-변환)

## 대입 및 이동 대입 연산자

- ✅ **대입연산자**
  - 묵시적인 대입 연산자: 우측 피연산자 데이터 멤버를 좌측 피연산자에 그대로 복사함
  - 객체에 동적 할당된 메모리를 가리키는 포인터가 포함되어 있을 경우 얕은 족사로 인해 의도하지 않은 공유 상태의 문제가 발생할 수 있음
    - 깊은 복사를 할 수 있는 대입 연산자를 다중정의할 필요가 있음
    - ex) VecF 클래스의 대입 연산자 다중정의
    ```c++
    VecF& VecF::operator=(const VecF& fv){
        if(n != fv.n){  // 벡터의 크기가 다르다면
            deletep[] arr;  // 기존 메모리를 변환하고
            arr = new float[n = fv.n];  // 새로 메모리를 할당함
        }
        memcpy(arr, fv.arr, sizeof(float)*n);   // 데이터 복사
        return *this;
    }
    ```

- ✅ **이동 대입 연산자(=)**
  - 좌측 피연산자에 대입할 우측 피연산자가 *r-value*일 때 사용됨
    - 대입 후 우측 피연산자의 내용이 더 이상 필요 없는 상황
  - 우측 피연산자의 내용을 좌측 피연산자로 이동하여 불필요한 복사를 피함으로써 효율성을 높일 수 있음
    - ex) VecF 클래스의 대입 연산자 다중정의
    ```c++
    VecF& VecF::operator=(VecF&& fv){
        delete[] arr;   // 기존 메모리를 반환하고
        n = fv.n;   // 우측 피연산자의 내용을 이동함
        arr = fv.arr;
        fv.arr = nullptr;
        return *this;
    }
    ```

- ✅ **대입 및 이동 대입 연산자의 활용**
  - ex) VFMain3.cpp
    ```c++
    int main(){
        float a[3] = {1, 2, 3};
        float b[3] = {2, 4, 6};
        VecF v1(3, a);
        VecF v2(3, b);
        VecF v3(3);
        v3 = v1;    // 대입 연산자 (l-value)
        cout << v3 << endl;
        v3 = v1.add(v2);    // 이동 대입 연산자 (r-value)
        cout << v1 << " + " << v2 << " = ";
        cout << v3 << endl;
        return 0;
    }
    ```

- ✅ **`std::move` 함수의 활용**
  - 두 VecF 객체를 교환하는 함수의 구현 (1)
    ```c++
    void swapVecF(VecF& v1, VecF& v2){
        VecF tmp(v1);   // 복사 생성자
        v1 = v2;    // 대입 연산자 사용
        v2 = tmp;   // 대입 연산자 사용
    }

    int main(){
        float a[3] = {1, 2, 3};
        float b[3] = {2, 4, 6};
        VecF vec1(3, a), vec2(3, b);
        swapVecF(vec1, vec2);
        ......
    }
    ```

  - `std::move` 함수
    - 인수로 전달되는 객체의 *r-value*참조를 반환
    - ex) `VecF tmp = std::move(v1);`
      - v1의 r-value 참조를 구하여 tmp의 초기화에 사용
      - 이동 생성자를 이용하여 tmp 생성
    - ex) `v1 = std::move(v2);`
      - v2의 r-value 참조를 구하여 v1에 대입
      - 이동 대입 연산자 실행
  - 두 VecF 객체를 교환하는 함수의 구현 (2)
    ```c++
    void swapVecF(VecF& v1, VecF& v2){
        VecF tmp = move(v1);   // 이동 생성자
        v1 = move(v2);    // 이동 대입 연산자 사용
        v2 = move(tmp);   // 이동 대입 연산자 사용
    }

    int main(){
        float a[3] = {1, 2, 3};
        float b[3] = {2, 4, 6};
        VecF vec1(3, a), vec2(3, b);
        swapVecF(vec1, vec2);
        ......
    }
    ```

## [] 연산자의 다중정의

- ✅ **요구사항**
  - 배열처럼 지정된 개수의 `int` 값을 저장할 수 있다.
    - 예: `SafeIntArray a(10);` -> 10개의 `int` 값을 저장하는 객체
  - 각각의 값들은 0번부터 시작하는 일련번호를 첨자로 지정하여 액세스한다.
    - 예: `a[5] = 10;` -> 6번째 위치에 10을 저장함
  - 첨자가 지정된 범위를 벗어날 경우 오류 메시지를 출력한 후 프로그램을 종료한다.
    - 예: `cout << a[11];`

- ✅ **[] 연산자**
  - 배열의 첨자를 지정하는 이항 연산자
  - 피연산자: 배열과 첨자

- ✅ **데이터를 저장하기 위해 사용할 [] 연산자**
  - SafeIntArray a(10);
  - a[5] = 10;
    ```c++
    int& SafeIntArray::operator[](int i){
        ......
    }
    ```

- ✅ **`const` 객체를 위한 [] 연산자**
  - 데이터를 읽기만 할 수 있도록 [] 연산자를 정의함
    ```c++
    void f(const SafeIntArray& x){
        for(int i=0; i<x.size(); i++){
            cout << x[i] << endl;
        }
    }
    ```
    ```c++
    // ERROR: []는 x의 값을 수정활 수 있는 연산자임
    int& SafeIntArray::operator[](int i){
        .......
    }
    ```
    ```c++
    // GOOD
    int& SafeIntArray::operator[](int i) const {
        .......
    }
    ```

- ✅ **SafeIntArray.h**
    ```c++
    #include <iostream>

    class SafeIntArray{
        int limit;  // 원소의 개수
        int *arr;   // 데이터 저장공간
        public:
            SafeIntArray(int n): limit(n){
                arr = new int[n];   // 공간 할당
            }
            ~SafeIntArray(){
                delete[] arr;
            }
            int size() const { return limit; }
            // i번 원소를 반환하는 멤버함수
            int& operator[](int i){
                if(i < 0 || i >= limit){
                    std::cout << "첨자가 범위를 벗어나 프로그램을 종료합니다.";
                    exit(EXIT_FAILURE);
                }
                return arr[i];  // i번 원소 반환
            }
            // i번 원소를 반환하는 멤버함수(상수에 해당)
            int operatorp[](int i)const{    
                if(i < 0 || i >= limit){
                    std::cout << "첨자가 범위를 벗어나 프로그램을 종료합니다.";
                    exit(EXIT_FAILURE);
                }
                return arr[i];  // i번 원소 반환               
            }
    };
    ```
- ✅ **SafeArr.cpp**
    ```c++
    #include <iostream>
    #include "SafeIntArray.h"
    using namespace std;

    int main(){
        SafeIntArray a(10); // 10개의 원소를 갖는 객체 생성
        for(int i=0; i<10; i++)
            a[i] = i;
        cout << a[5] << endl;   // 올바른 범위의 원소 액세스
        cout << a[12] << endl;  // 범위를 벗어난 액세스
        return 0;
    }
    ```

## 문자열 클래스

- ✅ **C 스타일 문자열**
  - 문자열의 저장
    - 문자열의 끝을 알리기 위해 널(*null*)문자('\0')를 사용함
      - *Null-terminated string*
    - 문자열을 저장하기 위한 `char`형 배열
      - ex) `char str1[40] = "C style string";`
        |0|||||5|||||10|||||15||39|
        |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
        |C||s|t|y|l|e||s|t|r|i|n|g|`\0`||......||
      - ex) `char str2[40] = "Object-Oriented ";`
        |0|||||5|||||10|||||15||
        |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
        |O|b|j|e|c|t|-|O|r|i|e|n|t|e|d||`\0`|
      
    - 문자 리터럴
      - ex) `const char *str3 = "Programming"`
        |`str3`||0|||||5|||||10||
        |:-:|-|-|-|-|-|-|-|-|-|-|-|-|-|
        |`->`||P|r|o|g|r|a|m|m|i|n|g|`\0`|
  - C 스타일 문자열 처리 함수( 헤더 파일: `#include <cstring>` )
    - 문자열의 길이 구하기
      - `size_t strlen(const char* str);`
      - MS Visual C++의 보안개선 함수 제공

        - `size_t strnlen_s(const char* str, size_t nEl);` (보안강화)
          
          ```c++
          char str[10] = "abcde";
          n = strnlen_s(str, 10); // n = 5
          ```
    - 문자열 복사하기
      - `char* strcpy(char* strDestination, const char* strSource);`
        ```c++
        char str1[10] = "KNOU";
        strcpy(str1, "CS");
        ```
      - <주의!> 대입 명령으로 배열에 문자열 리터럴을 넣을 수 없음! `str1 = "cs"; // ERROR`
      - MS Visual C++의 보안개선 함수 제공
        
        - `errno_t strcpy_s(char* strD, size_t nEl, const char* strS);`
   
    - 문자열 연결하기
      - `char* strcat(char* strDestination, const char* strSource);`
        
        ```c++
        char str2[10] = "KNOU";
        strcat(str2, "CS"); // str2 = "KNOUCS"
        ```
      - MS Visual C++의 보안개선 함수 제공

        - `errno_t strcat_s(char* strD, size_t nEl, const char* strS);`

- ✅ **MyString 클래스**
  - 요구사항: 문자열을 저장하되 다음의 다중정의된 연산자를 포함하며, 실행시 필요에 따라 저장공간을 늘릴 수 있음

    |연산자|기능|
    |:--:|--|
    |=|대입 연산자. C 스타일 문자열이나 MyString 객체를 복사한다.|
    |+|문자열 연결 연산자. 두 문자열을 연결한 문자열을 구한다.|
    |+=|문자열을 뒤에 추가한다.|
    |==, >, <|관계연산자. 두 문자열의 등로 및 순서를 비교한다.|
    |<<|스트림 출력 연산자. 출력 스트림으로 문자열을 출력한다.|
    |[]|문자열 내의 개별 문자 접근|

    - 생성자 및 소멸자
      - `MyString();`
      - `MyString(const char* str);`
      - `MyString(const MyString& mstr);`
      - `MyString(MyString&& mstr);`
      - `MyString(int s); // private-내부용으로만 사용함`
      - `~MyString();`
    - 기타 메소드
      - `int length() const; // 문자열 길이 반환`
    - 데이터 멤버
      - `int len`: 문자열의 길이를 저장한다
      - `int bufSize`: 최대로 저장할 수 있는 문자열의 길이를 저장한다.
      - `char *buf`: 문자열 저장 공간

  - MyString.h
    ```c++
    #include <iostream>

    class MyString{
        int len;    // 문자열의 길이
        int bufSize;    // 저장 가능한 문자열의 길이
        char *buf;
        MyString(int s);    // 생성자(private)

        public:
            MyString(); // 디폴트 생성자
            MyString(const char *str);  // 생성자
            MyString(const MyString &mstr); // 복사 생성자
            MyString(MyString &&mstr);  // 이동 생성자
            ~MyString();    // 소멸자
            int length() const; // 문자열 길이 반환 메소드
            // 대입 연산자
            MyString& operator=(const MyString &mstr);
            // 이동 연산자
            MyString& operator=(MyString &&mstr);
            // 문자열 연결 연산자
            MyString& operator+(const MyString &mstr) const;
            MyString& operator+=(const MyString &mstr);
            bool operator==(const MyString &mstr) const;    // == 연산자
            bool operator>(const MyString &mstr) const; // > 연산자
            bool operator<(const MyString &mstr) const; // < 연산자
            char& operator[](int i);
            char operator[](int i) const;
            friend std::ostream& operator<<(std::ostream &os, const MyString &mstr);
    };

    // 스트림 출력 연산자
    inline std::ostream& operator<<(std::ostream &os, const MyString &mstr){
        os << mstr.buf;
        return os;
    }
    ```

  - MyString.cpp
    ```c++
    #include <iostream>
    #include <cstring>
    #include "MyString.h"

    MyString::MyString(int s) : len(s), bufSize(s){
        buf = new char[s + 1];
        buf[s] = '\0';
    }
    MyString::MyString() : len(0), bufSize(0){  // 디폴트 생성자
        buf = new char[1];
        buf[0] = '\0';
    }
    MyString::MyString(const char *str){    // 생성자
        len = bufSize s= strlen(str);   // 문자열 길이
        buf = new char[len + 1];    // 문자열 저장공간 할당
        strcpy(buf, str);   // 문자열 복사
    } 
    MyString::MyString(const MyString &mstr)    // 복사 생성자
        : len(mstr.len), bufSize(mstr.len){
        buf = new char[len + 1];
        strcpy(buf, mstr.buf);
    }
    MyString::MyString(MyString &&mstr) // 이동 생성자
        : len(mstr.len), bufSize(mstr.bufSize), buf(mstr.buf){
        mstr.buf = nullptr;
    }
    MyString::~MyString(){  // 소멸자
        delete[] buf;
    }
    int MyString::length() const {  // 문자열 길이 반환 메소드
        return len;
    }
    //대입 연산자
    MyString& MyString::operator=(const MyString &mstr){
        if(bufSize < mstr.len){ // 문자열 공간이 필요양보다 작으면
            delete[] buf;   // 기존 공간 반환
            len = bufSize = mstr.len;   // 새로운 문자열의 길이
            buf = new char[len + 1];    // 새로운 공간 할당
        } else  // 그렇지 않으면
            len = mstr.len; // 문자열의 길이만 수정
        strcpy(buf, mstr.buf);
        return *this;
    }
    // 이동 대입 연산자
    MyString& MyString::operator=(MyString &&mstr){
        delete[] buf;
        len = mstr.len;
        bufSzie = mstr.bufSize;
        buf = mstr.bufl
        mstr.buf = nullptr;
        return *this;
    }
    // 문자열 열결 연산자
    MyString MyString::operator+(cosnt MyString &mstr) const {
        MyString tmstr(len + mstr.len); // private으로 정의한 생성자
        strcpy(tmstr.buf, buf);
        strcpy(tmstr.bif + len, mstr.buf);
        return tmstr;
    }
    MyString& MyString::operator+=(const MyString &mstr){
        if(bufSize < len + mstr.len){
            char* tbuf = new char[(bufSize = len + mstr.len) + 1];
            strcpy(tbuf, buf);
            delete[] buf;
            buf = tbuf;
        }
        strcpy(buf + len, mstr.buf);
        len += mstr.len;
        return *this;
    }
    ......
    ```

  - MSMain.cpp
    ```c++
    int main(){
        MyString str1("MyString class");
        MyString str2("Object Oriented ");
        MyString str3;

        cout << str1 << endl;   // 문자열 출력
        str3 = "Programming";   // 묵시적 형 변환 및 이동 대입
        cout << str3 << "의 문자열의 길이는 ";
        cout << str3.length() << endl;  // 문자열 길이를 구하는 메소드
        str1 = str2;    // 대입 연산자로 문자열 복사
        cout << str1 << endl;
        str1 - str2 + str3;   // 문자열 연결 연산자, 이동 대입 연산자
    }
    ```

- ✅ **`string` 이란?**
  - 문자열을 저장하기 위한 표준 C++ 라이브러리의 클래스
    - `basic_string<char>`
  - 헤더파일: `#include <string>`
  - 연산자: [], +, =, +=, ==, !=, >, >=, <, <=, 스트림 입출력(<<, >>) 등
  - 멤버함수: length, append, find, c_str 등
  - 함수: stoi, stod, to_string, swap, getline 등

## 자료형의 변환

- ✅ **묵시적 형 변환**
  - MyString 클래스의 묵시적 형 변환
  - `str3 = "Programming";`

- ✅ **형 변환 연산자를 정의하는 위치**
  - 값을 제공하는 송신 측 클래스에서 정의하는 방법
    - 값을 받는 수신 측 클래스의 이름으로 연산자를 정의함
    - ex) MyString 클래스의 객체를 C 스타일 문자열로 변환하기
    ```c++
    class MyString{
        ......
        operator char*() const {
            char *pt = new char[length() + 1];
            strcpy(pt, buf);
            return pt;
        }
    };
    ```

  - 값을 제공받는 수신 측 클래스에서 정의하는 방법
    - 송신 측 클래스의 객체를 인수로 갖는 1 인수 생성자를 정의함
    - ex) `MyString(const char* str);`
    - 문제점: 송신 측 클래스의 private 멤버를 액세스해야 변환이 가능한 경우
      - 변환 대상 송신 측 클래스의 private 멤버를 액세스할 수 있는 멤버함수가 송신 측 클래스에 정의되어 있어야 함
      - ex) Meter 클래스와 Feet 클래스
        ```c++
        class Meter{
            int m;
            int cm;
            public:
                ......
                int getM() const { return m; }
                int getCM() const { return cm; }
        };
        ```
        ```c++
        class Feet{
            int ft;
            int in;
            public:
                ......
                Feet(const Meter &m){
                    int cmeter = m.getM()*100 + m.getCM();
                    in  = static_cast<int>(cmeter/2.54+0.5);
                    ft = in / 12;
                    in %= 12;
                }
                ......
        };
        ```

- ✅ **생성자를 이용한 묵시적 형 변환의 금지**
  - `explicit` 으로 선언된 생성자
    ```c++
    class MyString{
        ......
        explicit MyString(const char *str); // 생성자
        ......
    }
    // -> MyString str; 
    //    str = "Programming" => ERROR
    //    str = MyString{ "Programming" }; => GOOD
    //    str = static cast<MyString>("Programming"); => GOOD
    ```



---

[⏫TOP](#)

---