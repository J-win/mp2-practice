#pragma once

#include "Ringlist.h"

class monom
{
	double rank_number(const double a, const int i); //���������� ����� a � ������� i
	double converter_in_number(const string &s); //����������� ������ s � �����
	monom converter_in_monom(const string &s); //����������� ������ s � �����
public:
	double coeff; //����������� ������
	unsigned int xyz; //������� ������
	monom(const double c = 0.0, const unsigned int w = 0); //����������� �� ������
	monom(const monom &m); //����������� �����������
	monom(const string &s); //����������� �� ������
	~monom() {} //����������
	const monom& operator=(const monom &m); //�������� ������������
	bool operator==(const monom &m) const; //�������� ��������� �����
	bool operator!=(const monom &m) const; //�������� ��������� �� �����
	bool operator<(const monom &m) const; //�������� ��������� ������
	bool operator>(const monom &m) const; //�������� ��������� ������
	monom operator*(const double d) const; //��������� ������ �� �����
	monom operator*(const monom &m) const; //������������ ���� �������
	friend ostream & operator<<(ostream &out, const monom &m); //�������� ������
};