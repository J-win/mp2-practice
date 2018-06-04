#pragma once
#include "polinom.h"

typedef string key;
typedef polinom datValue;

class record
{
public:
	key keyRecord; //���� ������
	datValue dataRecord; //������ ������

	record() {} //����������� �� ���������
	~record() {} //����������

	record(const key &k, const datValue &data); //����������� �� ����� � ������
	record(const record &rec); //����������� �����������

	record& operator=(const record &rec); //�������� ������������

	bool operator==(const record &rec); //�������� �� ���������
	bool operator!=(const record &rec); //�������� �� �����������
	bool operator>(const record &rec); //�������� �� ������
	bool operator<(const record &rec); //�������� �� ������

	friend ostream & operator<<(ostream &out, const record &r); //���������� ��������� ������
};