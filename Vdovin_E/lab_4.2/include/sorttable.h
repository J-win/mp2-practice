#pragma once
#include "table.h"

class sorttable : public table
{
	record **arrayRecord; //������ �������

	int findNumberRecord(const key &k); //����� ������ ������ � ������� �� �����
	void addSize(); //������������� ������, ���� ��������� 70% �������
public:
	sorttable(int size = 1000); //�����������
	~sorttable(); //����������

	void insRecord(const key &k, const datValue &data); //���������� ����� ������, ���� ����� ���
	void delRecord(const key &k); //�������� ������, ���� ����� �������
	datValue* findRecord(const key &k); //����� ������ �� �����

	key getKey(); //��������� ����� � ������� ������
	datValue getData(); //��������� ������ � ������� ������

	friend ostream & operator<<(ostream &out, const sorttable &sr); //���������� ��������� ������
};