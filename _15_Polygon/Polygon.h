#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

// 2차원 좌표 구조체
struct Vertex {
	double x, y; // x축 좌표와 y축 좌표
};

class Polygon {
	int totalVertice; // 총 꼭짓점 수
	Vertex* vertex;	// 꼭짓점 좌표

public:
	Polygon(int tCount, Vertex* v);	// 생성자
	Polygon(const Polygon& p);	// 복사 생성자
	Polygon(Polygon&& p);	// 이동 생성자

	Polygon func(const Polygon& p)	const; // 객체 리턴 함수

	~Polygon();	// 소멸자
	double getArea();	// 면적 구하는 함수
	void print();	// 객체 정보 출력
};
#endif