#pragma once
#include "table.h"

class scantable : public table
{
	record **arrayRecord; //������ �������

	int findNumberRecord(const key &k); //����� ������ ������ � ������� �� �����
	void addSize(); //������������� ������, ���� ��������� 70% �������
public:
	scantable(int size = 1000); //�����������
	~scantable(); //����������

	void insRecord(const key &k, const datValue &data); //���������� ����� ������, ���� ����� ���
	void delRecord(const key &k); //�������� ������, ���� ����� �������
	datValue* findRecord(const key &k); //����� ������ �� �����

	key getKey(); //��������� ����� � ������� ������
	datValue getData(); //��������� ������ � ������� ������

	friend ostream & operator<<(ostream &out, const scantable &sc); //���������� ��������� ������
};