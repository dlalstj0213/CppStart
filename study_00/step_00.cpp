#include <iostream>

namespace myNSp1 { int n = 10; }
namespace myNSp2 { int n = 20; }
int n = 30;

int main() {
	// 표준 출력 스트림으로 문장을 출력함
	std::cout << "나의 첫 번째 C++프로그램" << std::endl;
	int a = 10;
	std::cout << "a의 값은";
	std::cout << a << "입니다." << std::endl;

	char str[100];
	std::cin >> a >> str;

	int n = 40;
	std::cout << myNSp1::n << std::endl; //결과 : 10
	std::cout << myNSp2::n << std::endl; //결과 : 20
	std::cout << ::n << std::endl; //결과 : 30
	std::cout << n << std::endl; //결과 : 40


	return 0;
}
// 소스파일 추가 : 솔루션 or 프로젝트 마우스 우클릭 -> 추가 -> 새 항목 -> .cpp 확장자 파일 만들기 [ Ctrl+Shift+A ]
// 빌드 : 네비게이션바 -> 빌드 클릭 -> 솔루션 빌드 [ F7 ]
// 특정 프로젝트 빌드 : 네비게이션바 -> 빌드 클릭 -> study_00 빌드 [ Ctrl+B ]
// 디버그 : 네비게이션바 -> 디버그 -> 디버깅 시작 / 디버그 하지않고 시작 [ F5 / Crtl+F5 ]

// 주석_1(comment) : '//' 
/*
주석_2
*/