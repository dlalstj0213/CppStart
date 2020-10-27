[<< BACK](https://github.com/dlalstj0213/CppStart)

---

# 함수
- [함수](#함수)
  - [함수의 정의와 호출](#함수의-정의와-호출)
  - [인수의 전달](#인수의-전달)
  - [함수의 다중정의](#함수의-다중정의)
  - [inline 함수](#inline-함수)

## 함수의 정의와 호출
```c++
// 분산을 구하는 함수
double variance(const double arr[], int n) {
    double sum = 0, sqSum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        sqSum += arr[i] * arr[i];
    }
    return sqSum/n - sum * sum / (n * n);
}

int main(){
    double a[50], b[100];
    ...... // 생략: a와 b에 각각 50개와 100개의 데이터 입력
    cout << varience(a, 50) << endl;
    cout << varience(b, 100) << endl;
}
```
- **함수란?**
  - 필요한 작업을 수행하는 프로그램 문장들을 하나의 단위로 모아 놓고 **이름**을 부여한 것
  - 함수에 정의된 처리가 필요한 부분에서 **호출**하여 사용함
  - 매개변수를 통하여 함수에서 처리할 데이터(**인수**)를 전달함
  - 함수는 정해진 처리를 한 후 결과 값을 **반환**할 수 있음
  - 함수의 실행을 완료하면 **호출한 곳으로 복귀**함
  - C++ 프로그램은 함수를 기본 단위로 하여 구성됨
- **함수 정의 형식**
    ```c++
    ReturnType functionName(fParameterList) // 머리부
    { // 몸체 블록
        Type1 localVar1; // 지역 변수 선언
        Type2 localVar2;
        ......
        statement1; // 처리할 작업을 수행하는 문장
        statement2;
        ......
        return returnExpression; // 결과값을 반환함
    }
    ```
  - `fParameterList`: 인수를 받기 위한 형식 매개변수 선언
  - `ReturnType`: 함수의 결과로 반환하는 값의 자료형
  - `returnExpression`: 함수의 결과로 반환하는 값
  - return 명령
    - 함수를 마치고 함수를 호출한 곳으로 복귀하는 명령
    - 함수 안의 어느 곳이든 복귀를 위해 사용할 수 있음
    - *returnExpression*은 함수 머리부에 선언한 *ReturnType*과 일치하는 자료형의 수식 또는 **묵시적 형 변환이 가능한 자료형의 수식**을 사용함
    - 반환값이 없는 함수의 *ReturnType*은 **void**로 선언함
    - **main 함수**에서는 *return* 명령을 만나지 않은 상태로 함수의 끝에 도달하면 `return 0;`을 실행한 것과 같음
- **함수 호출 형식**
  1. `functionName(aParameterList);`
  2. `varName = functionName(aParameterList);`
     - `aParameterList`: 인수로 전달할 **실 매개변수** 나열
     - 형식a: 반환값 유무에 관계없이 사용 가능
     - 형식b: *ReturnType*이 *void*가 아닌 함수에 사용할 수 있음
  ```c++
  #include <iostream>
  using namespace std;
  // 화씨온도를 섭씨온도로 변환하는 함수
  // 매개변수 float fahr: 화씨온도
  // 반환값 섭씨온도(float)
  float FahrToc(float fahr){ // 매개변수의 fahr은 형식 매개변수이다.
      return (fahr - 32) * 5 / 9;
  }
  int main(){
      float fTemp, cTemp; // fTemp: 화씨온도, cTemp: 섭씨온도
      
      cout << "화씨온도 : ";
      cin >> fTemp;
      cTemp = FahrToc(fTemp); // 함수 호출, 여기서의 fTemp는 실 매개변수인다.
      cout << "---> 섭씨온도 : " << cTemp << endl;
      return 0; // main 함수는 return 생략 가능
  }
  ```
- **함수의 원형**
  - 정의된 함수가 뒤에 있거나 다른 파일에 있더라도 문제없이 정의한 함수를 호출할 수 있음
  ```c++
  float FahrToc(float fahr); // 함수의 원형

  int main(){
      float fTemp, cTemp;
      ......
      cTemp = FahrToc(fTemp);
      /*
      호출 함수가 main 함수보다 뒤에 있다면 함수 원형을 정의하거나
      main 함수보다 먼저 선언 되어야 한다.
      */
      return 0;
  }

  float FahrToc(float fahr){
      return (fahr - 32) * 5 / 9;
      /*
      main 함수보다 뒤에 있기 때문에 컴파일시 문제가 생긴다.
      하지만 함수의 원형을 정의 한다면 문제없이 컴파일 및 실행 가능하다.
      */
  }
  ```
- **장점**
  - 의미 있는 작업 단위로 모듈화
    - 간결하고 이해하기 쉬운 프로그램을 만들 수 있음
  - **반복** 사용되는 코드의 **중복 방지**
  - 잘 설계된 함수는 다른 응용에서 **재사용**할 수 있음
- **단점**
  - 함수 호출과 복귀 과정에서 **처리 시간이 추가**됨
    - 매우 효율적으로 동작해야 하는 함수라면 **inline 함수**로 선언함


## 인수의 전달
- **인수**
  - 함수 호출 문장에서 함수에 전달하는 값
  - 매개변수를 통해 인수를 전달함
- **매개변수**

|실 매개변수(actual parameter)|형식 매개변수(formal parameter)|
|--|--|
|- 함수 호출 문장에서 함수의 형식<br>매개변수에 전달할 값|- 인수를 전달받기 위해 함수에<br>선언된 매개변수<br>- 함수 헤더에 매개변수의 자료형과<br>이름을 선언함|

- **인수 전달 방식**
  - 값 호출(call-by-value)
    - 실 매개변수의 **값**을 형식 매개변수에 **복사**함
    - 장점
      - 실 매개변수와 형식 매개변수는 별개의 데이터이므로 불필요한 부작용이 발생하지 않음
    - 단점
      - 구조체와 같이 **많은 양의 데이터로 구성된 인수를 전달할 경우** 데이터의 복사량이 많아짐
  - 참조 호출(call-by-reference)
    - 실 매개변수의 **참조**를 형식 매개변수에 전달함
    - 함수에서 **형식 매개변수의 값을 변경**하는 것은 **실 매개변수의 값을 변경**하는 것과 같음
    - 형식 매개변수에 복사되는 데이터의 양은 **실 매개변수의 크기와 관계 없이 일정함**
      - 많은 양의 데이터로 구성되는 구조체나 객체를 인수로 전달하는 경우 효율적임
    - ex)
    ```c++
    #inclue <iostream>
    using namespace std;
    void SwapValues(int &x, int &y); //원형

    int main(){
        int a, b;

        cout << "두 수를 입력하시오 : ";
        cin >> a >> b;
        if(a < b) SwapValues(a, b); // 순서를 바꿔 a에 큰 값을 넣음
        cout << "큰 수 = " << a << " 작은수 = " << b << endl;
        return 0;
    }

    void SwapValues(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
    }
    ```
  - 참조 호출을 통한 효율적인 인수 전달
    - 많은 양의 데이터로 구성되는 구조체나 객체를 인수로 전달하는 경우 값 호출을 사용하는 것에 비해 참조 호출을 사용하는 것이 효율적임
    - 함수 호출의 효율성을 위해 참조 호출을 하지만 실 매개변수의 값이 변경되는 것을 원하지 않는 **형식 매개변수에는 const를 한정어**를 지정하여 실 매개변수를 보호함
- **const 매개변수**
  - const 한정어를 이용한 실 매개변수 보호
    ```c++
    struct SalesRec{
        char pID[10]; // 10바이트
        int dYear, dMonth, dDate; // 12바이트
        char deliverAddr[40]; // 40바이트
        // 총 62바이트(64바이트), 논리적으로는 62바이트지만 물리적으로는 64바이트로 저장하는데 사용됨
    }

    void PrSalesRec(const SalesRec &srec){ // 4바이트 복사, const의 매개변수
        cout << "품목코드 : "<< srec.pID << endl;
        cout << "배달일자 : "<< srec.dYear << "년 ";
        cout << srec.dMonth << "월 ";
        cout << srec.dDate << "일 " << endl;
        cout << "배달주소 : " << srec.deliverAddr << endl;
    }
    ```
- **디폴트(default) 인수**
  - 인수의 디폴트 값을 지정하는 방법
    - 일반적으로 사용되는 디폴트 값이 있는 인수의 경우 함수를 정의할 때 그 값을 미리 지정할 수 있음
  - ex)
  ```c++
  ......
  double Round(double x, int d = 0);
  
  int main(){
      double a;
      cout << "값 = ";
      cin >> a;
      cout << "반올림 --> " << Round(a) << endl;
      cout << "반올림 --> " << Round(a, 1) << endl;
      cout << "반올림 --> " << Round(a, 2) << endl;
      cout << "반올림 --> " << Round(a, 3) << endl;
      return 0;
  }

  double Round(double x, int d){ //default 인수는 한 번 만 정의함
      double a = x >= 0 ? 0.5 : 0.5;
      double pow10 = pow(10, d);
      return trunc(x * pow10 + a) / pow10;
  }
  ```
  - 주의사항
    - 디폴트 인수는 인수 중 끝에만 위치할 수 있음
    - `void f(int x, int y=10, int z=20); // OK`
    - <del>`void g(int x, int y=10, int z);`</del> 오류
    - `f(5); // OK` -> x=5, y=10, z=20 전달
    - `f(5, 100); // OK` -> x=5, y=100, z=20 전달
    - `f(5, 100, 200); // OK` -> x=5, y=100, z=200 전달
    - <del>`f(5, , 300);`</del> 오류 -> `f(5, 10, 300);`으로 작성

## 함수의 다중정의
- **다중정의(overloading)란?**
  - 동일한 이름에 대하여 여러 가지 의미를 부여하는 것
- **함수 다중정의**
  - 동일한 이름을 갖는 함수를 **여러 개** 정의하는 것
  - 동일한 개념의 처리를 여러 가지 데이터나 객체에 대해 **각각의 대상에 맞는** 처리를 해야 할 경우 사용함
  - 다중정의된 함수의 구분: 인수의 개수 및 자료형
    - <!> 함수의 반환 자료형으로 함수를 구분할 수 없음
    ```c++
    // 시간 구조체
    struct TimeRec{
        int hours;
        int minutes;
    };

    // 시간을 더하는 함수
    // 인수 TimeRec &t1 : 누계할 시간
    // const TimeRec &t2 : 더할 시간
    // 반환값 없음
    void AddTime(TimeRec &t1, const TimeRec &t2){
        t1.minutes += t2.minutes;
        t1.hours += t2.hours + t1.minutes / 60;
        t1.minutes %= 60;
    }

    void AddTime(TimeRec &t, int minutes){
        t.minutes += minutes;
        t.hours += t.minutes / 60;
        t.minutes %= 60;
    }

    int main(){
        TimeRec tRec1 = {2, 30};
        TimeRec tRex2 = {1, 45};

        cout << tRec1.hours << "시간 " << tRec1.minutes << "분 + ";
        cout << tRec2.hours << "시간 " << tRec2.minutes << "분 = ";
        AddTime(tRec1, tRec2);
        cout << tRec1.hours << "시간 " << tRec1.minutes << "분" << endl;

        cout << tRec1.hours << "시간 " << tRec1.minutes << "분 + ";
        cout << "135분 = ";
        AddTime(tRec1, 135);
        cout << tRec1.hours << "시간 " << tRec1.minutes << "분" << endl;
        return 0;
    }
    ```
  - <!> 주의: 모호한 함수 다중정의
    ```c++
    void f(int a, int b){
        ......
    }
    int f(int a, int b){
        ......
    }
    int main(){
        f(10, 20);
    }
    // ERROR
    ```
    ```c++
    void g(int a){
        ......
    }
    void g(int a, int b = 100){
        ......
    }
    int main(){
        g(10, 20);
        g(10);
    }
    // ERROR
    ```
    ```c++
    void h(int a){
        ......
    }
    void h(float a){
        ......
    }
    int main(){
        h(10);
        h(10.0f);
        h(10.0); // double 타입: 형 변환 대상이 모호
    }
    // ERROR
    ```
## inline 함수
- **inline 함수란?**
  - **함수 호출 절차를 따르지 않고** 함수 호출 위치에 **함수의 처리 문장이 삽입되게 번역하도록 선언된 함수**
  - 함수를 사용합으로써 얻을 수 있는 **모듈화의 장점**을 살리면서, 함수 호출에 따른 **부수적인 처리시간이 생략**됨
  - 함수 호출 루틴으로부터 함수로 넘어가는 부분의 **코드가 최적화**가 가능해짐
    - 매우 빈번히 호출되며 빠른 실행이 요구되는 함수를 inline 함수로 선언하면 성능을 높이는데 도움이 됨
  - <!> 주의: inline 함수로 선언하더라도 반드시 inline으로 번역되는 것은 아님
    - inline 선언을 무시하고 일반 함수로 번역하는 경우
      - 함수가 너무 큰 경우
      - 순환/재귀 호출(recursive call)을 하는 경우
      - 프로그램 내에서 그 함수에 대한 포인터를 사용하는 경우
    ```c++
    // inline 함수는 함수가 호출 되는 것이 아니라 함수에 정의 된 코드가 호출한 부분에 그대로 쓰여짐
    inline void SwapValues(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
    }

    int main(){
        int a, b;
        cout << "두 수를 입력하시오 : ";
        cin >> a >> b;
        if(a<b) SwapCalues(a, b);
        cout << "큰 수 : " << a << " 작은 수 : " << b << endl;
        return 0;
    }
    ```
---

[^TOP](#함수)

---