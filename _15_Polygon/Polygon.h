#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

// 2���� ��ǥ ����ü
struct Vertex {
	double x, y; // x�� ��ǥ�� y�� ��ǥ
};

class Polygon {
	int totalVertice; // �� ������ ��
	Vertex* vertex;	// ������ ��ǥ

public:
	Polygon(int tCount, Vertex* v);	// ������
	Polygon(const Polygon& p);	// ���� ������
	Polygon(Polygon&& p);	// �̵� ������

	Polygon func(const Polygon& p)	const; // ��ü ���� �Լ�

	~Polygon();	// �Ҹ���
	double getArea();	// ���� ���ϴ� �Լ�
	void print();	// ��ü ���� ���
};
#endif