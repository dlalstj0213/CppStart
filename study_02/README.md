[<< BACK](../)

---

# C++ 기초(2)
- [C++ 기초(2)](#c-기초2)
  - [흐름제어 구문](#흐름제어-구문)
  - [구조체와 클래스](#구조체와-클래스)
  - [배열](#배열)
  - [포인터와 동적 메모리 할당](#포인터와-동적-메모리-할당)
  - [참조](#참조)


## 흐름제어 구문
- **조건문**
  - 지정된 조건에 따라 실행 흐름을 제어하는 문장
  - if문, switch문
  - if문 사용 형식
    ```c++
    if(a > b)
        cout << a << endl; //조건이 참일 때 실행할 문장
    else
        cout << b << endl; //조건이 거짓일 때 실행할 문장
    ```
    ```c++
    //변수 a와 b에 저장된 값 중 큰 값을 a에, 작은 값을 b에 저장하기
    if(a < b){
        //조건이 참일 때 실행할 문장
        int t = a; // t는 블록 내의 지역변수
        a = b;
        b = t;
    }
    ```
  - switch문 사용 형식
    ```c++
    switch(정수형_수식){
        case 값1;
        문장1; //정수형_수식 == 값1일때 실행할 문장들 나열
        break; //switch문을 빠져 나가게 함
        case 값2:
        문장2; //정수형_수식 == 값2일때 실행할 문장들 나열
        break; //switch문을 빠져 나가게 함
        ......
        default:
        문장n; //정수형_수식의 값과 일치하는 case값이 없을때 실행할 문장들 나열
    }
    ```
    ```c++
    // int형 변수 score의 값에 따라 A~F학점 부여하기
    switch(score / 10){
        case 10:    // score가 100인 경우
        case 9: // score가 90~99인 경우
            grade = 'A';
            break;
        case 8: // score가 80~89인 경우
            grade = 'B';
            break;
        case 7: // score가 70~79인 경우
            grade = 'C';
            break;
        case 6: // score가 60~69인 경우
            grade = 'D';
            break;
        default:    // score가 59이하인 경우
            grade = 'F';
    }   
    ```
- **반복문**
  - 정해진 범위의 문장을 반복적으로 실행하게 하는 문장
  - for문, while문, do-while문
  - for문 사용 형식
    ```c++
    for(초기화 문장; 반복조건; 증감_문장)
        반복할 문장;
    ```
    ```c++
    // 10개의 정수 값을 읽어 합을 구하기
    int val , total = 0;
    for(int i=0; i<10; i++){
        cin >> val;
        total += val;
    }
    ```
  - 범위 기반 for 루프(c++11 이후)
    ```c++
    for(원소 선언 : 데이터집합)
        반복할 문장;
    ```
    ```c++
    // 배열 안의 모든 값을 합산하기
    int arr[5] = {2, 3, 9, 4, 7};
    int sum = 0;
    for(int a : arr)
        sum += a;
    cout << "합계 = " << sum << endl;
    ```
    ```c++
    // 배열 안의 모든 값을 1씩 증가시키기
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int& a : arr) //'&': 참조 기호, 참조를 한다는 의미
        ++a;
    ```
  - while문 사용 형식
    ```c++
    while(반복조건)
        반복할_문장;
    ```
    ```c++
    // for루프를 while루프로 표현하기
    int val, total = 0;
    for(int i=0; i<10; i++){
        cin >> val;
        total += val;
    }

    int i = 0;
    while(i<10){
        cin >> val;
        total += val;
        i++;
    }
    ```
  - do-while문 사용 형식
    ```c++
    do{
        반복할_문장;
    } while(반복조건);
    ```

## 구조체와 클래스
- **구조체란?**
  - 여러 가지 자료형의 데이터 집합을 저장할 수 있는 새로운 자료형을 정의한 것
  - 구조체 선언문 형식
    ```c++
    struct StructName{
        Type1 item1;
        Type2 item2;
        ......
    };
    ```
  - 구조체 예 (활용 예제 참조: [step_00.cpp](https://github.com/dlalstj0213/CppStart/blob/master/study_02/step_00.cpp))
    ```c++
    // 2차원 좌표
    struct C2dType{
        double x, y;
    };

    // 원
    struct CircleType{
        C2dType center;
        double radius;
    }
    ```
- **클래스란?**
  - 표현 대상이 어떤 일을 할 수 있는가(**행위**)와 어떤 데이터를 저장하는가(**속성**)를 하나의 단위로 묶어 선언한 것
  - ex) '원' 클래스 (활용 예제 참조: [step_01.cpp](https://github.com/dlalstj0213/CppStart/blob/master/study_02/step_01.cpp))
    |클래스||
    |:---:|---|
    |행위|init: 원의 초기화<br>area: 원의 면적을 계산<br>chkOverlap: 다른 원과 중첩 여부 검사<br>display: 원의 정보 디스플레이|
    |속성|center: 중심 좌표<br>radius: 반경|
    ```c++
    class CircleClass{
        C2dType center; // 중심 좌표
        double radius; // 반경
        public: 
        void init(double cx, double cy, double r){...}
        double area() const{...}
        bool chkOverlap(const CircleClass& c) const{...}
        void display() const{...}
    };
    ```
- **구조체와 클래스의 문법적 차이**
  - 사실 **C언어에서와는 달리** C++언어에서는 구조체에 대해서도 클래스처럼 함수를 함께 정의가 가능하다. 문법적으로 약간의 차이는 있다. 예를 들어 특별히 지정하지 않은 경우, 구조체에서는 모든 데이터나 함수가 공개되나, 클래스에서는 공개되지 않는다. 이러한 차이점에도 불구하고 문법적으로는 구조체나 클래스를 같이 쓸 수 있다. 하지만 대상물의 **데이터만을 표현하고자 할 때에는 구조체**를, **데이터와 함수를 함께 묶어 정의하고자 할 때에는 클래스**를 사용하는 것이 **일반적**이다.
  
## 배열
- **배열이란?**
  - **동일한 자료형의 값**을 여러 개 저장할 수 있는 **연속적으로 할당된 공간**을 묶어 하나의 이름을 갖는 변수로 만든 것
  - 각각의 원소는 **0번부터 시작**하여 차례로 부여된 **번호**(**첨자**, **인덱스**)를 이용하여 액세스 함
  - 배열의 차원: 배열의 첨자 개수
- **1차원 배열**
  - 1차원 배열의 선언
    - `float fArray[4];` = `fArray[0]`, `fArray[1]`, `fArray[2]`, `fArray[3]`
  - 1차원 배열의 사용
    ```c++
    float fArray[4];
    int i = 0;
    cin >> fArray[1] >> fArray[2] >> fArray[3];
    cout << fArray[1] * fArray[2];
    ```
- **다차원 배열**
  - n차원 배열
    - n-1차원 배열이 원소인 배열
    - 2차원 배열: `int Arr2D[4][3]`
      - 행 우선 순서(row-major order)
  - 배열 초기화
    - `int a[5] = {1, 2, 3, 4, 5}; // '='는 생략할 수 있음`
    - `int b[5] - {1, 2, 3}; // b[3]와 b[4]는 0으로 초기화됨`
    - `int c[] = {1, 2, 3, 4, 5}; // 배열의 크기는 5`
    - `int d[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}}; // 2차원 배열의 초기화`
  - 배열의 활용
    ```c++
    // 여러 개의 데이터 중 최댓값 구하기
    int main(){
        int max;
        int data[10] = {10, 23, 5, 9, 22, 48, 12, 10, 55, 31};

        max = data[0]; // data의 0번 값을 max로 가정함
        cout << "데이터 : " << data[0]; // 0번 데이터 출력
        for(int i=1; i<10; i++){ // 나머지 9개의 데이터 비교
            cout << " " << data[i]; // i번 데이터 출력
            if(max < data[i]) max = data[i]; // i번 데이터 비교
        }
        cout << "\n\n배열의 최댓값 : " << max << endl;
        return 0;
    }
    ```

## 포인터와 동적 메모리 할당
- **포인터란?** 
  - 다른 변수, 구조체, 객체 등 값이 저장된 곳을 가리키는 변수
- **포인터 선언 형식**
  - `TypeName *ptrVar`;
  - `TypeName`: 가리킬 값의 자료형
  - `ptrVar`: 포인터 변수의 이름
  - ex) `int *iPtr`: iPtr이라는 변수는 정수형 값이 저장되어있는 곳을 가리키는 포인터이다
- **포인터의 사용**
    ```C++
    ptrVar = &var;
    *ptrVar = value;
    ```
  - & : 주소 계산 연산자
  - *ptrVar : 포인터 ptrVar가 가리키는 곳
  - ex)
    ```c++
    #include <iostream>
    using namespace std;
    int main(){
        int a = 10;
        int *ptr;
        
        ptr = &a;
        cout << "ptr이 가리키는 값: " << *ptr << endl; // 출력: 10
        *ptr = 20;
        cout << "변수 a의 값: " << a << endl; // 출력: 20
        return 0;
    }
    ```
- **동적 메모리 할당이란?**
  - 프로그램 동작 중에 기억공간의 필요성 및 소요량을 결정하여 필요한 공간을 할당하는 것
    - 기억 공간의 생성 시점: `new` 연산자의 실행 시점
    - 기억 공간의 소멸 시점: `delete` 연산자의 실행 시점
  - 포인터 변수가 할당된 기억 공간을 가리키게 함
- **동적 메모리 할당 연산자**
  1. `ptrVar = new TypeName;`
  2. `ptrVar = new TypeName[n]; // n: 정수형 수식`
- **동적 메모리 반납 연산자**
  1. `delete ptrVar;`
  2. `delete [] ptrVar;`
- **단일 데이터 공간의 할당 및 반환**
    ```c++
    int *intPtr;
    intPtr = new int; // 자유 메모리 공간 생성
    *intPtr = 10; // 생성된 메모리 공간에 값을 저장
    ......
    delete intPtr; // 저장된 값 반환 but 포인터는 아직 생성된 공간을 가리키고 있음
    intPtr = nullptr; // intPtr이 더이상 아무 곳도 가리키고 있지 않다라는 초기화
    ```
    ```c++
    int *intPtr;
    intPtr = new int[4]; // 4개의 공간을 가진 메모리 생성
    *intPtr = 10; // 첫번째 공간에 10의 값을 저장
    *(intPtr + 1) = 20; // 형식1. 두번째 공간에 20의 값을 저장
    intPtr[2] = 30; // 형식2. 세번째 공간에 30의 값을 저장
    .....
    delete [] intPtr; // 공간 반환
    intPtr = nullptr; // 포인터 초기화 (아무것도 가리키지 않음)
    ```
## 참조
- **참조(reference)란?**
  - 어떤한 대상을 가리키는 값(포인터와 유사함)
  - 참조 변수는 참조 대상의 별명처럼 사용할 수 있음
  - l-value 참조: 값을 저장할 수 있는 실체가 있는 대상(l-value)에 대한 참조 (<->r-value)
- **l-value 참조**
  - l-value 참조 변수의 선언 형식
    - `TypeName &refVar = varName;`
    - `TypeName`: 참조 대상의 자료형
    - `refVar`: 참조 변수의 이름
    - `varName`: 참조 대상
    - ex)
      ```c++
      int a = 10, b = 20;
      int &aRef = a;
      cout << aRef << endl; // a의 값인 10을 출력
      aRef = 100; // a = 100;
      aRef = b; // a = b;

      // vs.Pointer

      int a = 10, b = 20;
      int *aPtr = &a;
      cout << *aRef << endl; // a의 값인 10을 출력
      *aRef = 100; // a = 100;
      *aRef = b; // a = b;
      ```
  - const 참조
    - 참조를 이용하여 참조 대상의 값을 바꿀 수 없음
    ```c++
    int x {10};
    const int &xRef = x;
    cout << xRef << endl; // x의 값을 읽고 출력
    xRef += 10; // 오류: const참조로 값을 수정할 수 없음
    ```
  - 참조 변수가 포인터와 다른 점
    - 참조 변수를 이용하여 값을 읽거나 저장할 때 일반 변수를 사용하는 형식과 동일함
    - 참조 변수는 초기화를 통해 반드시 어떤 대상을 참조해야 함
      - 아무것도 참조하지 않는 상황은 발생하지 않음
    - 참조 변수는 초기화를 통해 지정된 참조 대상을 바꿀 수 없어 참조의 유효기간 동안 하나의 대상만 참조할 수 있음
- **r-value 참조**
  - r-value 참조란?
    - 사용한 후에는 그 값을 더 이상 가지고 있을 필요가 없는 대상을 참조
  - r-value 참조의 용도
    - 객체의 값을 다른 객체로 이동

---

[^TOP](#c-기초2)

---