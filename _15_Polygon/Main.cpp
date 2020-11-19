#include <iostream>
#include <typeinfo>
#include "Polygon.h"
using namespace std;

int main() {
    int totalCount;
    /*** 다각형의 꼭짓점 수 입력받기 ***/
    while (true) {
        cout << "[종료를 원하시면 0000을 입력해주세요]" << endl;
        cout << "다각형의 꼭짓점 갯수를 입력해주세요(최소 3개 이상): ";
        cin >> totalCount;
        if (cin.fail()) {
            cout << "잘못된 입력입니다. 숫자를 입력해 주세요." << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        else {
            if (totalCount == 0000) {
                cout << "프로그램을 종료합니다." << endl;
                exit(EXIT_FAILURE);
            }
            else if (totalCount < 3) {
                continue;
            }
            break;
        }
    }
    const int vSize = totalCount;

    /*** 꼭짓점 수 만큼 좌표 입력받기 ***/
    Vertex *v = new Vertex[totalCount];

    for (int i = 0; i < totalCount; i++) {
        cout << (i + 1) << "번째 x좌표 :";
        cin >> v[i].x;
        cout << (i + 1) << "번째 y좌표 :";
        cin >> v[i].y;
        cout << endl;
    }

    /*** 다각형 객체 생성 ***/
    Polygon p1(totalCount, v);
    p1.print(); // p1의 꼭짓점 좌표 출력
    cout << "p1의 면적 :" << p1.getArea() << endl; // p1의 면적 출력
    Polygon&& p2 = p1.func(p1); // p2를 r-value로 복사 및 이동 생성자 호출
    p2.print(); // p2의 꼭짓점 좌표 출력
    cout << "p2의 면적 :" << p2.getArea() << endl; // p2의 면적 출력

    return 0;
}