#include <iostream>

namespace myNSp1 { int n = 10; }
namespace myNSp2 { int n = 20; }
int n = 30;

int main() {
	// ǥ�� ��� ��Ʈ������ ������ �����
	std::cout << "���� ù ��° C++���α׷�" << std::endl;
	int a = 10;
	std::cout << "a�� ����";
	std::cout << a << "�Դϴ�." << std::endl;

	char str[100];
	std::cin >> a >> str;

	int n = 40;
	std::cout << myNSp1::n << std::endl; //��� : 10
	std::cout << myNSp2::n << std::endl; //��� : 20
	std::cout << ::n << std::endl; //��� : 30
	std::cout << n << std::endl; //��� : 40


	return 0;
}
// �ҽ����� �߰� : �ַ�� or ������Ʈ ���콺 ��Ŭ�� -> �߰� -> �� �׸� -> .cpp Ȯ���� ���� ����� [ Ctrl+Shift+A ]
// ���� : �׺���̼ǹ� -> ���� Ŭ�� -> �ַ�� ���� [ F7 ]
// Ư�� ������Ʈ ���� : �׺���̼ǹ� -> ���� Ŭ�� -> study_00 ���� [ Ctrl+B ]
// ����� : �׺���̼ǹ� -> ����� -> ����� ���� / ����� �����ʰ� ���� [ F5 / Crtl+F5 ]

// �ּ�_1(comment) : '//' 
/*
�ּ�_2
*/