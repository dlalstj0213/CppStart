#include <iostream>
#include <cstring>
#include "Polygon.h"
using namespace std;

Polygon::Polygon(int tCount, Vertex* v) : totalVertice{ tCount }, vertex{ v } {	// 생성자
	cout << "생성자 호출 - 주소: " << this << endl;
}

Polygon::Polygon(const Polygon& p) : totalVertice{ p.totalVertice } {	// 복사 생성자
	vertex = new Vertex[totalVertice];
	memcpy(vertex, p.vertex, sizeof(Vertex) * totalVertice);
	cout << "복사 생성자 호출 - 주소: " << this << endl;
}

Polygon::Polygon(Polygon&& p) : totalVertice{ p.totalVertice }, vertex{ p.vertex }{
	p.vertex = nullptr;
	p.totalVertice = 0;
	cout << "이동 생성자 호출 - 주소: " << this << endl;
}

Polygon Polygon::func(const Polygon& p) const {
	Polygon tmp(p);
	return tmp;
}


Polygon::~Polygon() {	// 소멸자
	cout << "소멸자 호출 - 주소: " << this << endl;
	delete[] vertex;
}
double Polygon::getArea() {
	double sum = 0;
	for (int i = 0; i < totalVertice; ++i) {
		sum += vertex[i].x * vertex[(i + 1) % totalVertice].y;
	}
	for (int i = 0; i < totalVertice; ++i) {
		sum -= vertex[(i + 1) % totalVertice].x * vertex[i].y;
	}
	return abs(sum) / 2.0;
}

void Polygon::print() {
	cout << "꼭지점 좌표: ";
	for (int i = 0; i < totalVertice; i++) {
		if (i == 0)
			cout << "(";
		else
			cout << ", (";
		cout << vertex[i].x << ", " << vertex[i].y << ")";
	}
	cout << endl;
}