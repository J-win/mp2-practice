#pragma once
#include "table.h"
#include "list.h"

class hashtable : public table
{
	list<record> *arrayRecord; //������ ������� �������

	int findNumberRecord(const key &k); //����� ������ ������ � ������� �� �����
	int hashfunctable(const key &k); //��� �������
	void addSize() {}; //������������� ������, ���� ��������� 70% ������� (�� ���������)
public:
	hashtable(); //����������� �� ���������
	~hashtable(); //����������

	void insRecord(const key &k, const datValue &data); //���������� ����� ������, ���� ����� ���
	void delRecord(const key &k); //�������� ������, ���� ����� �������
	datValue* findRecord(const key &k); //����� ������ �� �����

	key getKey(); //��������� ����� � ������� ������
	datValue getData(); //��������� ������ � ������� ������

	friend ostream & operator<<(ostream &out, const hashtable &h); //���������� ��������� ������
};