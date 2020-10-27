// 구조체 활용 예제: 원의 면적 구하기
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141593;

struct C2dType { // 2차원 좌표 구조체
	double x, y;
};

struct CircleType { // 원 구조체
	C2dType center;	// 중심 좌표
	double radius;	// 반경
};

double circleArea(CircleType c) {
	return c.radius * c.radius * PI;
}

bool chkOverlap(CircleType c1, CircleType c2) {
	double dx = c1.center.x - c2.center.x;
	double dy = c1.center.y - c2.center.y;
	double dCntr = sqrt(dx * dx + dy * dy);
	return dCntr < c1.radius + c2.radius;
}

void dispCircle(CircleType c) {
	cout << " 중심: (" << c.center.x << ", " << c.center.y << ")";
	cout << " 반경: " << c.radius << endl;
}
/*
int main(){
	CircleType c1 = { {0,0}, 10 }; // 중심(0,0), 반경 10으로 초기화
	CircleType c2 = { {30, 10}, 5 }; // 중심(30,10), 반경 5로 초기화
	cout << "원1" << endl;
	dispCircle(c1);
	cout << " 원1의 면적: " << circleArea(c1) << endl;
	cout << "원2" << endl;
	dispCircle(c2);
	cout << " 원2의 면적: " << circleArea(c2) << endl << endl;

	// 두 원의 중첩 여부 출력
	if (chkOverlap(c1, c2)) cout << "두 원은 중첩됩니다." << endl;
	else cout << "두 원은 중첩되지 않습니다." << endl;
	return 0;
}
*/



